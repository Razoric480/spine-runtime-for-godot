//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINEPATHCONSTRAINTDATA_H
#define GODOT_SPINEPATHCONSTRAINTDATA_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineConstraintData.h"
#include "SpineBoneData.h"
#include "SpineSlotData.h"

class SpinePathConstraintData : public SpineConstraintData {
	GODOT_CLASS(SpinePathConstraintData, SpineConstraintData);

protected:
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

	godot::Array get_bones();

	godot::Ref<SpineSlotData> get_target();
	void set_target(godot::Ref<SpineSlotData> v);

	PositionMode get_position_mode();
	void set_position_mode(PositionMode v);

	SpacingMode get_spacing_mode();
	void set_spacing_mode(SpacingMode v);

	RotateMode get_rotate_mode();
	void set_rotate_mode(RotateMode v);

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

#endif //GODOT_SPINEPATHCONSTRAINTDATA_H
