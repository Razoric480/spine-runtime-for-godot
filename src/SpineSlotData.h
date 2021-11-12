//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINESLOTDATA_H
#define GODOT_SPINESLOTDATA_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineBoneData.h"

class SpineSlotData : public godot::Reference {
	GODOT_CLASS(SpineSlotData, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::SlotData *slot_data;

public:
	SpineSlotData();
	~SpineSlotData();

	inline void set_spine_object(spine::SlotData *s){
		slot_data = s;
	}
	inline spine::SlotData *get_spine_object(){
		return slot_data;
	}

	enum BlendMode {
		BLENDMODE_NORMAL = 0,
		BLENDMODE_ADDITIVE,
		BLENDMODE_MULTIPLY,
		BLENDMODE_SCREEN
	};

	int get_index();

	godot::String get_slot_name();

	godot::Ref<SpineBoneData> get_bone_data();

	godot::Color get_color();
	void set_color(godot::Color c);

	godot::Color get_dark_color();
	void set_dark_color(godot::Color c);

	bool has_dark_color();
	void set_has_dark_color(bool v);

	godot::String get_attachment_name();
	void set_attachment_name(const godot::String &v);

	BlendMode get_blend_mode();
	void set_blend_mode(BlendMode v);
};

#endif //GODOT_SPINESLOTDATA_H
