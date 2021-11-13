//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpinePathConstraintData.h"

void SpinePathConstraintData::_register_methods() {
	godot::register_method("get_all_bone_data", &SpinePathConstraintData::get_bones);
	godot::register_method("get_target", &SpinePathConstraintData::get_target);
	godot::register_method("set_target", &SpinePathConstraintData::set_target);
	godot::register_method("get_position_mode", &SpinePathConstraintData::get_position_mode);
	godot::register_method("set_position_mode", &SpinePathConstraintData::set_position_mode);
	godot::register_method("get_spacing_mode", &SpinePathConstraintData::get_spacing_mode);
	godot::register_method("set_spacing_mode", &SpinePathConstraintData::set_spacing_mode);
	godot::register_method("get_rotate_mode", &SpinePathConstraintData::get_rotate_mode);
	godot::register_method("set_rotate_mode", &SpinePathConstraintData::set_rotate_mode);
	godot::register_method("get_offset_rotation", &SpinePathConstraintData::get_offset_rotation);
	godot::register_method("set_offset_rotation", &SpinePathConstraintData::set_offset_rotation);
	godot::register_method("get_position", &SpinePathConstraintData::get_position);
	godot::register_method("set_position", &SpinePathConstraintData::set_position);
	godot::register_method("get_spacing", &SpinePathConstraintData::get_spacing);
	godot::register_method("set_spacing", &SpinePathConstraintData::set_spacing);
	godot::register_method("get_mix_rotate", &SpinePathConstraintData::get_mix_rotate);
	godot::register_method("set_mix_rotate", &SpinePathConstraintData::set_mix_rotate);
	godot::register_method("get_mix_x", &SpinePathConstraintData::get_mix_x);
	godot::register_method("set_mix_x", &SpinePathConstraintData::set_mix_x);
	godot::register_method("get_mix_y", &SpinePathConstraintData::get_mix_y);
	godot::register_method("set_mix_y", &SpinePathConstraintData::set_mix_y);

	godot::register_property<SpinePathConstraintData, int>("POSITIONMODE_FIXED", nullptr, &SpinePathConstraintData::get_POSITIONMODE_FIXED, 0);
	godot::register_property<SpinePathConstraintData, int>("POSITIONMODE_PERCENT", nullptr, &SpinePathConstraintData::get_POSITIONMODE_PERCENT, 0);
	godot::register_property<SpinePathConstraintData, int>("SPACINGMODE_LENGTH", nullptr, &SpinePathConstraintData::get_SPACINGMODE_LENGTH, 0);
	godot::register_property<SpinePathConstraintData, int>("SPACINGMODE_FIXED,", nullptr, &SpinePathConstraintData::get_SPACINGMODE_FIXED, 0);
	godot::register_property<SpinePathConstraintData, int>("SPACINGMODE_PERCENT", nullptr, &SpinePathConstraintData::get_SPACINGMODE_PERCENT, 0);
	godot::register_property<SpinePathConstraintData, int>("ROTATEMODE_TANGENT", nullptr, &SpinePathConstraintData::get_ROTATEMODE_TANGENT, 0);
	godot::register_property<SpinePathConstraintData, int>("ROTATEMODE_CHAIN", nullptr, &SpinePathConstraintData::get_ROTATEMODE_CHAIN, 0);
	godot::register_property<SpinePathConstraintData, int>("ROTATEMODE_CHAINSCALE", nullptr, &SpinePathConstraintData::get_ROTATEMODE_CHAINSCALE, 0);
}

int SpinePathConstraintData::get_POSITIONMODE_FIXED() {
	return POSITIONMODE_FIXED;
}

int SpinePathConstraintData::get_POSITIONMODE_PERCENT() {
	return POSITIONMODE_PERCENT;
}

int SpinePathConstraintData::get_SPACINGMODE_LENGTH() {
	return SPACINGMODE_LENGTH;
}

int SpinePathConstraintData::get_SPACINGMODE_FIXED() {
	return SPACINGMODE_FIXED;
}

int SpinePathConstraintData::get_SPACINGMODE_PERCENT() {
	return SPACINGMODE_PERCENT;
}

int SpinePathConstraintData::get_ROTATEMODE_TANGENT() {
	return ROTATEMODE_TANGENT;
}

int SpinePathConstraintData::get_ROTATEMODE_CHAIN() {
	return ROTATEMODE_CHAIN;
}

int SpinePathConstraintData::get_ROTATEMODE_CHAINSCALE() {
	return ROTATEMODE_CHAINSCALE;
}

SpinePathConstraintData::SpinePathConstraintData() {}
SpinePathConstraintData::~SpinePathConstraintData() {}

void SpinePathConstraintData::_init() {}

godot::Array SpinePathConstraintData::get_bones() {
	auto bs = get_spine_data()->getBones();
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

godot::Ref<SpineSlotData> SpinePathConstraintData::get_target() {
	auto s = get_spine_data()->getTarget();
	if (s == NULL)
		return NULL;
	godot::Ref<SpineSlotData> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(s);
	return gd_s;
}

void SpinePathConstraintData::set_target(godot::Ref<SpineSlotData> v) {
	if (v.is_valid()) {
		get_spine_data()->setTarget(v->get_spine_object());
	} else {
		get_spine_data()->setTarget(NULL);
	}
}

int SpinePathConstraintData::get_position_mode() {
	auto m = (int)get_spine_data()->getPositionMode();
	return m;
}

void SpinePathConstraintData::set_position_mode(int v) {
	auto m = (int)v;
	get_spine_data()->setPositionMode((spine::PositionMode)m);
}

int SpinePathConstraintData::get_spacing_mode() {
	auto m = (int)get_spine_data()->getSpacingMode();
	return m;
}

void SpinePathConstraintData::set_spacing_mode(int v) {
	auto m = (int)v;
	get_spine_data()->setSpacingMode((spine::SpacingMode)m);
}

int SpinePathConstraintData::get_rotate_mode() {
	auto m = (int)get_spine_data()->getRotateMode();
	return m;
}

void SpinePathConstraintData::set_rotate_mode(int v) {
	auto m = (int)v;
	get_spine_data()->setRotateMode((spine::RotateMode)m);
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
