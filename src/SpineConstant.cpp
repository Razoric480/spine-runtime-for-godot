//
// Created by Raiix on 2021/7/14.
// Edited by Razoric on 2021/11/xx
//

#include "SpineConstant.h"

void SpineConstant::_register_methods() {
	godot::register_property("MixBlend_Setup", &SpineConstant::noset, &SpineConstant::get_MixBlend_Setup, 0);
	godot::register_property("MixBlend_First", &SpineConstant::noset, &SpineConstant::get_MixBlend_First, 0);
	godot::register_property("MixBlend_Replace", &SpineConstant::noset, &SpineConstant::get_MixBlend_Replace, 0);
	godot::register_property("MixBlend_Add", &SpineConstant::noset, &SpineConstant::get_MixBlend_Add, 0);
	godot::register_property("MixDirection_In", &SpineConstant::noset, &SpineConstant::get_MixDirection_In, 0);
	godot::register_property("MixDirection_Out", &SpineConstant::noset, &SpineConstant::get_MixDirection_Out, 0);
	godot::register_property("Property_Rotate", &SpineConstant::noset, &SpineConstant::get_Property_Rotate, 0);
	godot::register_property("Property_X", &SpineConstant::noset, &SpineConstant::get_Property_X, 0);
	godot::register_property("Property_Y", &SpineConstant::noset, &SpineConstant::get_Property_Y, 0);
	godot::register_property("Property_ScaleX", &SpineConstant::noset, &SpineConstant::get_Property_ScaleX, 0);
	godot::register_property("Property_ScaleY", &SpineConstant::noset, &SpineConstant::get_Property_ScaleY, 0);
	godot::register_property("Property_ShearX", &SpineConstant::noset, &SpineConstant::get_Property_ShearX, 0);
	godot::register_property("Property_ShearY", &SpineConstant::noset, &SpineConstant::get_Property_ShearY, 0);
	godot::register_property("Property_Rgb", &SpineConstant::noset, &SpineConstant::get_Property_Rgb, 0);
	godot::register_property("Property_Alpha", &SpineConstant::noset, &SpineConstant::get_Property_Alpha, 0);
	godot::register_property("Property_Rgb2", &SpineConstant::noset, &SpineConstant::get_Property_Rgb2, 0);
	godot::register_property("Property_Attachment", &SpineConstant::noset, &SpineConstant::get_Property_Attachment, 0);
	godot::register_property("Property_Deform", &SpineConstant::noset, &SpineConstant::get_Property_Deform, 0);
	godot::register_property("Property_Event", &SpineConstant::noset, &SpineConstant::get_Property_Event, 0);
	godot::register_property("Property_DrawOrder", &SpineConstant::noset, &SpineConstant::get_Property_DrawOrder, 0);
	godot::register_property("Property_IkConstraint", &SpineConstant::noset, &SpineConstant::get_Property_IkConstraint, 0);
	godot::register_property("Property_TransformConstraint", &SpineConstant::noset, &SpineConstant::get_Property_TransformConstraint, 0);
	godot::register_property("Property_PathConstraintPosition", &SpineConstant::noset, &SpineConstant::get_Property_PathConstraintPosition, 0);
	godot::register_property("Property_PathConstraintSpacing", &SpineConstant::noset, &SpineConstant::get_Property_PathConstraintSpacing, 0);
	godot::register_property("Property_PathConstraintMix", &SpineConstant::noset, &SpineConstant::get_Property_PathConstraintMix, 0);
}

void SpineConstant::_init() {
}

int SpineConstant::get_MixBlend_Setup() const {
	return MixBlend_Setup;
}

int SpineConstant::get_MixBlend_First() const {
	return MixBlend_First;
}

int SpineConstant::get_MixBlend_Replace() const {
	return MixBlend_Replace;
}

int SpineConstant::get_MixBlend_Add() const {
	return MixBlend_Add;
}

int SpineConstant::get_MixDirection_In() const {
	return MixDirection_In;
}

int SpineConstant::get_MixDirection_Out() const {
	return MixDirection_Out;
}

int SpineConstant::get_Property_Rotate() const {
	return Property_Rotate;
}

int SpineConstant::get_Property_X() const {
	return Property_X;
}

int SpineConstant::get_Property_Y() const {
	return Property_Y;
}

int SpineConstant::get_Property_ScaleX() const {
	return Property_ScaleX;
}

int SpineConstant::get_Property_ScaleY() const {
	return Property_ScaleY;
}

int SpineConstant::get_Property_ShearX() const {
	return Property_ShearX;
}

int SpineConstant::get_Property_ShearY() const {
	return Property_ShearY;
}

int SpineConstant::get_Property_Rgb() const {
	return Property_Rgb;
}

int SpineConstant::get_Property_Alpha() const {
	return Property_Alpha;
}

int SpineConstant::get_Property_Rgb2() const {
	return Property_Rgb2;
}

int SpineConstant::get_Property_Attachment() const {
	return Property_Attachment;
}

int SpineConstant::get_Property_Deform() const {
	return Property_Deform;
}

int SpineConstant::get_Property_Event() const {
	return Property_Event;
}

int SpineConstant::get_Property_DrawOrder() const {
	return Property_DrawOrder;
}

int SpineConstant::get_Property_IkConstraint() const {
	return Property_IkConstraint;
}

int SpineConstant::get_Property_TransformConstraint() const {
	return Property_TransformConstraint;
}

int SpineConstant::get_Property_PathConstraintPosition() const {
	return Property_PathConstraintPosition;
}

int SpineConstant::get_Property_PathConstraintSpacing() const {
	return Property_PathConstraintSpacing;
}

int SpineConstant::get_Property_PathConstraintMix() const {
	return Property_PathConstraintMix;
}

void SpineConstant::noset(int v) {
}