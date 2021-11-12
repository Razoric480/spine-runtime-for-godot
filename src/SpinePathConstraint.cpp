//
// Created by Raymond_Lx on 2020/6/6.
//

#include "SpinePathConstraint.h"

void SpinePathConstraint::_register_methods() {
	// ClassDB::bind_method(D_METHOD("apply"), &SpinePathConstraint::apply);
	godot::register_method("update", &SpinePathConstraint::update);
	godot::register_method("get_order", &SpinePathConstraint::get_order);
	godot::register_method("get_position", &SpinePathConstraint::get_position);
	godot::register_method("set_position", &SpinePathConstraint::set_position);
	godot::register_method("get_spacing", &SpinePathConstraint::get_spacing);
	godot::register_method("set_spacing", &SpinePathConstraint::set_spacing);
	godot::register_method("get_mix_rotate", &SpinePathConstraint::get_mix_rotate);
	godot::register_method("set_mix_rotate", &SpinePathConstraint::set_mix_rotate);
	godot::register_method("get_mix_x", &SpinePathConstraint::get_mix_x);
	godot::register_method("set_mix_x", &SpinePathConstraint::set_mix_x);
	godot::register_method("get_mix_y", &SpinePathConstraint::get_mix_y);
	godot::register_method("set_mix_y", &SpinePathConstraint::set_mix_y);
	godot::register_method("get_bones", &SpinePathConstraint::get_bones);
	godot::register_method("get_target", &SpinePathConstraint::get_target);
	godot::register_method("set_target", &SpinePathConstraint::set_target);
	godot::register_method("get_data", &SpinePathConstraint::get_data);
	godot::register_method("is_active", &SpinePathConstraint::is_active);
	godot::register_method("set_active", &SpinePathConstraint::set_active);
}

SpinePathConstraint::SpinePathConstraint() {}
SpinePathConstraint::~SpinePathConstraint() {}

// void SpinePathConstraint::apply(){
// 	path_constraint->apply();
// }

void SpinePathConstraint::_init() {
	path_constraint = nullptr;
}

void SpinePathConstraint::update() {
	path_constraint->update();
}

int SpinePathConstraint::get_order() {
	return path_constraint->getOrder();
}

float SpinePathConstraint::get_position() {
	return path_constraint->getPosition();
}
void SpinePathConstraint::set_position(float v) {
	path_constraint->setPosition(v);
}

float SpinePathConstraint::get_spacing() {
	return path_constraint->getSpacing();
}
void SpinePathConstraint::set_spacing(float v) {
	path_constraint->setSpacing(v);
}

float SpinePathConstraint::get_mix_rotate() {
	return path_constraint->getMixRotate();
}
void SpinePathConstraint::set_mix_rotate(float v) {
	path_constraint->setMixRotate(v);
}

float SpinePathConstraint::get_mix_x() {
	return path_constraint->getMixX();
}
void SpinePathConstraint::set_mix_x(float v) {
	path_constraint->setMixX(v);
}

float SpinePathConstraint::get_mix_y() {
	return path_constraint->getMixY();
}
void SpinePathConstraint::set_mix_y(float v) {
	path_constraint->setMixY(v);
}

godot::Array SpinePathConstraint::get_bones() {
	auto &bs = path_constraint->getBones();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		auto b = bs[i];
		if (b == NULL)
			gd_bs[i] = godot::Ref<SpineBone>(NULL);
		godot::Ref<SpineBone> gd_b;
		gd_b.instance();
		gd_b->set_spine_object(b);
		gd_bs[i] = gd_b;
	}
	return gd_bs;
}

godot::Ref<SpineSlot> SpinePathConstraint::get_target() {
	auto s = path_constraint->getTarget();
	if (s == NULL)
		return NULL;
	godot::Ref<SpineSlot> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(s);
	return gd_s;
}
void SpinePathConstraint::set_target(godot::Ref<SpineSlot> v) {
	if (v.is_valid()) {
		path_constraint->setTarget(v->get_spine_object());
	} else {
		path_constraint->setTarget(NULL);
	}
}

godot::Ref<SpinePathConstraintData> SpinePathConstraint::get_data() {
	auto &sd = path_constraint->getData();
	godot::Ref<SpinePathConstraintData> gd_sd;
	gd_sd.instance();
	gd_sd->set_spine_object(&sd);
	return gd_sd;
}

bool SpinePathConstraint::is_active() {
	return path_constraint->isActive();
}

void SpinePathConstraint::set_active(bool v) {
	path_constraint->setActive(v);
}