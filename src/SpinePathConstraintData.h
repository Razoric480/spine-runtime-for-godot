//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINEPATHCONSTRAINTDATA_H
#define GODOT_SPINEPATHCONSTRAINTDATA_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineConstraintData.h"
#include "SpineBoneData.h"
#include "SpineSlotData.h"

namespace godot {

class SpinePathConstraintData : public SpineConstraintData {
	GODOT_CLASS(SpinePathConstraintData, SpineConstraintData);

public:
	void _init();
	static void _register_methods();

public:
	SpinePathConstraintData();
	~SpinePathConstraintData();

	virtual inline spine::PathConstraintData *get_spine_data(){
		return (spine::PathConstraintData*) SpineConstraintData::get_spine_object();
	}

	enum PositionMode {
		POSITIONMODE_FIXED = 0,
		POSITIONMODE_PERCENT
	};

	enum SpacingMode {
		SPACINGMODE_LENGTH = 0,
		SPACINGMODE_FIXED,
		SPACINGMODE_PERCENT
	};

	enum RotateMode {
		ROTATEMODE_TANGENT = 0,
		ROTATEMODE_CHAIN,
		ROTATEMODE_CHAINSCALE
	};

	Array get_bones();

	Ref<SpineSlotData> get_target();
	void set_target(Ref<SpineSlotData> v);

	int get_position_mode();
	void set_position_mode(int v);

	int get_spacing_mode();
	void set_spacing_mode(int v);

	int get_rotate_mode();
	void set_rotate_mode(int v);

	float get_offset_rotation();
	void set_offset_rotation(float v);

	float get_position();
	void set_position(float v);

	float get_spacing();
	void set_spacing(float v);

	float get_mix_rotate();
	void set_mix_rotate(float v);

	float get_mix_x();
	void set_mix_x(float v);

	float get_mix_y();
	void set_mix_y(float v);
};

}

#endif //GODOT_SPINEPATHCONSTRAINTDATA_H
