//
// Created by Raiix on 2020/7/12.
//

#include "PackedSpineSkinResource.h"

void PackedSpineSkinResource::_register_methods() {
	register_signal("property_changed");

	register_property<PackedSpineSkinResource, String>("skin_name", &PackedSpineSkinResource::set_skin_name, &PackedSpineSkinResource::get_skin_name, "");
	register_property<PackedSpineSkinResource, String>("sub_skin_names", &PackedSpineSkinResource::set_sub_skin_names,&PackedSpineSkinResource::get_sub_skin_names, Array());
}

PackedSpineSkinResource::PackedSpineSkinResource() {}
PackedSpineSkinResource::~PackedSpineSkinResource() {}

void _init() {
	skin_name = "custom_skin_name";
}

void PackedSpineSkinResource::set_skin_name(const String &v) {
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
