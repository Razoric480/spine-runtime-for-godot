//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESKELETONDATARESOURCE_H
#define GODOT_SPINESKELETONDATARESOURCE_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineAnimation.h"
#include "SpineAtlasResource.h"
#include "SpineBoneData.h"
#include "SpineEventData.h"
#include "SpineIkConstraintData.h"
#include "SpinePathConstraintData.h"
#include "SpineSkeletonJsonDataResource.h"
#include "SpineSkin.h"
#include "SpineSlotData.h"
#include "SpineTransformConstraintData.h"


class SpineSkeletonDataResource : public godot::Resource {
	GODOT_CLASS(SpineSkeletonDataResource, godot::Resource);

protected:
	static void _register_methods();

private:
	godot::Ref<SpineAtlasResource> atlas_res;
	godot::Ref<SpineSkeletonJsonDataResource> skeleton_json_res;
	bool valid;
	bool spine_object;

	spine::SkeletonData *skeleton_data;

	void update_skeleton_data();

public:
	void _init();

	inline void set_spine_object(spine::SkeletonData *s) {
		skeleton_data = s;
		if (s)
			spine_object = true;
	}
	inline spine::SkeletonData *get_spine_object() {
		return skeleton_data;
	}

	void load_res(spine::Atlas *a, const godot::String &json_path);

	SpineSkeletonDataResource();
	virtual ~SpineSkeletonDataResource();

	godot::Array _get_property_list() const;

	void set_atlas_res(godot::Ref<SpineAtlasResource> a);
	godot::Ref<SpineAtlasResource> get_atlas_res();

	void set_skeleton_json_res(godot::Ref<SpineSkeletonJsonDataResource> s);
	godot::Ref<SpineSkeletonJsonDataResource> get_skeleton_json_res();

	inline spine::SkeletonData *get_skeleton_data() { return skeleton_data; }

	bool is_skeleton_data_loaded() const;

	void get_animation_names(godot::PoolStringArray &l) const;
	void get_skin_names(godot::PoolStringArray &l) const;

	// spine api
	godot::Ref<SpineBoneData> find_bone(const godot::String &bone_name);

	// int find_bone_index(const String &bone_name);

	godot::Ref<SpineSlotData> find_slot(const godot::String &slot_name);

	// int find_slot_index(const String &slot_name);

	godot::Ref<SpineSkin> find_skin(const godot::String &skin_name);

	godot::Ref<SpineEventData> find_event(const godot::String &event_data_name);

	godot::Ref<SpineAnimation> find_animation(const godot::String &animation_name);

	godot::Ref<SpineIkConstraintData> find_ik_constraint(const godot::String &constraint_name);
	godot::Ref<SpineTransformConstraintData> find_transform_constraint(const godot::String &constraint_name);
	godot::Ref<SpinePathConstraintData> find_path_constraint(const godot::String &constraint_name);

	// int find_path_constraint_index(const String &path_constraint_name);

	godot::Array get_bones();
	godot::Array get_slots();
	godot::Array get_skins() const;

	godot::Ref<SpineSkin> get_default_skin();
	void set_default_skin(godot::Ref<SpineSkin> v);

	godot::Array get_events();
	godot::Array get_animations();
	godot::Array get_ik_constraints();
	godot::Array get_transform_constraints();
	godot::Array get_path_constraints();

	godot::String get_sk_name();
	void set_sk_name(const godot::String &v);

	float get_x();
	void set_x(float v);

	float get_y();
	void set_y(float v);

	float get_width();
	float get_height();

	godot::String get_version();

	float get_fps();
	void set_fps(float v);
};

#endif //GODOT_SPINESKELETONDATARESOURCE_H
