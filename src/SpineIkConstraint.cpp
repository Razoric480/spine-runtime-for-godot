//
// Created by Raymond_Lx on 2020/6/6.
//

#include "SpineIkConstraint.h"
#include "SpineBone.h"

void SpineIkConstraint::_register_methods() {
	// ClassDB::bind_method(D_METHOD("apply"), &SpineIkConstraint::apply);
	godot::register_method("update", &SpineIkConstraint::update);
	godot::register_method("get_order", &SpineIkConstraint::get_order);
	godot::register_method("get_data", &SpineIkConstraint::get_data);
	godot::register_method("get_bones", &SpineIkConstraint::get_bones);
	godot::register_method("get_target", &SpineIkConstraint::get_target);
	godot::register_method("set_target", &SpineIkConstraint::set_target);
	godot::register_method("get_bend_direction", &SpineIkConstraint::get_bend_direction);
	godot::register_method("set_bend_direction", &SpineIkConstraint::set_bend_direction);
	godot::register_method("get_compress", &SpineIkConstraint::get_compress);
	godot::register_method("set_compress", &SpineIkConstraint::set_compress);
	godot::register_method("get_stretch", &SpineIkConstraint::get_stretch);
	godot::register_method("set_stretch", &SpineIkConstraint::set_stretch);
	godot::register_method("get_mix", &SpineIkConstraint::get_mix);
	godot::register_method("set_mix", &SpineIkConstraint::set_mix);
	godot::register_method("get_softness", &SpineIkConstraint::get_softness);
	godot::register_method("set_softness", &SpineIkConstraint::set_softness);
	godot::register_method("is_active", &SpineIkConstraint::is_active);
	godot::register_method("set_active", &SpineIkConstraint::set_active);
}

SpineIkConstraint::SpineIkConstraint() {}
SpineIkConstraint::~SpineIkConstraint() {}

void SpineIkConstraint::_init() {
	ik_constraint = nullptr;
}

// void SpineIkConstraint::apply(){
// 	ik_constraint->apply();
// }

void SpineIkConstraint::update() {
	ik_constraint->update();
}

int SpineIkConstraint::get_order() {
	return ik_constraint->getOrder();
}

godot::Ref<SpineIkConstraintData> SpineIkConstraint::get_data() {
	auto &ikc = ik_constraint->getData();
	godot::Ref<SpineIkConstraintData> gd_ikc;
	gd_ikc.instance();
	gd_ikc->set_spine_object(&ikc);
	return gd_ikc;
}

godot::Array SpineIkConstraint::get_bones() {
	auto &bs = ik_constraint->getBones();
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

godot::Ref<SpineBone> SpineIkConstraint::get_target() {
	auto b = ik_constraint->getTarget();
	if (b == NULL)
		return NULL;
	godot::Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}
void SpineIkConstraint::set_target(godot::Ref<SpineBone> v) {
	if (v.is_valid()) {
		ik_constraint->setTarget(v->get_spine_object());
	} else {
		ik_constraint->setTarget(NULL);
	}
}

int SpineIkConstraint::get_bend_direction() {
	return ik_constraint->getBendDirection();
}
void SpineIkConstraint::set_bend_direction(int v) {
	ik_constraint->setBendDirection(v);
}

bool SpineIkConstraint::get_compress() {
	return ik_constraint->getCompress();
}
void SpineIkConstraint::set_compress(bool v) {
	ik_constraint->setCompress(v);
}

bool SpineIkConstraint::get_stretch() {
	return ik_constraint->getStretch();
}
void SpineIkConstraint::set_stretch(bool v) {
	ik_constraint->setStretch(v);
}

float SpineIkConstraint::get_mix() {
	return ik_constraint->getMix();
}
void SpineIkConstraint::set_mix(float v) {
	ik_constraint->setMix(v);
}

float SpineIkConstraint::get_softness() {
	return ik_constraint->getSoftness();
}
void SpineIkConstraint::set_softness(float v) {
	ik_constraint->setSoftness(v);
}

bool SpineIkConstraint::is_active() {
	return ik_constraint->isActive();
}
void SpineIkConstraint::set_active(bool v) {
	ik_constraint->setActive(v);
}