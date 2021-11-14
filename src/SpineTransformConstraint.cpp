//
// Created by Raymond_Lx on 2020/6/6.
//

#include "SpineTransformConstraint.h"

namespace godot {

void SpineTransformConstraint::_register_methods() {
	register_method("update", &SpineTransformConstraint::update);
	register_method("get_data", &SpineTransformConstraint::get_data);
	register_method("get_bones", &SpineTransformConstraint::get_bones);
	register_method("get_target", &SpineTransformConstraint::get_target);
	register_method("set_target", &SpineTransformConstraint::set_target);
	register_method("get_mix_rotate", &SpineTransformConstraint::get_mix_rotate);
	register_method("set_mix_rotate", &SpineTransformConstraint::set_mix_rotate);
	register_method("get_mix_x", &SpineTransformConstraint::get_mix_x);
	register_method("set_mix_x", &SpineTransformConstraint::set_mix_x);
	register_method("get_mix_y", &SpineTransformConstraint::get_mix_y);
	register_method("set_mix_y", &SpineTransformConstraint::set_mix_y);
	register_method("get_mix_scale_x", &SpineTransformConstraint::get_mix_scale_x);
	register_method("set_mix_scale_x", &SpineTransformConstraint::set_mix_scale_x);
	register_method("get_mix_scale_y", &SpineTransformConstraint::get_mix_scale_y);
	register_method("set_mix_scale_y", &SpineTransformConstraint::set_mix_scale_y);
	register_method("get_mix_shear_y", &SpineTransformConstraint::get_mix_shear_y);
	register_method("set_mix_shear_y", &SpineTransformConstraint::set_mix_shear_y);
	register_method("is_active", &SpineTransformConstraint::is_active);
	register_method("set_active", &SpineTransformConstraint::set_active);
}

SpineTransformConstraint::SpineTransformConstraint() {}
SpineTransformConstraint::~SpineTransformConstraint() {}

void SpineTransformConstraint::_init() {
	transform_constraint = nullptr;
}

void SpineTransformConstraint::update() {
	transform_constraint->update();
}

int SpineTransformConstraint::get_order() {
	return transform_constraint->getOrder();
}

Ref<SpineTransformConstraintData> SpineTransformConstraint::get_data() {
	auto &d = transform_constraint->getData();
	Ref<SpineTransformConstraintData> gd_d;
	gd_d.instance();
	gd_d->set_spine_object(&d);
	return gd_d;
}

Array SpineTransformConstraint::get_bones() {
	auto &bs = transform_constraint->getBones();
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

Ref<SpineBone> SpineTransformConstraint::get_target() {
	auto b = transform_constraint->getTarget();
	if (b == NULL)
		return NULL;
	Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

void SpineTransformConstraint::set_target(Ref<SpineBone> v) {
	if (v.is_valid()) {
		transform_constraint->setTarget(v->get_spine_object());
	} else {
		transform_constraint->setTarget(NULL);
	}
}

float SpineTransformConstraint::get_mix_rotate() {
	return transform_constraint->getMixRotate();
}

void SpineTransformConstraint::set_mix_rotate(float v) {
	transform_constraint->setMixRotate(v);
}

float SpineTransformConstraint::get_mix_x() {
	return transform_constraint->getMixX();
}

void SpineTransformConstraint::set_mix_x(float v) {
	transform_constraint->setMixX(v);
}

float SpineTransformConstraint::get_mix_y() {
	return transform_constraint->getMixY();
}

void SpineTransformConstraint::set_mix_y(float v) {
	transform_constraint->setMixY(v);
}

float SpineTransformConstraint::get_mix_scale_x() {
	return transform_constraint->getMixScaleX();
}

void SpineTransformConstraint::set_mix_scale_x(float v) {
	transform_constraint->setMixScaleX(v);
}

float SpineTransformConstraint::get_mix_scale_y() {
	return transform_constraint->getMixScaleY();
}

void SpineTransformConstraint::set_mix_scale_y(float v) {
	transform_constraint->setMixScaleY(v);
}

float SpineTransformConstraint::get_mix_shear_y() {
	return transform_constraint->getMixShearY();
}

void SpineTransformConstraint::set_mix_shear_y(float v) {
	transform_constraint->setMixShearY(v);
}

bool SpineTransformConstraint::is_active() {
	return transform_constraint->isActive();
}

void SpineTransformConstraint::set_active(bool v) {
	transform_constraint->setActive(v);
}

} //namespace godot