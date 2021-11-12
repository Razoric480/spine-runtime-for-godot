//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETON_H
#define GODOT_SPINESKELETON_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineBone.h"
#include "SpineSkeletonDataResource.h"
#include "SpineSlot.h"


class SpineSprite;

class SpineSkeleton : public godot::Reference {
	GODOT_CLASS(SpineSkeleton, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::Skeleton *skeleton;
	bool spine_object;

	SpineSprite *the_sprite;

public:
	SpineSkeleton();
	~SpineSkeleton();
	
	void _init();

	void load_skeleton(godot::Ref<SpineSkeletonDataResource> sd);

	inline void set_spine_object(spine::Skeleton *s) {
		skeleton = s;
		spine_object = true;
	}
	inline spine::Skeleton *get_spine_object() {
		return skeleton;
	}

	void set_spine_sprite(SpineSprite *s);

	void update_world_transform();

	void set_to_setup_pose();

	void set_bones_to_setup_pose();

	void set_slots_to_setup_pose();

	godot::Ref<SpineBone> find_bone(const godot::String &name);
	// int find_bone_index(const String &name);

	godot::Ref<SpineSlot> find_slot(const godot::String &name);
	// int find_slot_index(const String &name);

	void set_skin_by_name(const godot::String &skin_name);
	void set_skin(godot::Ref<SpineSkin> new_skin);

	godot::Ref<SpineAttachment> get_attachment_by_slot_name(const godot::String &slot_name, const godot::String &attachment_name);
	godot::Ref<SpineAttachment> get_attachment_by_slot_index(int slot_index, const godot::String &attachment_name);

	void set_attachment(const godot::String &slot_name, const godot::String &attachment_name);

	godot::Ref<SpineIkConstraint> find_ik_constraint(const godot::String &constraint_name);
	godot::Ref<SpineTransformConstraint> find_transform_constraint(const godot::String &constraint_name);
	godot::Ref<SpinePathConstraint> find_path_constraint(const godot::String &constraint_name);

	void update(float delta);

	godot::Dictionary get_bounds();

	godot::Ref<SpineBone> get_root_bone();

	godot::Ref<SpineSkeletonDataResource> get_data() const;

	godot::Array get_bones();
	godot::Array get_slots();
	godot::Array get_draw_orders();
	godot::Array get_ik_constraints();
	godot::Array get_path_constraints();
	godot::Array get_transform_constraints();

	godot::Ref<SpineSkin> get_skin();

	godot::Color get_color();
	void set_color(godot::Color v);

	float get_time();
	void set_time(float v);

	void set_position(godot::Vector2 pos);

	float get_x();
	void set_x(float v);

	float get_y();
	void set_y(float v);

	float get_scale_x();
	void set_scale_x(float v);

	float get_scale_y();
	void set_scale_y(float v);
};

#endif //GODOT_SPINESKELETON_H
