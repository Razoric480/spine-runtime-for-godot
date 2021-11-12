//
// Created by Raymond_Lx on 2020/6/4.
//

#ifndef GODOT_SPINEEVENT_H
#define GODOT_SPINEEVENT_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineEventData.h"

class SpineEvent : public godot::Reference {
	GODOT_CLASS(SpineEvent, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::Event *event;

public:
	SpineEvent();
	~SpineEvent();

	void _init();

	inline void set_spine_object(spine::Event *e) {
		event = e;
	}
	inline spine::Event *get_spine_object() const {
		return event;
	}

	enum EventType {
		EVENTTYPE_START = spine::EventType_Start,
		EVENTTYPE_INTERRUPT = spine::EventType_Interrupt,
		EVENTTYPE_END = spine::EventType_End,
		EVENTTYPE_COMPLETE = spine::EventType_Complete,
		EVENTTYPE_DISPOSE = spine::EventType_Dispose,
		EVENTTYPE_EVENT = spine::EventType_Event
	};

	godot::Ref<SpineEventData> get_data();

	godot::String get_event_name();

	float get_time();

	int get_int_value();
	void set_int_value(int inValue);

	float get_float_value();
	void set_float_value(float inValue);

	godot::String get_string_value();
	void set_string_value(const godot::String &inValue);

	float get_volume();
	void set_volume(float inValue);

	float get_balance();
	void set_balance(float inValue);
};

#endif //GODOT_SPINEEVENT_H
