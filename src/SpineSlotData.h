//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINESLOTDATA_H
#define GODOT_SPINESLOTDATA_H
#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineBoneData.h"

namespace godot {

class SpineSlotData : public Reference {
	GODOT_CLASS(SpineSlotData, Reference);

public:
	void _init();

protected:
	
public:
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

	String get_slot_name();

	Ref<SpineBoneData> get_bone_data();

	Color get_color();
	void set_color(Color c);

	Color get_dark_color();
	void set_dark_color(Color c);

	bool has_dark_color();
	void set_has_dark_color(bool v);

	String get_attachment_name();
	void set_attachment_name(const String &v);

	int get_blend_mode();
	void set_blend_mode(int v);
};

}

#endif //GODOT_SPINESLOTDATA_H
