//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineBoneData.h"

void SpineBoneData::_register_methods() {
	godot::register_method("get_index", &SpineBoneData::get_index);
	godot::register_method("get_bone_name", &SpineBoneData::get_bone_name);
	godot::register_method("get_parent", &SpineBoneData::get_parent);

	godot::register_method("get_length", &SpineBoneData::get_length);
	godot::register_method("set_length", &SpineBoneData::set_length);

	godot::register_method("get_x", &SpineBoneData::get_x);
	godot::register_method("set_x", &SpineBoneData::set_x);

	godot::register_method("get_y", &SpineBoneData::get_y);
	godot::register_method("set_y", &SpineBoneData::set_y);

	godot::register_method("get_rotation", &SpineBoneData::get_rotation);
	godot::register_method("set_rotation", &SpineBoneData::set_rotation);

	godot::register_method("get_scale_x", &SpineBoneData::get_scale_x);
	godot::register_method("set_scale_x", &SpineBoneData::set_scale_x);

	godot::register_method("get_scale_y", &SpineBoneData::get_scale_y);
	godot::register_method("set_scale_y", &SpineBoneData::set_scale_y);

	godot::register_method("get_shear_x", &SpineBoneData::get_shear_x);
	godot::register_method("set_shear_x", &SpineBoneData::set_shear_x);

	godot::register_method("get_shear_y", &SpineBoneData::get_shear_y);
	godot::register_method("set_shear_y", &SpineBoneData::set_shear_y);

	godot::register_method("get_transform_mode", &SpineBoneData::get_transform_mode);
	godot::register_method("set_transform_mode", &SpineBoneData::set_transform_mode);

	godot::register_method("is_skin_required", &SpineBoneData::is_skin_required);
	godot::register_method("set_skin_required", &SpineBoneData::set_skin_required);
	
	godot::register_property<SpineBoneData, int>("TRANSFORMMODE_NORMAL", nullptr, &SpineBoneData::get_TRANSFORMMODE_NORMAL, 0);
	godot::register_property<SpineBoneData, int>("TRANSFORMMODE_ONLYTRANSLATION", nullptr, &SpineBoneData::get_TRANSFORMMODE_ONLYTRANSLATION, 1);
	godot::register_property<SpineBoneData, int>("TRANSFORMMODE_NOROTATIONORREFLECTION", nullptr, &SpineBoneData::get_TRANSFORMMODE_NOROTATIONORREFLECTION, 2);
	godot::register_property<SpineBoneData, int>("TRANSFORMMODE_NOSCALE", nullptr, &SpineBoneData::get_TRANSFORMMODE_NOSCALE, 3);
	godot::register_property<SpineBoneData, int>("TRANSFORMMODE_NOSCALEORREFLECTION", nullptr, &SpineBoneData::get_TRANSFORMMODE_NOSCALEORREFLECTION, 4);
}

int SpineBoneData::get_TRANSFORMMODE_NORMAL() {
	return TRANSFORMMODE_NORMAL;
}
int SpineBoneData::get_TRANSFORMMODE_ONLYTRANSLATION() {
	return TRANSFORMMODE_ONLYTRANSLATION;
}
int SpineBoneData::get_TRANSFORMMODE_NOROTATIONORREFLECTION() {
	return TRANSFORMMODE_NOROTATIONORREFLECTION;
}
int SpineBoneData::get_TRANSFORMMODE_NOSCALE() {
	return TRANSFORMMODE_NOSCALE;
}
int SpineBoneData::get_TRANSFORMMODE_NOSCALEORREFLECTION() {
	return TRANSFORMMODE_NOSCALEORREFLECTION;
}

SpineBoneData::SpineBoneData() {}
SpineBoneData::~SpineBoneData() {}

void SpineBoneData::_init() {
	bone_data = nullptr;
}

int SpineBoneData::get_index() {
	return bone_data->getIndex();
}

godot::String SpineBoneData::get_bone_name() {
	return bone_data->getName().buffer();
}

godot::Ref<SpineBoneData> SpineBoneData::get_parent() {
	auto p = bone_data->getParent();
	if (p == NULL)
		return NULL;
	godot::Ref<SpineBoneData> gd_bone_data;
	gd_bone_data.instance();
	gd_bone_data->set_spine_object(p);
	return gd_bone_data;
}

float SpineBoneData::get_length() {
	return bone_data->getLength();
}
void SpineBoneData::set_length(float v) {
	bone_data->setLength(v);
}

float SpineBoneData::get_x() {
	return bone_data->getX();
}
void SpineBoneData::set_x(float v) {
	bone_data->setX(v);
}

float SpineBoneData::get_y() {
	return bone_data->getY();
}
void SpineBoneData::set_y(float v) {
	bone_data->setY(v);
}

float SpineBoneData::get_rotation() {
	return bone_data->getRotation();
}
void SpineBoneData::set_rotation(float v) {
	bone_data->setRotation(v);
}

float SpineBoneData::get_scale_x() {
	return bone_data->getScaleX();
}
void SpineBoneData::set_scale_x(float v) {
	bone_data->setScaleX(v);
}

float SpineBoneData::get_scale_y() {
	return bone_data->getScaleY();
}
void SpineBoneData::set_scale_y(float v) {
	bone_data->setScaleY(v);
}

float SpineBoneData::get_shear_x() {
	return bone_data->getShearX();
}
void SpineBoneData::set_shear_x(float v) {
	bone_data->setShearX(v);
}

float SpineBoneData::get_shear_y() {
	return bone_data->getShearY();
}
void SpineBoneData::set_shear_y(float v) {
	bone_data->setShearY(v);
}

SpineBoneData::TransformMode SpineBoneData::get_transform_mode() {
	auto tm = (int)bone_data->getTransformMode();
	return (TransformMode)tm;
}
void SpineBoneData::set_transform_mode(TransformMode v) {
	auto tm = (int)v;
	bone_data->setTransformMode((spine::TransformMode)tm);
}

bool SpineBoneData::is_skin_required() {
	return bone_data->isSkinRequired();
}
void SpineBoneData::set_skin_required(bool v) {
	bone_data->setSkinRequired(v);
}