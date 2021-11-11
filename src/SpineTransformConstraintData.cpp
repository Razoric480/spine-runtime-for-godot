//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineTransformConstraintData.h"

void SpineTransformConstraintData::_register_methods() {
	godot::register_method("get_all_bone_data", &SpineTransformConstraintData::get_bones);
	godot::register_method("get_target", &SpineTransformConstraintData::get_target);
	godot::register_method("get_mix_rotate", &SpineTransformConstraintData::get_mix_rotate);
	godot::register_method("get_mix_x", &SpineTransformConstraintData::get_mix_x);
	godot::register_method("get_mix_y", &SpineTransformConstraintData::get_mix_y);
	godot::register_method("get_mix_scale_x", &SpineTransformConstraintData::get_mix_scale_x);
	godot::register_method("get_mix_scale_y", &SpineTransformConstraintData::get_mix_scale_y);
	godot::register_method("get_mix_shear_y", &SpineTransformConstraintData::get_mix_shear_y);
	godot::register_method("get_offset_rotation", &SpineTransformConstraintData::get_offset_rotation);
	godot::register_method("get_offset_x", &SpineTransformConstraintData::get_offset_x);
	godot::register_method("get_offset_y", &SpineTransformConstraintData::get_offset_y);
	godot::register_method("get_offset_scale_x", &SpineTransformConstraintData::get_offset_scale_x);
	godot::register_method("get_offset_scale_y", &SpineTransformConstraintData::get_offset_scale_y);
	godot::register_method("get_offset_shear_y", &SpineTransformConstraintData::get_offset_shear_y);
	godot::register_method("is_relative", &SpineTransformConstraintData::is_relative);
	godot::register_method("is_local", &SpineTransformConstraintData::is_local);
}

SpineTransformConstraintData::SpineTransformConstraintData() {}
SpineTransformConstraintData::~SpineTransformConstraintData() {}

godot::Array SpineTransformConstraintData::get_bones() {
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

godot::Ref<SpineBoneData> SpineTransformConstraintData::get_target() {
	auto b = get_spine_data()->getTarget();
	if (b == NULL)
		return NULL;
	godot::Ref<SpineBoneData> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	return gd_b;
}

float SpineTransformConstraintData::get_mix_rotate() {
	return get_spine_data()->getMixRotate();
}

float SpineTransformConstraintData::get_mix_x() {
	return get_spine_data()->getMixX();
}

float SpineTransformConstraintData::get_mix_y() {
	return get_spine_data()->getMixY();
}

float SpineTransformConstraintData::get_mix_scale_x() {
	return get_spine_data()->getMixScaleX();
}

float SpineTransformConstraintData::get_mix_scale_y() {
	return get_spine_data()->getMixScaleY();
}

float SpineTransformConstraintData::get_mix_shear_y() {
	return get_spine_data()->getMixShearY();
}

float SpineTransformConstraintData::get_offset_rotation() {
	return get_spine_data()->getOffsetRotation();
}

float SpineTransformConstraintData::get_offset_x() {
	return get_spine_data()->getOffsetX();
}

float SpineTransformConstraintData::get_offset_y() {
	return get_spine_data()->getOffsetY();
}

float SpineTransformConstraintData::get_offset_scale_x() {
	return get_spine_data()->getOffsetScaleX();
}

float SpineTransformConstraintData::get_offset_scale_y() {
	return get_spine_data()->getOffsetScaleY();
}

float SpineTransformConstraintData::get_offset_shear_y() {
	return get_spine_data()->getOffsetShearY();
}

bool SpineTransformConstraintData::is_relative() {
	return get_spine_data()->isRelative();
}

bool SpineTransformConstraintData::is_local() {
	return get_spine_data()->isLocal();
}