//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINEPATHCONSTRAINT_H
#define GODOT_SPINEPATHCONSTRAINT_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineBone.h"
#include "SpinePathConstraintData.h"
#include "SpineSlot.h"


class SpinePathConstraint : public godot::Reference {
	GODOT_CLASS(SpinePathConstraint, godot::Reference);

public:
	static void _register_methods();

private:
	spine::PathConstraint *path_constraint;

public:
	SpinePathConstraint();
	~SpinePathConstraint();

	inline void set_spine_object(spine::PathConstraint *pc) {
		path_constraint = pc;
	}
	inline spine::PathConstraint *get_spine_object() {
		return path_constraint;
	}

	void _init();

	// The spine-runtime-cpp 4.0 seems to not have a apply function implementation.
	// void apply();

	void update();

	int get_order();

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

	godot::Array get_bones();

	godot::Ref<SpineSlot> get_target();
	void set_target(godot::Ref<SpineSlot> v);

	godot::Ref<SpinePathConstraintData> get_data();

	bool is_active();
	void set_active(bool v);
};

#endif //GODOT_SPINEPATHCONSTRAINT_H
