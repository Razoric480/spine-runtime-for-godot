//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineSlotData.h"

void SpineSlotData::_register_methods() {
	godot::register_method("get_index", &SpineSlotData::get_index);
	godot::register_method("get_slot_name", &SpineSlotData::get_slot_name);
	godot::register_method("get_bone_data", &SpineSlotData::get_bone_data);
	godot::register_method("get_color", &SpineSlotData::get_color);
	godot::register_method("get_dark_color", &SpineSlotData::get_dark_color);
	godot::register_method("has_dark_color", &SpineSlotData::has_dark_color);
	godot::register_method("set_has_dark_color", &SpineSlotData::set_has_dark_color);
	godot::register_method("get_attachment_name", &SpineSlotData::get_attachment_name);
	godot::register_method("set_attachment_name", &SpineSlotData::set_attachment_name);
	godot::register_method("get_blend_mode", &SpineSlotData::get_blend_mode);
	godot::register_method("set_blend_mode", &SpineSlotData::set_blend_mode);

	godot::register_method("set_color", &SpineSlotData::set_color);
	godot::register_method("set_dark_color", &SpineSlotData::set_dark_color);

	godot::register_property<SpineSlotData, int>("BLENDMODE_NORMAL", nullptr, &SpineSlotData::get_BLENDMODE_NORMAL, 0);
	godot::register_property<SpineSlotData, int>("BLENDMODE_ADDITIVE", nullptr, &SpineSlotData::get_BLENDMODE_ADDITIVE, 0);
	godot::register_property<SpineSlotData, int>("BLENDMODE_MULTIPLY", nullptr, &SpineSlotData::get_BLENDMODE_MULTIPLY, 0);
	godot::register_property<SpineSlotData, int>("BLENDMODE_SCREEN", nullptr, &SpineSlotData::get_BLENDMODE_SCREEN, 0);
}

SpineSlotData::SpineSlotData() {}
SpineSlotData::~SpineSlotData() {}

int SpineSlotData::get_BLENDMODE_NORMAL() {
	return BLENDMODE_NORMAL;
}

int SpineSlotData::get_BLENDMODE_ADDITIVE() {
	return BLENDMODE_ADDITIVE;
}

int SpineSlotData::get_BLENDMODE_MULTIPLY() {
	return BLENDMODE_MULTIPLY;
}

int SpineSlotData::get_BLENDMODE_SCREEN() {
	return BLENDMODE_SCREEN;
}

void SpineSlotData::_init() {
	slot_data = nullptr;
}

#define S_T(x) (spine::String(x.utf8().get_data()))
int SpineSlotData::get_index() {
	return slot_data->getIndex();
}

godot::String SpineSlotData::get_slot_name() {
	return slot_data->getName().buffer();
}

godot::Ref<SpineBoneData> SpineSlotData::get_bone_data() {
	auto &bd = slot_data->getBoneData();
	godot::Ref<SpineBoneData> gd_bone_data;
	gd_bone_data.instance();
	gd_bone_data->set_spine_object(&bd);
	return gd_bone_data;
}

godot::Color SpineSlotData::get_color() {
	auto &c = slot_data->getColor();
	return godot::Color(c.r, c.g, c.b, c.a);
}

void SpineSlotData::set_color(godot::Color v) {
	auto &c = slot_data->getColor();
	c.set(v.r, v.g, v.b, v.a);
}

godot::Color SpineSlotData::get_dark_color() {
	auto &c = slot_data->getDarkColor();
	return godot::Color(c.r, c.g, c.b, c.a);
}
void SpineSlotData::set_dark_color(godot::Color v) {
	auto &c = slot_data->getDarkColor();
	c.set(v.r, v.g, v.b, v.a);
}

bool SpineSlotData::has_dark_color() {
	return slot_data->hasDarkColor();
}

void SpineSlotData::set_has_dark_color(bool v) {
	slot_data->setHasDarkColor(v);
}

godot::String SpineSlotData::get_attachment_name() {
	return slot_data->getAttachmentName().buffer();
}

void SpineSlotData::set_attachment_name(const godot::String &v) {
	slot_data->setAttachmentName(S_T(v));
}

SpineSlotData::BlendMode SpineSlotData::get_blend_mode() {
	auto bm = (int)slot_data->getBlendMode();
	return (BlendMode)bm;
}
void SpineSlotData::set_blend_mode(BlendMode v) {
	auto bm = (int)v;
	slot_data->setBlendMode((spine::BlendMode)bm);
}

#undef S_T