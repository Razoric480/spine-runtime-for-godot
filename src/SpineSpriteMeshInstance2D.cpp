//
// Created by Raymond_Lx on 2020/6/7.
//

#include "SpineSpriteMeshInstance2D.h"

#include "SpineBone.h"

void SpineSpriteMeshInstance2D::_register_methods() {
	godot::register_method("get_slot", &SpineSpriteMeshInstance2D::get_slot);
	godot::register_method("apply_transform_2d", &SpineSpriteMeshInstance2D::apply_transform_2d);
}

SpineSpriteMeshInstance2D::SpineSpriteMeshInstance2D() {}
SpineSpriteMeshInstance2D::~SpineSpriteMeshInstance2D() {}

godot::Ref<SpineSlot> SpineSpriteMeshInstance2D::get_slot() {
	return slot;
}

void SpineSpriteMeshInstance2D::_init() {}

void SpineSpriteMeshInstance2D::apply_transform_2d(godot::Variant o){
	slot->get_bone()->apply_world_transform_2d(o);
}