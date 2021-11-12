//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSkeletonDataResource.h"

void SpineSkeletonDataResource::_register_methods() {
	godot::register_method("set_atlas_res", &SpineSkeletonDataResource::set_atlas_res);
	godot::register_method("get_atlas_res", &SpineSkeletonDataResource::get_atlas_res);
	godot::register_method("set_skeleton_json_res", &SpineSkeletonDataResource::set_skeleton_json_res);
	godot::register_method("get_skeleton_json_res", &SpineSkeletonDataResource::get_skeleton_json_res);
	godot::register_method("is_skeleton_data_loaded", &SpineSkeletonDataResource::is_skeleton_data_loaded);
	// godot::register_method("find_bone_index", "bone_name"), &SpineSkeletonDataResource::find_bone_index);
	// godot::register_method("find_slot_index", "slot_name"), &SpineSkeletonDataResource::find_slot_index);
	// godot::register_method("find_path_constraint_index", "path_constraint_name"), &SpineSkeletonDataResource::find_path_constraint_index);
	godot::register_method("find_animation", &SpineSkeletonDataResource::find_animation);
	godot::register_method("get_sk_name", &SpineSkeletonDataResource::get_sk_name);
	godot::register_method("set_sk_name", &SpineSkeletonDataResource::set_sk_name);
	godot::register_method("get_x", &SpineSkeletonDataResource::get_x);
	godot::register_method("set_x", &SpineSkeletonDataResource::set_x);
	godot::register_method("get_y", &SpineSkeletonDataResource::get_y);
	godot::register_method("set_y", &SpineSkeletonDataResource::set_y);
	godot::register_method("get_width", &SpineSkeletonDataResource::get_width);
	godot::register_method("get_height", &SpineSkeletonDataResource::get_height);
	godot::register_method("get_version", &SpineSkeletonDataResource::get_version);
	godot::register_method("get_fps", &SpineSkeletonDataResource::get_fps);
	godot::register_method("set_fps", &SpineSkeletonDataResource::set_fps);

	godot::register_method("find_bone", &SpineSkeletonDataResource::find_bone);
	godot::register_method("find_slot", &SpineSkeletonDataResource::find_slot);
	godot::register_method("find_skin", &SpineSkeletonDataResource::find_skin);
	godot::register_method("find_event", &SpineSkeletonDataResource::find_event);
	godot::register_method("find_ik_constraint_data", &SpineSkeletonDataResource::find_ik_constraint);
	godot::register_method("find_transform_constraint_data", &SpineSkeletonDataResource::find_transform_constraint);
	godot::register_method("find_path_constraint_data", &SpineSkeletonDataResource::find_path_constraint);
	godot::register_method("get_all_bone_data", &SpineSkeletonDataResource::get_bones);
	godot::register_method("get_all_slot_data", &SpineSkeletonDataResource::get_slots);
	godot::register_method("get_skins", &SpineSkeletonDataResource::get_skins);
	godot::register_method("get_default_skin", &SpineSkeletonDataResource::get_default_skin);
	godot::register_method("set_default_skin", &SpineSkeletonDataResource::set_default_skin);
	godot::register_method("get_all_event_data", &SpineSkeletonDataResource::get_events);
	godot::register_method("get_animations", &SpineSkeletonDataResource::get_animations);
	godot::register_method("get_all_ik_constraint_data", &SpineSkeletonDataResource::get_ik_constraints);
	godot::register_method("get_all_transform_constraint_data", &SpineSkeletonDataResource::get_transform_constraints);
	godot::register_method("get_all_path_constraint_data", &SpineSkeletonDataResource::get_path_constraints);

	godot::register_method("_get_property_list", &SpineSkeletonDataResource::_get_property_list);

	godot::register_signal<SpineSkeletonDataResource>("skeleton_data_loaded");
	godot::register_signal<SpineSkeletonDataResource>("atlas_res_changed");
	godot::register_signal<SpineSkeletonDataResource>("skeleton_json_res_changed");

	godot::register_property<SpineSkeletonDataResource, godot::Ref<SpineAtlasResource>>("atlas_res", &SpineSkeletonDataResource::set_atlas_res, &SpineSkeletonDataResource::get_atlas_res, nullptr, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_RESOURCE_TYPE, "SpineAtlasResource");
	godot::register_property<SpineSkeletonDataResource, godot::Ref<SpineSkeletonJsonDataResource>>("atlas_res", &SpineSkeletonDataResource::set_skeleton_json_res, &SpineSkeletonDataResource::get_skeleton_json_res, nullptr, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_RESOURCE_TYPE, "SpineSkeletonJsonDataResource");
}

SpineSkeletonDataResource::SpineSkeletonDataResource() {
}

SpineSkeletonDataResource::~SpineSkeletonDataResource() {
	if (skeleton_data && !spine_object) {
		delete skeleton_data;
		skeleton_data = NULL;
	}
}

void SpineSkeletonDataResource::_init() {
	valid = false;
	spine_object = false;
	skeleton_data = nullptr;
}

bool SpineSkeletonDataResource::is_skeleton_data_loaded() const {
	return valid || spine_object;
}

void SpineSkeletonDataResource::load_res(spine::Atlas *a, const godot::String &json_string) {
	if (json_string.empty())
		return;
	auto path = get_path();
	spine::SkeletonJson json(a);
	auto temp_skeleton_data = json.readSkeletonData(json_string.utf8().get_data());
	if (!temp_skeleton_data) {
		godot_print_error(godot::String("Error happened while loading skeleton json data: " + path).utf8().get_data(), __FUNCTION__, __FILE__, __LINE__);
		godot::String error_message = "Error msg: ";
		error_message += json.getError().buffer();
		godot_print_error(error_message.utf8().get_data(), __FUNCTION__, __FILE__, __LINE__);
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

void SpineSkeletonDataResource::set_atlas_res(godot::Ref<SpineAtlasResource> a) {
	atlas_res = a;
	valid = false;
	//	print_line("atlas_res_changed emitted");
	emit_signal("atlas_res_changed");
	update_skeleton_data();
}

godot::Ref<SpineAtlasResource> SpineSkeletonDataResource::get_atlas_res() {
	if (spine_object) {
		godot::Godot::print("Getting atlas res from a spine_object skeleton! The result may be NULL!");
	}
	return atlas_res;
}

void SpineSkeletonDataResource::set_skeleton_json_res(godot::Ref<SpineSkeletonJsonDataResource> s) {
	skeleton_json_res = s;
	valid = false;
	//	print_line("skeleton_json_res_changed emitted");
	emit_signal("skeleton_json_res_changed");
	update_skeleton_data();
}

godot::Ref<SpineSkeletonJsonDataResource> SpineSkeletonDataResource::get_skeleton_json_res() {
	if (spine_object) {
		godot::Godot::print("Getting atlas res from a spine_object skeleton! The result may be NULL!");
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
#define S_T(x) (spine::String(x.utf8().get_data()))
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

godot::Ref<SpineAnimation> SpineSkeletonDataResource::find_animation(const godot::String &animation_name) {
	CHECK_X(NULL);
	if (animation_name.empty()) {
		return NULL;
	}
	auto a = skeleton_data->findAnimation(S_T(animation_name));
	if (!a)
		return NULL;
	godot::Ref<SpineAnimation> sa;
	sa.instance();
	sa->set_spine_object(a);
	return sa;
}

godot::String SpineSkeletonDataResource::get_sk_name() {
	CHECK_X("error");
	return skeleton_data->getName().buffer();
}

void SpineSkeletonDataResource::set_sk_name(const godot::String &v) {
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

godot::String SpineSkeletonDataResource::get_version() {
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

godot::Ref<SpineBoneData> SpineSkeletonDataResource::find_bone(const godot::String &bone_name) {
	if (bone_name.empty())
		return NULL;
	auto b = skeleton_data->findBone(S_T(bone_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpineBoneData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Ref<SpineSlotData> SpineSkeletonDataResource::find_slot(const godot::String &slot_name) {
	if (slot_name.empty())
		return NULL;
	auto b = skeleton_data->findSlot(S_T(slot_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpineSlotData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Ref<SpineSkin> SpineSkeletonDataResource::find_skin(const godot::String &skin_name) {
	if (skin_name.empty())
		return NULL;
	auto b = skeleton_data->findSkin(S_T(skin_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpineSkin> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Ref<SpineEventData> SpineSkeletonDataResource::find_event(const godot::String &event_data_name) {
	if (event_data_name.empty())
		return NULL;
	auto b = skeleton_data->findEvent(S_T(event_data_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpineEventData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Ref<SpineIkConstraintData> SpineSkeletonDataResource::find_ik_constraint(const godot::String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto b = skeleton_data->findIkConstraint(S_T(constraint_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpineIkConstraintData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Ref<SpineTransformConstraintData> SpineSkeletonDataResource::find_transform_constraint(const godot::String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto b = skeleton_data->findTransformConstraint(S_T(constraint_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpineTransformConstraintData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Ref<SpinePathConstraintData> SpineSkeletonDataResource::find_path_constraint(const godot::String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto b = skeleton_data->findPathConstraint(S_T(constraint_name));
	if (b == NULL)
		return NULL;
	godot::Ref<SpinePathConstraintData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

godot::Array SpineSkeletonDataResource::get_bones() {
	auto bs = skeleton_data->getBones();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineBoneData>(NULL);
		else {
			godot::Ref<SpineBoneData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkeletonDataResource::get_slots() {
	auto bs = skeleton_data->getSlots();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineSlotData>(NULL);
		else {
			godot::Ref<SpineSlotData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkeletonDataResource::get_skins() const {
	auto bs = skeleton_data->getSkins();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineSkin>(NULL);
		else {
			godot::Ref<SpineSkin> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Ref<SpineSkin> SpineSkeletonDataResource::get_default_skin() {
	auto b = skeleton_data->getDefaultSkin();
	if (b == NULL)
		return NULL;
	godot::Ref<SpineSkin> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

void SpineSkeletonDataResource::set_default_skin(godot::Ref<SpineSkin> v) {
	if (v.is_valid()) {
		skeleton_data->setDefaultSkin(v->get_spine_object());
	} else
		skeleton_data->setDefaultSkin(NULL);
}

godot::Array SpineSkeletonDataResource::get_events() {
	auto bs = skeleton_data->getEvents();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineEventData>(NULL);
		else {
			godot::Ref<SpineEventData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkeletonDataResource::get_animations() {
	auto bs = skeleton_data->getAnimations();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineAnimation>(NULL);
		else {
			godot::Ref<SpineAnimation> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkeletonDataResource::get_ik_constraints() {
	auto bs = skeleton_data->getIkConstraints();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineIkConstraintData>(NULL);
		else {
			godot::Ref<SpineIkConstraintData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkeletonDataResource::get_transform_constraints() {
	auto bs = skeleton_data->getTransformConstraints();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineTransformConstraintData>(NULL);
		else {
			godot::Ref<SpineTransformConstraintData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkeletonDataResource::get_path_constraints() {
	auto bs = skeleton_data->getPathConstraints();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpinePathConstraintData>(NULL);
		else {
			godot::Ref<SpinePathConstraintData> gd_b;
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
void SpineSkeletonDataResource::get_animation_names(godot::PoolStringArray &res) const {
	res.resize(0);
	if (!is_skeleton_data_loaded()) {
		return;
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
}
void SpineSkeletonDataResource::get_skin_names(godot::PoolStringArray &res) const {
	res.resize(0);
	if (!is_skeleton_data_loaded()) {
		return;
	}
	auto as = get_skins();
	res.resize(as.size());
	for (size_t i = 0; i < as.size(); ++i) {
		auto a = godot::Ref<SpineSkin>(as[i]);
		if (a.is_valid()) {
			res.push_back(a->get_skin_name());
		} else {
			res.push_back("");
		}
	}
}

godot::Array SpineSkeletonDataResource::_get_property_list() const {
	godot::Array list;

	godot::Dictionary p;
	godot::PoolStringArray res;

	p["name"] = "animations";
	p["type"] = godot::Variant::STRING;
	get_animation_names(res);
	godot::String hint_string;
	for (int i = 0; i < res.size(); ++i) {
		hint_string += res[i];
		if (i != res.size() - 1) {
			hint_string += ",";
		}
	}
	p["hint_string"] = hint_string;
	p["hint"] = GODOT_PROPERTY_HINT_ENUM;
	list.push_back(p);

	p["name"] = "skins";
	p["type"] = godot::Variant::STRING;
	get_skin_names(res);
	hint_string = "";
	for (int i = 0; i < res.size(); ++i) {
		hint_string += res[i];
		if (i != res.size() - 1) {
			hint_string += ",";
		}
	}
	p["hint_string"] = hint_string;
	p["hint"] = GODOT_PROPERTY_HINT_ENUM;
	list.push_back(p);

	return list;
}
