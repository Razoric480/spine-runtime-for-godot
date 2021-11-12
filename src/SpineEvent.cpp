//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineEvent.h"

void SpineEvent::_register_methods() {
	godot::register_method("get_data", &SpineEvent::get_data);
	godot::register_method("get_event_name", &SpineEvent::get_event_name);
	godot::register_method("get_time", &SpineEvent::get_time);
	godot::register_method("get_int_value", &SpineEvent::get_int_value);
	godot::register_method("set_int_value", &SpineEvent::set_int_value);
	godot::register_method("get_float_value", &SpineEvent::get_float_value);
	godot::register_method("set_float_value", &SpineEvent::set_float_value);
	godot::register_method("get_string_value", &SpineEvent::get_string_value);
	godot::register_method("set_string_value", &SpineEvent::set_string_value);
	godot::register_method("get_volume", &SpineEvent::get_volume);
	godot::register_method("set_volume", &SpineEvent::set_volume);
	godot::register_method("get_balance", &SpineEvent::get_balance);
	godot::register_method("set_balance", &SpineEvent::set_balance);
	//
	//	BIND_ENUM_CONSTANT(EVENTTYPE_START);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_INTERRUPT);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_END);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_COMPLETE);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_DISPOSE);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_EVENT);
}

SpineEvent::SpineEvent() {
}

SpineEvent::~SpineEvent() {
}

void SpineEvent::_init() {
	event = nullptr;
}

godot::Ref<SpineEventData> SpineEvent::get_data() {
	godot::Ref<SpineEventData> event_data;
	event_data.instance();
	event_data->set_spine_object(&(event->getData()));
	return event_data;
}

godot::String SpineEvent::get_event_name() {
	return event->getData().getName().buffer();
}

float SpineEvent::get_time() {
	return event->getTime();
}

int SpineEvent::get_int_value() {
	return event->getIntValue();
}

void SpineEvent::set_int_value(int v) {
	event->setIntValue(v);
}

float SpineEvent::get_float_value() {
	return event->getFloatValue();
}

void SpineEvent::set_float_value(float v) {
	event->setFloatValue(v);
}

godot::String SpineEvent::get_string_value() {
	return event->getStringValue().buffer();
}

void SpineEvent::set_string_value(const godot::String &v) {
	event->setStringValue(spine::String(v.utf8().get_data()));
}

float SpineEvent::get_volume() {
	return event->getVolume();
}

void SpineEvent::set_volume(float v) {
	event->setVolume(v);
}

float SpineEvent::get_balance() {
	return event->getBalance();
}

void SpineEvent::set_balance(float v) {
	event->setBalance(v);
}
