//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSkeletonDataResource.h"

namespace godot {

void SpineSkeletonDataResource::_register_methods() {
	register_method("set_atlas_res", &SpineSkeletonDataResource::set_atlas_res);
	register_method("get_atlas_res", &SpineSkeletonDataResource::get_atlas_res);
	register_method("set_skeleton_json_res", &SpineSkeletonDataResource::set_skeleton_json_res);
	register_method("get_skeleton_json_res", &SpineSkeletonDataResource::get_skeleton_json_res);
	register_method("is_skeleton_data_loaded", &SpineSkeletonDataResource::is_skeleton_data_loaded);
	// register_method("find_bone_index", &SpineSkeletonDataResource::find_bone_index);
	// register_method("find_slot_index", &SpineSkeletonDataResource::find_slot_index);
	// register_method("find_path_constraint_index", &SpineSkeletonDataResource::find_path_constraint_index);
	register_method("find_animation", &SpineSkeletonDataResource::find_animation);
	register_method("get_sk_name", &SpineSkeletonDataResource::get_sk_name);
	register_method("set_sk_name", &SpineSkeletonDataResource::set_sk_name);
	register_method("get_x", &SpineSkeletonDataResource::get_x);
	register_method("set_x", &SpineSkeletonDataResource::set_x);
	register_method("get_y", &SpineSkeletonDataResource::get_y);
	register_method("set_y", &SpineSkeletonDataResource::set_y);
	register_method("get_width", &SpineSkeletonDataResource::get_width);
	register_method("get_height", &SpineSkeletonDataResource::get_height);
	register_method("get_version", &SpineSkeletonDataResource::get_version);
	register_method("get_fps", &SpineSkeletonDataResource::get_fps);
	register_method("set_fps", &SpineSkeletonDataResource::set_fps);

	register_method("find_bone", &SpineSkeletonDataResource::find_bone);
	register_method("find_slot", &SpineSkeletonDataResource::find_slot);
	register_method("find_skin", &SpineSkeletonDataResource::find_skin);
	register_method("find_event", &SpineSkeletonDataResource::find_event);
	register_method("find_ik_constraint_data", &SpineSkeletonDataResource::find_ik_constraint);
	register_method("find_transform_constraint_data", &SpineSkeletonDataResource::find_transform_constraint);
	register_method("find_path_constraint_data", &SpineSkeletonDataResource::find_path_constraint);
	register_method("get_all_bone_data", &SpineSkeletonDataResource::get_bones);
	register_method("get_all_slot_data", &SpineSkeletonDataResource::get_slots);
	register_method("get_skins", &SpineSkeletonDataResource::get_skins);
	register_method("get_default_skin", &SpineSkeletonDataResource::get_default_skin);
	register_method("set_default_skin", &SpineSkeletonDataResource::set_default_skin);
	register_method("get_all_event_data", &SpineSkeletonDataResource::get_events);
	register_method("get_animations", &SpineSkeletonDataResource::get_animations);
	register_method("get_all_ik_constraint_data", &SpineSkeletonDataResource::get_ik_constraints);
	register_method("get_all_transform_constraint_data", &SpineSkeletonDataResource::get_transform_constraints);
	register_method("get_all_path_constraint_data", &SpineSkeletonDataResource::get_path_constraints);

	register_signal<SpineSkeletonDataResource>("skeleton_data_loaded", Dictionary());
	register_signal<SpineSkeletonDataResource>("atlas_res_changed", Dictionary());
	register_signal<SpineSkeletonDataResource>("skeleton_json_res_changed", Dictionary());

	register_property<SpineSkeletonDataResource, Ref<SpineAtlasResource>>("atlas_res", &SpineSkeletonDataResource::set_atlas_res, &SpineSkeletonDataResource::get_atlas_res, nullptr, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_RESOURCE_TYPE, "Resource");
	register_property<SpineSkeletonDataResource, Ref<SpineSkeletonJsonDataResource>>("skeleton_json_res", &SpineSkeletonDataResource::set_skeleton_json_res, &SpineSkeletonDataResource::get_skeleton_json_res, nullptr, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_RESOURCE_TYPE, "Resource");
}

SpineSkeletonDataResource::SpineSkeletonDataResource() {
}

void SpineSkeletonDataResource::_init() {
	valid = false;
	spine_object = false;
	skeleton_data = nullptr;
}

SpineSkeletonDataResource::~SpineSkeletonDataResource() {
	if (skeleton_data && !spine_object) {
		delete skeleton_data;
		skeleton_data = NULL;
	}
}

bool SpineSkeletonDataResource::is_skeleton_data_loaded() const {
	return valid || spine_object;
}

void SpineSkeletonDataResource::load_res(spine::Atlas *a, const String &json_string) {
	if (json_string.empty())
		return;
	auto path = get_path();
	spine::SkeletonJson json(a);
	auto temp_skeleton_data = json.readSkeletonData(json_string.alloc_c_string());
	if (!temp_skeleton_data) {
		ERR_PRINT(String("Error happened while loading skeleton json data: ") + path);
		ERR_PRINT(String("Error msg: ") + json.getError().buffer());
		return;
	}
	if (skeleton_data) {
		delete skeleton_data;
		skeleton_data = NULL;
	}
	skeleton_data = temp_skeleton_data;

	valid = true;
	//	print_line("Skeleton json data loaded!");
}

void SpineSkeletonDataResource::update_skeleton_data() {
	if (atlas_res.is_valid() && skeleton_json_res.is_valid()) {
		load_res(atlas_res->get_spine_atlas(), skeleton_json_res->get_json_string());
		if (valid) {
			emit_signal("skeleton_data_loaded");
		}
	}
}

void SpineSkeletonDataResource::set_atlas_res(Ref<SpineAtlasResource> a) {
	atlas_res = a;
	valid = false;
	//	print_line("atlas_res_changed emitted");
	emit_signal("atlas_res_changed");
	update_skeleton_data();
}

Ref<SpineAtlasResource> SpineSkeletonDataResource::get_atlas_res() {
	if (spine_object) {
		Godot::print("Getting atlas res from a spine_object skeleton! The result may be NULL!");
	}
	return atlas_res;
}

void SpineSkeletonDataResource::set_skeleton_json_res(Ref<SpineSkeletonJsonDataResource> s) {
	skeleton_json_res = s;
	valid = false;
	//	print_line("skeleton_json_res_changed emitted");
	emit_signal("skeleton_json_res_changed");
	update_skeleton_data();
}

Ref<SpineSkeletonJsonDataResource> SpineSkeletonDataResource::get_skeleton_json_res() {
	if (spine_object) {
		Godot::print("Getting atlas res from a spine_object skeleton! The result may be NULL!");
	}
	return skeleton_json_res;
}

#define CHECK_V                                         \
	if (!is_skeleton_data_loaded()) {                   \
		ERR_PRINT("skeleton data has not loaded yet!"); \
		return;                                         \
	}
#define CHECK_X(x)                                      \
	if (!is_skeleton_data_loaded()) {                   \
		ERR_PRINT("skeleton data has not loaded yet!"); \
		return x;                                       \
	}
#define S_T(x) (spine::String(x.alloc_c_string()))
// int SpineSkeletonDataResource::find_bone_index(const String &bone_name) {
// 	CHECK_X(-1);
// 	if(bone_name.empty()) return -1;
// 	return skeleton_data->findBoneIndex(S_T(bone_name));
// }
// int SpineSkeletonDataResource::find_slot_index(const String &slot_name) {
// 	if(slot_name.empty()) return -1;
// 	CHECK_X(-1);
// 	return skeleton_data->findSlotIndex(S_T(slot_name));
// }
// int SpineSkeletonDataResource::find_path_constraint_index(const String &path_constraint_name) {
// 	if(path_constraint_name.empty()) return -1;
// 	CHECK_X(-1);
// 	return skeleton_data->findPathConstraintIndex(S_T(path_constraint_name));
// }

Ref<SpineAnimation> SpineSkeletonDataResource::find_animation(const String &animation_name) {
	CHECK_X(NULL);
	if (animation_name.empty()) {
		return NULL;
	}
	const char *alloced = animation_name.alloc_c_string();
	auto a = skeleton_data->findAnimation(S_T(animation_name));
	if (!a)
		return NULL;
	Ref<SpineAnimation> sa;
	sa.instance();
	sa->set_spine_object(a);
	return sa;
}

String SpineSkeletonDataResource::get_sk_name() {
	CHECK_X("error");
	return skeleton_data->getName().buffer();
}
void SpineSkeletonDataResource::set_sk_name(const String &v) {
	CHECK_V;
	skeleton_data->setName(S_T(v));
}

float SpineSkeletonDataResource::get_x() {
	CHECK_X(0);
	return skeleton_data->getX();
}

void SpineSkeletonDataResource::set_x(float v) {
	CHECK_V;
	skeleton_data->setX(v);
}

float SpineSkeletonDataResource::get_y() {
	CHECK_X(0);
	return skeleton_data->getY();
}

void SpineSkeletonDataResource::set_y(float v) {
	CHECK_V;
	skeleton_data->setY(v);
}

float SpineSkeletonDataResource::get_width() {
	CHECK_X(0);
	return skeleton_data->getWidth();
}

float SpineSkeletonDataResource::get_height() {
	CHECK_X(0);
	return skeleton_data->getHeight();
}

String SpineSkeletonDataResource::get_version() {
	CHECK_X("error");
	return skeleton_data->getVersion().buffer();
}

float SpineSkeletonDataResource::get_fps() {
	CHECK_X(0);
	return skeleton_data->getFps();
}

void SpineSkeletonDataResource::set_fps(float v) {
	CHECK_V;
	skeleton_data->setFps(v);
}

Ref<SpineBoneData> SpineSkeletonDataResource::find_bone(const String &bone_name) {
	if (bone_name.empty())
		return NULL;
	auto b = skeleton_data->findBone(S_T(bone_name));
	if (b == NULL)
		return NULL;
	Ref<SpineBoneData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Ref<SpineSlotData> SpineSkeletonDataResource::find_slot(const String &slot_name) {
	if (slot_name.empty())
		return NULL;
	auto b = skeleton_data->findSlot(S_T(slot_name));
	if (b == NULL)
		return NULL;
	Ref<SpineSlotData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Ref<SpineSkin> SpineSkeletonDataResource::find_skin(const String &skin_name) {
	if (skin_name.empty())
		return NULL;
	auto b = skeleton_data->findSkin(S_T(skin_name));
	if (b == NULL)
		return NULL;
	Ref<SpineSkin> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Ref<SpineEventData> SpineSkeletonDataResource::find_event(const String &event_data_name) {
	if (event_data_name.empty())
		return NULL;
	auto b = skeleton_data->findEvent(S_T(event_data_name));
	if (b == NULL)
		return NULL;
	Ref<SpineEventData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Ref<SpineIkConstraintData> SpineSkeletonDataResource::find_ik_constraint(const String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto b = skeleton_data->findIkConstraint(S_T(constraint_name));
	if (b == NULL)
		return NULL;
	Ref<SpineIkConstraintData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Ref<SpineTransformConstraintData> SpineSkeletonDataResource::find_transform_constraint(const String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto b = skeleton_data->findTransformConstraint(S_T(constraint_name));
	if (b == NULL)
		return NULL;
	Ref<SpineTransformConstraintData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Ref<SpinePathConstraintData> SpineSkeletonDataResource::find_path_constraint(const String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto b = skeleton_data->findPathConstraint(S_T(constraint_name));
	if (b == NULL)
		return NULL;
	Ref<SpinePathConstraintData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

Array SpineSkeletonDataResource::get_bones() {
	auto bs = skeleton_data->getBones();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineBoneData>(NULL);
		else {
			Ref<SpineBoneData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

Array SpineSkeletonDataResource::get_slots() {
	auto bs = skeleton_data->getSlots();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineSlotData>(NULL);
		else {
			Ref<SpineSlotData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

Array SpineSkeletonDataResource::get_skins() const {
	auto bs = skeleton_data->getSkins();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineSkin>(NULL);
		else {
			Ref<SpineSkin> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

Ref<SpineSkin> SpineSkeletonDataResource::get_default_skin() {
	auto b = skeleton_data->getDefaultSkin();
	if (b == NULL)
		return NULL;
	Ref<SpineSkin> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

void SpineSkeletonDataResource::set_default_skin(Ref<SpineSkin> v) {
	if (v.is_valid()) {
		skeleton_data->setDefaultSkin(v->get_spine_object());
	} else
		skeleton_data->setDefaultSkin(NULL);
}

Array SpineSkeletonDataResource::get_events() {
	auto bs = skeleton_data->getEvents();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineEventData>(NULL);
		else {
			Ref<SpineEventData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

Array SpineSkeletonDataResource::get_animations() {
	auto bs = skeleton_data->getAnimations();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineAnimation>(NULL);
		else {
			Ref<SpineAnimation> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

Array SpineSkeletonDataResource::get_ik_constraints() {
	auto bs = skeleton_data->getIkConstraints();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineIkConstraintData>(NULL);
		else {
			Ref<SpineIkConstraintData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}
Array SpineSkeletonDataResource::get_transform_constraints() {
	auto bs = skeleton_data->getTransformConstraints();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpineTransformConstraintData>(NULL);
		else {
			Ref<SpineTransformConstraintData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}
Array SpineSkeletonDataResource::get_path_constraints() {
	auto bs = skeleton_data->getPathConstraints();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = Ref<SpinePathConstraintData>(NULL);
		else {
			Ref<SpinePathConstraintData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}
#undef S_T
#undef CHECK_V
#undef CHECK_X

//External feature functions
Array SpineSkeletonDataResource::get_animation_names() {
	Array res;
	if (!is_skeleton_data_loaded()) {
		return res;
	}
	auto as = skeleton_data->getAnimations();
	for (size_t i = 0; i < as.size(); ++i) {
		auto a = as[i];
		if (a) {
			res.push_back(a->getName().buffer());
		} else {
			res.push_back("");
		}
	}
	return res;
}

Array SpineSkeletonDataResource::get_skin_names() {
	Array res;
	if (!is_skeleton_data_loaded()) {
		return res;
	}
	auto as = get_skins();
	res.resize(as.size());
	for (size_t i = 0; i < as.size(); ++i) {
		auto a = Ref<SpineSkin>(as[i]);
		if (a.is_valid()) {
			res.push_back(a->get_skin_name());
		} else {
			res.push_back("");
		}
	}
	return res;
}

Array SpineSkeletonDataResource::_get_property_list() {
	Array list;

	PoolStringArray res = get_animation_names();
	String hint_string;
	for (int i = 0; i < res.size(); ++i) {
		hint_string += res[i];
		if (i < res.size() - 1) {
			hint_string += ",";
		}
	}

	list.push_back(Dictionary::make("name", "animations", "type", Variant::STRING, "hint_string", hint_string, "hint", GODOT_PROPERTY_HINT_ENUM));

	res = get_skin_names();
	hint_string = "";
	for (int i = 0; i < res.size(); ++i) {
		hint_string += res[i];
		if (i < res.size() - 1) {
			hint_string += ",";
		}
	}

	list.push_back(Dictionary::make("name", "skins", "type", Variant::STRING, "hint_string", hint_string, "hint", GODOT_PROPERTY_HINT_ENUM));

	return list;
}

} //namespace godot