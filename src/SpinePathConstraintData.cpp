//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpinePathConstraintData.h"

namespace godot {

void SpinePathConstraintData::_register_methods() {
	register_method("get_all_bone_data", &SpinePathConstraintData::get_bones);
	register_method("get_target", &SpinePathConstraintData::get_target);
	register_method("set_target", &SpinePathConstraintData::set_target);
	register_method("get_position_mode", &SpinePathConstraintData::get_position_mode);
	register_method("set_position_mode", &SpinePathConstraintData::set_position_mode);
	register_method("get_spacing_mode", &SpinePathConstraintData::get_spacing_mode);
	register_method("set_spacing_mode", &SpinePathConstraintData::set_spacing_mode);
	register_method("get_rotate_mode", &SpinePathConstraintData::get_rotate_mode);
	register_method("set_rotate_mode", &SpinePathConstraintData::set_rotate_mode);
	register_method("get_offset_rotation", &SpinePathConstraintData::get_offset_rotation);
	register_method("set_offset_rotation", &SpinePathConstraintData::set_offset_rotation);
	register_method("get_position", &SpinePathConstraintData::get_position);
	register_method("set_position", &SpinePathConstraintData::set_position);
	register_method("get_spacing", &SpinePathConstraintData::get_spacing);
	register_method("set_spacing", &SpinePathConstraintData::set_spacing);
	register_method("get_mix_rotate", &SpinePathConstraintData::get_mix_rotate);
	register_method("set_mix_rotate", &SpinePathConstraintData::set_mix_rotate);
	register_method("get_mix_x", &SpinePathConstraintData::get_mix_x);
	register_method("set_mix_x", &SpinePathConstraintData::set_mix_x);
	register_method("get_mix_y", &SpinePathConstraintData::get_mix_y);
	register_method("set_mix_y", &SpinePathConstraintData::set_mix_y);
}

SpinePathConstraintData::SpinePathConstraintData() {}
SpinePathConstraintData::~SpinePathConstraintData() {}

void SpinePathConstraintData::_init() {
	
}

Array SpinePathConstraintData::get_bones() {
	auto bs = get_spine_data()->getBones();
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

Ref<SpineSlotData> SpinePathConstraintData::get_target() {
	auto s = get_spine_data()->getTarget();
	if (s == NULL)
		return NULL;
	Ref<SpineSlotData> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(s);
	return gd_s;
}

void SpinePathConstraintData::set_target(Ref<SpineSlotData> v) {
	if (v.is_valid()) {
		get_spine_data()->setTarget(v->get_spine_object());
	} else {
		get_spine_data()->setTarget(NULL);
	}
}

int SpinePathConstraintData::get_position_mode() {
	return (int)get_spine_data()->getPositionMode();
}

void SpinePathConstraintData::set_position_mode(int v) {
	get_spine_data()->setPositionMode((spine::PositionMode)v);
}

int SpinePathConstraintData::get_spacing_mode() {
	return (int)get_spine_data()->getSpacingMode();
}

void SpinePathConstraintData::set_spacing_mode(int v) {
	get_spine_data()->setSpacingMode((spine::SpacingMode)v);
}

int SpinePathConstraintData::get_rotate_mode() {
	return (int)get_spine_data()->getRotateMode();
}

void SpinePathConstraintData::set_rotate_mode(int v) {
	get_spine_data()->setRotateMode((spine::RotateMode)v);
}

float SpinePathConstraintData::get_offset_rotation() {
	return get_spine_data()->getOffsetRotation();
}

void SpinePathConstraintData::set_offset_rotation(float v) {
	get_spine_data()->setOffsetRotation(v);
}

float SpinePathConstraintData::get_position() {
	return get_spine_data()->getPosition();
}

void SpinePathConstraintData::set_position(float v) {
	get_spine_data()->setPosition(v);
}

float SpinePathConstraintData::get_spacing() {
	return get_spine_data()->getSpacing();
}

void SpinePathConstraintData::set_spacing(float v) {
	get_spine_data()->setSpacing(v);
}

float SpinePathConstraintData::get_mix_rotate() {
	return get_spine_data()->getMixRotate();
}

void SpinePathConstraintData::set_mix_rotate(float v) {
	get_spine_data()->setMixRotate(v);
}

float SpinePathConstraintData::get_mix_x() {
	return get_spine_data()->getMixX();
}

void SpinePathConstraintData::set_mix_x(float v) {
	get_spine_data()->setMixX(v);
}

float SpinePathConstraintData::get_mix_y() {
	return get_spine_data()->getMixY();
}

void SpinePathConstraintData::set_mix_y(float v) {
	get_spine_data()->setMixY(v);
}

} //namespace godot