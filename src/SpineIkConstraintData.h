//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINEIKCONSTRAINTDATA_H
#define GODOT_SPINEIKCONSTRAINTDATA_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineConstraintData.h"
#include "SpineBoneData.h"

class SpineIkConstraintData : public SpineConstraintData {
	GODOT_CLASS(SpineIkConstraintData, SpineConstraintData);

protected:
	static void _register_methods();

public:
	SpineIkConstraintData();
	~SpineIkConstraintData();

	virtual inline spine::IkConstraintData *get_spine_data(){
		return (spine::IkConstraintData*) SpineConstraintData::get_spine_object();
	}

	godot::Array get_bones();

	godot::Ref<SpineBoneData> get_target();
	void set_target(godot::Ref<SpineBoneData> v);

	int get_bend_direction();
	void set_bend_direction(int v);

	bool get_compress();
	void set_compress(bool v);

	bool get_stretch();
	void set_stretch(bool v);

	bool get_uniform();
	void set_uniform(bool v);

	float get_mix();
	void set_mix(float v);

	float get_softness();
	void set_softness(float v);

};

#endif //GODOT_SPINEIKCONSTRAINTDATA_H
