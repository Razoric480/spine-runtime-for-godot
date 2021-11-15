//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpineSlotData.h"

namespace godot {

void SpineSlotData::_register_methods() {
	register_method("get_index", &SpineSlotData::get_index);
	register_method("get_slot_name", &SpineSlotData::get_slot_name);
	register_method("get_bone_data", &SpineSlotData::get_bone_data);
	register_method("get_color", &SpineSlotData::get_color);
	register_method("get_dark_color", &SpineSlotData::get_dark_color);
	register_method("has_dark_color", &SpineSlotData::has_dark_color);
	register_method("set_has_dark_color", &SpineSlotData::set_has_dark_color);
	register_method("get_attachment_name", &SpineSlotData::get_attachment_name);
	register_method("set_attachment_name", &SpineSlotData::set_attachment_name);
	register_method("get_blend_mode", &SpineSlotData::get_blend_mode);
	register_method("set_blend_mode", &SpineSlotData::set_blend_mode);

	register_method("set_color", &SpineSlotData::set_color);
	register_method("set_dark_color", &SpineSlotData::set_dark_color);
}

SpineSlotData::SpineSlotData() {}
SpineSlotData::~SpineSlotData() {}

void SpineSlotData::_init() {
	slot_data = nullptr;
}

#define S_T(x) (spine::String(x.alloc_c_string()))
int SpineSlotData::get_index() {
	return slot_data->getIndex();
}

String SpineSlotData::get_slot_name() {
	return slot_data->getName().buffer();
}

Ref<SpineBoneData> SpineSlotData::get_bone_data() {
	auto &bd = slot_data->getBoneData();
	Ref<SpineBoneData> gd_bone_data;
	gd_bone_data.instance();
	gd_bone_data->set_spine_object(&bd);
	return gd_bone_data;
}

Color SpineSlotData::get_color() {
	auto &c = slot_data->getColor();
	return Color(c.r, c.g, c.b, c.a);
}

void SpineSlotData::set_color(Color v) {
	auto &c = slot_data->getColor();
	c.set(v.r, v.g, v.b, v.a);
}

Color SpineSlotData::get_dark_color() {
	auto &c = slot_data->getDarkColor();
	return Color(c.r, c.g, c.b, c.a);
}

void SpineSlotData::set_dark_color(Color v) {
	auto &c = slot_data->getDarkColor();
	c.set(v.r, v.g, v.b, v.a);
}

bool SpineSlotData::has_dark_color() {
	return slot_data->hasDarkColor();
}

void SpineSlotData::set_has_dark_color(bool v) {
	slot_data->setHasDarkColor(v);
}

String SpineSlotData::get_attachment_name() {
	return slot_data->getAttachmentName().buffer();
}

void SpineSlotData::set_attachment_name(const String &v) {
	slot_data->setAttachmentName(S_T(v));
}

int SpineSlotData::get_blend_mode() {
	return (int)slot_data->getBlendMode();
}

void SpineSlotData::set_blend_mode(int v) {
	slot_data->setBlendMode((spine::BlendMode)v);
}

#undef S_T

} //namespace godot