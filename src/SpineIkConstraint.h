//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINEIKCONSTRAINT_H
#define GODOT_SPINEIKCONSTRAINT_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineIkConstraintData.h"

class SpineBone;

class SpineIkConstraint : public godot::Reference {
	GODOT_CLASS(SpineIkConstraint, godot::Reference);

public:
	static void _register_methods();

private:
	spine::IkConstraint *ik_constraint;

public:
	SpineIkConstraint();
	~SpineIkConstraint();
	
	void _init();

	inline void set_spine_object(spine::IkConstraint * ic){
		ik_constraint = ic;
	}
	inline spine::IkConstraint *get_spine_object(){
		return ik_constraint;
	}

	// The spine-runtime-cpp 4.0 seems to not have a apply function implementation.
	// void apply(); 

	void update();

	int get_order();

	godot::Ref<SpineIkConstraintData> get_data();

	godot::Array get_bones();

	godot::Ref<SpineBone> get_target();
	void set_target(godot::Ref<SpineBone> v);

	int get_bend_direction();
	void set_bend_direction(int v);

	bool get_compress();
	void set_compress(bool v);

	bool get_stretch();
	void set_stretch(bool v);

	float get_mix();
	void set_mix(float v);

	float get_softness();
	void set_softness(float v);

	bool is_active();
	void set_active(bool v);

};

#endif //GODOT_SPINEIKCONSTRAINT_H
