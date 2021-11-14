//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineEvent.h"

namespace godot {

void SpineEvent::_register_methods() {
	register_method("get_data", &SpineEvent::get_data);
	register_method("get_event_name", &SpineEvent::get_event_name);
	register_method("get_time", &SpineEvent::get_time);
	register_method("get_int_value", &SpineEvent::get_int_value);
	register_method("set_int_value", &SpineEvent::set_int_value);
	register_method("get_float_value", &SpineEvent::get_float_value);
	register_method("set_float_value", &SpineEvent::set_float_value);
	register_method("get_string_value", &SpineEvent::get_string_value);
	register_method("set_string_value", &SpineEvent::set_string_value);
	register_method("get_volume", &SpineEvent::get_volume);
	register_method("set_volume", &SpineEvent::set_volume);
	register_method("get_balance", &SpineEvent::get_balance);
	register_method("set_balance", &SpineEvent::set_balance);
	//
	//	BIND_ENUM_CONSTANT(EVENTTYPE_START);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_INTERRUPT);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_END);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_COMPLETE);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_DISPOSE);
	//	BIND_ENUM_CONSTANT(EVENTTYPE_EVENT);
}

SpineEvent::SpineEvent() {}
SpineEvent::~SpineEvent() {}

void SpineEvent::_init() {
	event = nullptr;
}

Ref<SpineEventData> SpineEvent::get_data() {
	Ref<SpineEventData> event_data;
	event_data.instance();
	event_data->set_spine_object(&(event->getData()));
	return event_data;
}

String SpineEvent::get_event_name() {
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

String SpineEvent::get_string_value() {
	return event->getStringValue().buffer();
}

void SpineEvent::set_string_value(const String &v) {
	event->setStringValue(spine::String(v.alloc_c_string()));
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

} //namespace godot