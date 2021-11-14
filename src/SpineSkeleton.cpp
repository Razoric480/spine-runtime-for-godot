//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineSkeleton.h"

namespace godot {

void SpineSkeleton::_register_methods() {
	//void update_world_transform();
	//
	//	void set_to_setup_pose();
	//
	//	void set_bones_to_setup_pose();
	//
	//	void set_slots_to_setup_pose();
	register_method("update_world_transform", &SpineSkeleton::update_world_transform);
	register_method("set_to_setup_pose", &SpineSkeleton::set_to_setup_pose);
	register_method("set_bones_to_setup_pose", &SpineSkeleton::set_bones_to_setup_pose);
	register_method("set_slots_to_setup_pose", &SpineSkeleton::set_slots_to_setup_pose);
	//
	//	Ref<SpineBone> find_bone(const String &name);
	//	int find_bone_index(const String &name);
	//
	//	Ref<SpineSlot> find_slot(const String &name);
	//	int find_slot_index(const String &name);
	//
	//	void set_skin_by_name(const String &skin_name);
	//	void set_skin(Ref<SpineSkin> new_skin);
	//
	//	Ref<SpineAttachment> get_attachment_by_slot_name(const String &slot_name, const String &attachment_name);
	//	Ref<SpineAttachment> get_attachment_by_slot_index(int slot_index, const String &attachment_name);
	register_method("find_bone", &SpineSkeleton::find_bone);
	// register_method("find_bone_index", &SpineSkeleton::find_bone_index);
	register_method("find_slot", &SpineSkeleton::find_slot);
	// register_method("find_slot_index", &SpineSkeleton::find_slot_index);
	register_method("set_skin_by_name", &SpineSkeleton::set_skin_by_name);
	register_method("set_skin", &SpineSkeleton::set_skin);
	register_method("get_attachment_by_slot_name", &SpineSkeleton::get_attachment_by_slot_name);
	register_method("get_attachment_by_slot_index", &SpineSkeleton::get_attachment_by_slot_index);
	//
	//	void set_attachment(const String &slot_name, const String &attachment_name);
	//
	//	Ref<SpineIkConstraint> find_ik_constraint(const String &constraint_name);
	//	Ref<SpineTransformConstraint> find_transform_constraint(const String &constraint_name);
	//	Ref<SpinePathConstraint> find_path_constraint(const String &constraint_name);
	//
	//	void update(float delta);
	//
	//	Dictionary get_bounds();
	//
	//	Ref<SpineBone> get_root_bone();
	//
	//	Ref<SpineSkeletonDataResource> get_data();
	register_method("set_attachment", &SpineSkeleton::set_attachment);
	register_method("find_ik_constraint", &SpineSkeleton::find_ik_constraint);
	register_method("find_transform_constraint", &SpineSkeleton::find_transform_constraint);
	register_method("find_path_constraint", &SpineSkeleton::find_path_constraint);
	register_method("update", &SpineSkeleton::update);
	register_method("get_bounds", &SpineSkeleton::get_bounds);
	register_method("get_root_bone", &SpineSkeleton::get_root_bone);
	register_method("get_data", &SpineSkeleton::get_data);
	//
	//	Array get_bones();
	//	Array get_slots();
	//	Array get_draw_orders();
	//	Array get_ik_constraints();
	//	Array get_path_constraints();
	//	Array get_transform_constraints();
	//
	//	Ref<SpineSkin> get_skin();
	register_method("get_bones", &SpineSkeleton::get_bones);
	register_method("get_slots", &SpineSkeleton::get_slots);
	register_method("get_draw_orders", &SpineSkeleton::get_draw_orders);
	register_method("get_ik_constraints", &SpineSkeleton::get_ik_constraints);
	register_method("get_path_constraints", &SpineSkeleton::get_path_constraints);
	register_method("get_transform_constraints", &SpineSkeleton::get_transform_constraints);
	register_method("get_skin", &SpineSkeleton::get_skin);
	//
	//	Color get_color();
	//	void set_color(Color v);
	//
	//	float get_time();
	//	void set_time(float v);
	//
	//	void set_position(Vector2 pos);
	register_method("get_color", &SpineSkeleton::get_color);
	register_method("set_color", &SpineSkeleton::set_color);
	register_method("get_time", &SpineSkeleton::get_time);
	register_method("set_time", &SpineSkeleton::set_time);
	register_method("set_position", &SpineSkeleton::set_position);
	//
	//	float get_x();
	//	void set_x(float v);
	//
	//	float get_y();
	//	void set_y(float v);
	//
	//	float get_scale_x();
	//	void set_scale_x(float v);
	//
	//	float get_scale_y();
	//	void set_scale_y(float v);
	register_method("get_x", &SpineSkeleton::get_x);
	register_method("set_x", &SpineSkeleton::set_x);
	register_method("get_y", &SpineSkeleton::get_y);
	register_method("set_y", &SpineSkeleton::set_y);
	register_method("get_scale_x", &SpineSkeleton::get_scale_x);
	register_method("set_scale_x", &SpineSkeleton::set_scale_x);
	register_method("get_scale_y", &SpineSkeleton::get_scale_y);
	register_method("set_scale_y", &SpineSkeleton::set_scale_y);
}

SpineSkeleton::SpineSkeleton() {
}

SpineSkeleton::~SpineSkeleton() {
	if (skeleton && !spine_object) {
		delete skeleton;
		skeleton = NULL;
	}
}

void SpineSkeleton::_init() {
	skeleton = nullptr;
	spine_object = false;
	the_sprite = nullptr;
}

void SpineSkeleton::load_skeleton(Ref<SpineSkeletonDataResource> sd) {
	if (skeleton && !spine_object) {
		delete skeleton;
		skeleton = NULL;
	}
	skeleton = new spine::Skeleton(sd->get_skeleton_data());
	spine_object = false;
}

#define S_T(x) (spine::String(x.alloc_c_string()))
void SpineSkeleton::update_world_transform() {
	skeleton->updateWorldTransform();
}

void SpineSkeleton::set_to_setup_pose() {
	skeleton->setToSetupPose();
}

void SpineSkeleton::set_bones_to_setup_pose() {
	skeleton->setBonesToSetupPose();
}

void SpineSkeleton::set_slots_to_setup_pose() {
	skeleton->setSlotsToSetupPose();
}

Ref<SpineBone> SpineSkeleton::find_bone(const String &name) {
	if (name.empty())
		return NULL;
	auto b = skeleton->findBone(S_T(name));
	if (b == NULL)
		return NULL;
	Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	gd_b->set_spine_sprite(the_sprite);
	return gd_b;
}
// int SpineSkeleton::find_bone_index(const String &name){
// 	if(name.empty()) return -1;
// 	return skeleton->findBoneIndex(S_T(name));
// }

Ref<SpineSlot> SpineSkeleton::find_slot(const String &name) {
	if (name.empty())
		return NULL;
	auto s = skeleton->findSlot(S_T(name));
	if (s == NULL)
		return NULL;
	Ref<SpineSlot> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(s);
	return gd_s;
}
// int SpineSkeleton::find_slot_index(const String &name){
// 	if(name.empty()) return -1;
// 	return skeleton->findSlotIndex(S_T(name));
// }

void SpineSkeleton::set_skin_by_name(const String &skin_name) {
	skeleton->setSkin(S_T(skin_name));
}

void SpineSkeleton::set_skin(Ref<SpineSkin> new_skin) {
	if (new_skin.is_valid()) {
		skeleton->setSkin(new_skin->get_spine_object());
	} else {
		skeleton->setSkin(NULL);
	}
}

Ref<SpineAttachment> SpineSkeleton::get_attachment_by_slot_name(const String &slot_name, const String &attachment_name) {
	auto a = skeleton->getAttachment(S_T(slot_name), S_T(attachment_name));
	if (a == NULL)
		return NULL;
	Ref<SpineAttachment> gd_a;
	gd_a.instance();
	gd_a->set_spine_object(a);
	return gd_a;
}

Ref<SpineAttachment> SpineSkeleton::get_attachment_by_slot_index(int slot_index, const String &attachment_name) {
	auto a = skeleton->getAttachment(slot_index, S_T(attachment_name));
	if (a == NULL)
		return NULL;
	Ref<SpineAttachment> gd_a;
	gd_a.instance();
	gd_a->set_spine_object(a);
	return gd_a;
}

void SpineSkeleton::set_attachment(const String &slot_name, const String &attachment_name) {
	ERR_FAIL_COND(slot_name.empty());
	ERR_FAIL_COND(get_attachment_by_slot_name(slot_name, attachment_name) == NULL);
	skeleton->setAttachment(S_T(slot_name), S_T(attachment_name));
}

Ref<SpineIkConstraint> SpineSkeleton::find_ik_constraint(const String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto c = skeleton->findIkConstraint(S_T(constraint_name));
	if (c == NULL)
		return NULL;
	Ref<SpineIkConstraint> gd_c;
	gd_c.instance();
	gd_c->set_spine_object(c);
	return gd_c;
}

Ref<SpineTransformConstraint> SpineSkeleton::find_transform_constraint(const String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto c = skeleton->findTransformConstraint(S_T(constraint_name));
	if (c == NULL)
		return NULL;
	Ref<SpineTransformConstraint> gd_c;
	gd_c.instance();
	gd_c->set_spine_object(c);
	return gd_c;
}

Ref<SpinePathConstraint> SpineSkeleton::find_path_constraint(const String &constraint_name) {
	if (constraint_name.empty())
		return NULL;
	auto c = skeleton->findPathConstraint(S_T(constraint_name));
	if (c == NULL)
		return NULL;
	Ref<SpinePathConstraint> gd_c;
	gd_c.instance();
	gd_c->set_spine_object(c);
	return gd_c;
}

void SpineSkeleton::update(float delta) {
	skeleton->update(delta);
}

Dictionary SpineSkeleton::get_bounds() {
	float x, y, w, h;
	spine::Vector<float> vertex_buffer;
	skeleton->getBounds(x, y, w, h, vertex_buffer);

	Dictionary res;
	res["x"] = x;
	res["y"] = y;
	res["w"] = w;
	res["h"] = h;

	Array gd_a;
	gd_a.resize(vertex_buffer.size());
	for (size_t i = 0; i < gd_a.size(); ++i) {
		gd_a[i] = vertex_buffer[i];
	}
	res["vertex_buffer"] = gd_a;

	return res;
}

Ref<SpineBone> SpineSkeleton::get_root_bone() {
	auto b = skeleton->getRootBone();
	if (b == NULL)
		return NULL;
	Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	gd_b->set_spine_sprite(the_sprite);
	return gd_b;
}

Ref<SpineSkeletonDataResource> SpineSkeleton::get_data() const {
	auto sd = skeleton->getData();
	if (sd == NULL)
		return NULL;
	Ref<SpineSkeletonDataResource> gd_sd;
	gd_sd.instance();
	gd_sd->set_spine_object(sd);
	return gd_sd;
}

Array SpineSkeleton::get_bones() {
	auto &as = skeleton->getBones();
	Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < gd_as.size(); ++i) {
		auto b = as[i];
		if (b == NULL)
			gd_as[i] = Ref<SpineBone>(NULL);
		Ref<SpineBone> gd_a;
		gd_a.instance();
		gd_a->set_spine_object(b);
		gd_a->set_spine_sprite(the_sprite);
		gd_as[i] = gd_a;
	}
	return gd_as;
}

Array SpineSkeleton::get_slots() {
	auto &as = skeleton->getSlots();
	Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < gd_as.size(); ++i) {
		auto b = as[i];
		if (b == NULL)
			gd_as[i] = Ref<SpineSlot>(NULL);
		Ref<SpineSlot> gd_a;
		gd_a.instance();
		gd_a->set_spine_object(b);
		gd_as[i] = gd_a;
	}
	return gd_as;
}

Array SpineSkeleton::get_draw_orders() {
	auto &as = skeleton->getDrawOrder();
	Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < gd_as.size(); ++i) {
		auto b = as[i];
		if (b == NULL)
			gd_as[i] = Ref<SpineSlot>(NULL);
		Ref<SpineSlot> gd_a;
		gd_a.instance();
		gd_a->set_spine_object(b);
		gd_as[i] = gd_a;
	}
	return gd_as;
}

Array SpineSkeleton::get_ik_constraints() {
	auto &as = skeleton->getIkConstraints();
	Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < gd_as.size(); ++i) {
		auto b = as[i];
		if (b == NULL)
			gd_as[i] = Ref<SpineIkConstraint>(NULL);
		Ref<SpineIkConstraint> gd_a;
		gd_a.instance();
		gd_a->set_spine_object(b);
		gd_as[i] = gd_a;
	}
	return gd_as;
}

Array SpineSkeleton::get_path_constraints() {
	auto &as = skeleton->getPathConstraints();
	Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < gd_as.size(); ++i) {
		auto b = as[i];
		if (b == NULL)
			gd_as[i] = Ref<SpinePathConstraint>(NULL);
		Ref<SpinePathConstraint> gd_a;
		gd_a.instance();
		gd_a->set_spine_object(b);
		gd_as[i] = gd_a;
	}
	return gd_as;
}

Array SpineSkeleton::get_transform_constraints() {
	auto &as = skeleton->getTransformConstraints();
	Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < gd_as.size(); ++i) {
		auto b = as[i];
		if (b == NULL)
			gd_as[i] = Ref<SpineTransformConstraint>(NULL);
		Ref<SpineTransformConstraint> gd_a;
		gd_a.instance();
		gd_a->set_spine_object(b);
		gd_as[i] = gd_a;
	}
	return gd_as;
}

Ref<SpineSkin> SpineSkeleton::get_skin() {
	auto s = skeleton->getSkin();
	if (s == NULL)
		return NULL;
	Ref<SpineSkin> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(s);
	return gd_s;
}

Color SpineSkeleton::get_color() {
	auto &c = skeleton->getColor();
	return Color(c.r, c.g, c.b, c.a);
}

void SpineSkeleton::set_color(Color v) {
	auto &c = skeleton->getColor();
	c.set(v.r, v.g, v.b, v.a);
}

float SpineSkeleton::get_time() {
	return skeleton->getTime();
}

void SpineSkeleton::set_time(float v) {
	skeleton->setTime(v);
}

void SpineSkeleton::set_position(Vector2 pos) {
	skeleton->setPosition(pos.x, pos.y);
}

float SpineSkeleton::get_x() {
	return skeleton->getX();
}

void SpineSkeleton::set_x(float v) {
	skeleton->setX(v);
}

float SpineSkeleton::get_y() {
	return skeleton->getY();
}

void SpineSkeleton::set_y(float v) {
	skeleton->setY(v);
}

float SpineSkeleton::get_scale_x() {
	return skeleton->getScaleX();
}

void SpineSkeleton::set_scale_x(float v) {
	skeleton->setScaleX(v);
}

float SpineSkeleton::get_scale_y() {
	return skeleton->getScaleY();
}

void SpineSkeleton::set_scale_y(float v) {
	skeleton->setScaleY(v);
}

void SpineSkeleton::set_spine_sprite(SpineSprite *s) {
	the_sprite = s;
}

} //namespace godot