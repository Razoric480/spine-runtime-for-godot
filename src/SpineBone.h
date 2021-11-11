//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINEBONE_H
#define GODOT_SPINEBONE_H

#include <Godot.hpp>
#include <spine/spine.h>

#include "SpineBoneData.h"
#include "SpineIkConstraint.h"
#include "SpinePathConstraint.h"
#include "SpineTransformConstraint.h"

class SpineSkeleton;
class SpineSprite;

class SpineBone : public godot::Reference {
	GODOT_CLASS(SpineBone, godot::Reference);

protected:
	static void _bind_methods();

private:
	spine::Bone *bone;

	SpineSprite *the_sprite;
public:
	SpineBone();
	~SpineBone();

	inline void set_spine_object(spine::Bone *b){
		bone = b;
	}
	inline spine::Bone *get_spine_object(){
		return bone;
	}

	void set_spine_sprite(SpineSprite *s);

	void update_world_transform();

	void set_to_setup_pose();

	godot::Vector2 world_to_local(godot::Vector2 world_position);

	godot::Vector2 local_to_world(godot::Vector2 local_position);

	float world_to_local_rotation(float world_rotation);

	float local_to_world_rotation(float local_rotation);

	void rotate_world(float degrees);

	float get_world_to_local_rotation_x();
	float get_world_to_local_rotation_y();

	godot::Ref<SpineBoneData> get_data();

	godot::Ref<SpineSkeleton> get_skeleton();

	godot::Ref<SpineBone> get_parent();

	godot::Array get_children();

	float get_x();
	void set_x(float v);

	float get_y();
	void set_y(float v);

	float get_rotation();
	void set_rotation(float v);

	float get_scale_x();
	void set_scale_x(float v);

	float get_scale_y();
	void set_scale_y(float v);

	float get_shear_x();
	void set_shear_x(float v);

	float get_shear_y();
	void set_shear_y(float v);

	float get_applied_rotation();
	void set_applied_rotation(float v);

	float get_a_x();
	void set_a_x(float v);

	float get_a_y();
	void set_a_y(float v);

	float get_a_scale_x();
	void set_a_scale_x(float v);

	float get_a_scale_y();
	void set_a_scale_y(float v);

	float get_a_shear_x();
	void set_a_shear_x(float v);

	float get_a_shear_y();
	void set_a_shear_y(float v);

	float get_a();
	void set_a(float v);

	float get_b();
	void set_b(float v);

	float get_c();
	void set_c(float v);

	float get_d();
	void set_d(float v);

	float get_world_x();
	void set_world_x(float v);

	float get_world_y();
	void set_world_y(float v);

	float get_world_rotation_x();
	float get_world_rotation_y();

	float get_world_scale_x();
	float get_world_scale_y();

	bool is_active();
	void set_active(bool v);

	// External feature functions
	void apply_world_transform_2d(godot::Variant o);

	godot::Transform2D get_godot_transform();
	void set_godot_transform(godot::Transform2D trans);

	godot::Transform2D get_godot_global_transform();
	void set_godot_global_transform(godot::Transform2D trans);
};

#endif //GODOT_SPINEBONE_H
