//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINESLOT_H
#define GODOT_SPINESLOT_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineAttachment.h"
#include "SpineSlotData.h"


class SpineSkeleton;

class SpineBone;

class SpineSlot : public godot::Reference {
	GODOT_CLASS(SpineSlot, godot::Reference);

public:
	static void _register_methods();

private:
	spine::Slot *slot;

public:
	SpineSlot();
	~SpineSlot();

	void _init();

	inline void set_spine_object(spine::Slot *s) {
		slot = s;
	}
	inline spine::Slot *get_spine_object() {
		return slot;
	}

	void set_to_setup_pos();

	godot::Ref<SpineSlotData> get_data();

	godot::Ref<SpineBone> get_bone();

	godot::Ref<SpineSkeleton> get_skeleton();

	godot::Color get_color();
	void set_color(godot::Color v);

	godot::Color get_dark_color();
	void set_dark_color(godot::Color v);

	bool has_dark_color();

	godot::Ref<SpineAttachment> get_attachment();
	void set_attachment(godot::Ref<SpineAttachment> v);

	int get_attachment_state();
	void set_attachment_state(int v);

	float get_attachment_time();
	void set_attachment_time(float v);

	godot::Array get_deform();
	void set_deform(godot::Array v);
};

#endif //GODOT_SPINESLOT_H
