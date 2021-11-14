//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINECONSTRAINTDATA_H
#define GODOT_SPINECONSTRAINTDATA_H

#include <Godot.hpp>

#include <spine/spine.h>

namespace godot {

class SpineConstraintData : public Reference {
	GODOT_CLASS(SpineConstraintData, Reference);

public:
	void _init();

protected:
public:
	static void _register_methods();

private:
	spine::ConstraintData *constraint_data;

public:
	SpineConstraintData();
	~SpineConstraintData();

	inline void set_spine_object(spine::ConstraintData *c) {
		constraint_data = c;
	}
	virtual inline spine::ConstraintData *get_spine_object() {
		return constraint_data;
	}

	String get_constraint_data_name();

	uint64_t get_order();
	void set_order(uint64_t v);

	bool is_skin_required();
	void set_skin_required(bool v);
};

} //namespace godot

#endif //GODOT_SPINECONSTRAINTDATA_H
