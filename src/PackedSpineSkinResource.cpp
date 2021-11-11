//
// Created by Raiix on 2020/7/12.
//

#include "PackedSpineSkinResource.h"

void PackedSpineSkinResource::_register_methods() {
	godot::register_signal<PackedSpineSkinResource>("property_changed");

	godot::register_property<PackedSpineSkinResource, const godot::String &>("skin_name", &PackedSpineSkinResource::set_skin_name, &PackedSpineSkinResource::get_skin_name, "");
	godot::register_property<PackedSpineSkinResource, godot::Array>("sub_skin_names", &PackedSpineSkinResource::set_sub_skin_names, &PackedSpineSkinResource::get_sub_skin_names, godot::Array());
}

PackedSpineSkinResource::PackedSpineSkinResource() {}
PackedSpineSkinResource::~PackedSpineSkinResource() {}

void PackedSpineSkinResource::_init() {
	skin_name = "custom_skin_name";
}

void PackedSpineSkinResource::set_skin_name(const godot::String &v) {
	skin_name = v;
	emit_signal("property_changed");
}

const godot::String &PackedSpineSkinResource::get_skin_name() {
	return skin_name;
}

void PackedSpineSkinResource::set_sub_skin_names(godot::Array v) {
	sub_skin_names = v;
	emit_signal("property_changed");
}

godot::Array PackedSpineSkinResource::get_sub_skin_names() {
	return sub_skin_names;
}
