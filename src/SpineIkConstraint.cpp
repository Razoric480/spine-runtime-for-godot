//
// Created by Raymond_Lx on 2020/6/6.
//

#include "SpineIkConstraint.h"
#include "SpineBone.h"

namespace godot {

void SpineIkConstraint::_register_methods() {
	// register_method("apply", &SpineIkConstraint::apply);
	register_method("update", &SpineIkConstraint::update);
	register_method("get_order", &SpineIkConstraint::get_order);
	register_method("get_data", &SpineIkConstraint::get_data);
	register_method("get_bones", &SpineIkConstraint::get_bones);
	register_method("get_target", &SpineIkConstraint::get_target);
	register_method("set_target", &SpineIkConstraint::set_target);
	register_method("get_bend_direction", &SpineIkConstraint::get_bend_direction);
	register_method("set_bend_direction", &SpineIkConstraint::set_bend_direction);
	register_method("get_compress", &SpineIkConstraint::get_compress);
	register_method("set_compress", &SpineIkConstraint::set_compress);
	register_method("get_stretch", &SpineIkConstraint::get_stretch);
	register_method("set_stretch", &SpineIkConstraint::set_stretch);
	register_method("get_mix", &SpineIkConstraint::get_mix);
	register_method("set_mix", &SpineIkConstraint::set_mix);
	register_method("get_softness", &SpineIkConstraint::get_softness);
	register_method("set_softness", &SpineIkConstraint::set_softness);
	register_method("is_active", &SpineIkConstraint::is_active);
	register_method("set_active", &SpineIkConstraint::set_active);
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

Ref<SpineIkConstraintData> SpineIkConstraint::get_data() {
	auto &ikc = ik_constraint->getData();
	Ref<SpineIkConstraintData> gd_ikc;
	gd_ikc.instance();
	gd_ikc->set_spine_object(&ikc);
	return gd_ikc;
}

Array SpineIkConstraint::get_bones() {
	auto &bs = ik_constraint->getBones();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		auto b = bs[i];
		if (b == NULL)
			gd_bs[i] = Ref<SpineBone>(NULL);
		Ref<SpineBone> gd_b;
		gd_b.instance();
		gd_b->set_spine_object(b);
		gd_bs[i] = gd_b;
	}
	return gd_bs;
}

Ref<SpineBone> SpineIkConstraint::get_target() {
	auto b = ik_constraint->getTarget();
	if (b == NULL)
		return NULL;
	Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

void SpineIkConstraint::set_target(Ref<SpineBone> v) {
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

} //namespace godot