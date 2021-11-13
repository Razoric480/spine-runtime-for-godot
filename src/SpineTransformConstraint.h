//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINETRANSFORMCONSTRAINT_H
#define GODOT_SPINETRANSFORMCONSTRAINT_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineBone.h"
#include "SpineTransformConstraintData.h"


class SpineTransformConstraint : public godot::Reference {
	GODOT_CLASS(SpineTransformConstraint, godot::Reference);

public:
	static void _register_methods();

private:
	spine::TransformConstraint *transform_constraint;

public:
	SpineTransformConstraint();
	~SpineTransformConstraint();

	void _init();

	inline void set_spine_object(spine::TransformConstraint *tc) {
		transform_constraint = tc;
	}
	inline spine::TransformConstraint *get_spine_object() {
		return transform_constraint;
	}

	void update();

	int get_order();

	godot::Ref<SpineTransformConstraintData> get_data();

	godot::Array get_bones();

	godot::Ref<SpineBone> get_target();
	void set_target(godot::Ref<SpineBone> v);

	float get_mix_rotate();
	void set_mix_rotate(float v);

	float get_mix_x();
	void set_mix_x(float v);

	float get_mix_y();
	void set_mix_y(float v);

	float get_mix_scale_x();
	void set_mix_scale_x(float v);

	float get_mix_scale_y();
	void set_mix_scale_y(float v);

	float get_mix_shear_y();
	void set_mix_shear_y(float v);

	bool is_active();
	void set_active(bool v);
};

#endif //GODOT_SPINETRANSFORMCONSTRAINT_H
