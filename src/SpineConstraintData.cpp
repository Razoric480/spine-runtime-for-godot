//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineConstraintData.h"

void SpineConstraintData::_register_methods() {
	godot::register_method("get_constraint_data_name", &SpineConstraintData::get_constraint_data_name);
	godot::register_method("get_order", &SpineConstraintData::get_order);
	godot::register_method("set_order", &SpineConstraintData::set_order);
	godot::register_method("is_skin_required", &SpineConstraintData::is_skin_required);
	godot::register_method("set_skin_required", &SpineConstraintData::set_skin_required);
}

SpineConstraintData::SpineConstraintData() {
}

SpineConstraintData::~SpineConstraintData() {
}

void SpineConstraintData::_init() {
	constraint_data = nullptr;
}

godot::String SpineConstraintData::get_constraint_data_name() {
	return constraint_data->getName().buffer();
}

uint64_t SpineConstraintData::get_order() {
	return constraint_data->getOrder();
}

void SpineConstraintData::set_order(uint64_t v) {
	constraint_data->setOrder(v);
}

bool SpineConstraintData::is_skin_required() {
	return constraint_data->isSkinRequired();
}

void SpineConstraintData::set_skin_required(bool v) {
	constraint_data->setSkinRequired(v);
}
