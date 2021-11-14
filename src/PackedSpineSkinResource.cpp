//
// Created by Raiix on 2020/7/12.
//

#include "PackedSpineSkinResource.h"

namespace godot {

void PackedSpineSkinResource::_register_methods() {
	register_method("set_skin_name", &PackedSpineSkinResource::set_skin_name);
	register_method("get_skin_name", &PackedSpineSkinResource::get_skin_name);
	register_method("set_sub_skin_names", &PackedSpineSkinResource::set_sub_skin_names);
	register_method("get_sub_skin_names", &PackedSpineSkinResource::get_sub_skin_names);

	register_signal<PackedSpineSkinResource>("property_changed", Dictionary());

	register_property<PackedSpineSkinResource, String>("skin_name", &PackedSpineSkinResource::set_skin_name, &PackedSpineSkinResource::get_skin_name, "");
	register_property<PackedSpineSkinResource, Array>("sub_skin_names", &PackedSpineSkinResource::set_sub_skin_names, &PackedSpineSkinResource::get_sub_skin_names, Array());
}

PackedSpineSkinResource::PackedSpineSkinResource() {}
PackedSpineSkinResource::~PackedSpineSkinResource() {}

void PackedSpineSkinResource::_init() {
	skin_name = "custom_skin_name";
}

void PackedSpineSkinResource::set_skin_name(String v) {
	skin_name = v;
	emit_signal("property_changed");
}

String PackedSpineSkinResource::get_skin_name() {
	return skin_name;
}

void PackedSpineSkinResource::set_sub_skin_names(Array v) {
	sub_skin_names = v;
	emit_signal("property_changed");
}

Array PackedSpineSkinResource::get_sub_skin_names() {
	return sub_skin_names;
}

} //namespace godot