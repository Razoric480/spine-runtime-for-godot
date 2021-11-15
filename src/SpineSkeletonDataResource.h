//
// Created by Raymond_Lx on 2020/6/2.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINESKELETONDATARESOURCE_H
#define GODOT_SPINESKELETONDATARESOURCE_H

#include <Godot.hpp>
#include <Resource.hpp>

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

namespace godot {

class SpineSkeletonDataResource : public Resource {
	GODOT_CLASS(SpineSkeletonDataResource, Resource);

public:
	void _init();

protected:
public:
	static void _register_methods();

private:
	Ref<SpineAtlasResource> atlas_res;
	Ref<SpineSkeletonJsonDataResource> skeleton_json_res;
	bool valid;
	bool spine_object;

	spine::SkeletonData *skeleton_data;

	void update_skeleton_data();

public:
	inline void set_spine_object(spine::SkeletonData *s) {
		skeleton_data = s;
		if (s)
			spine_object = true;
	}
	inline spine::SkeletonData *get_spine_object() {
		return skeleton_data;
	}

	void load_res(spine::Atlas *a, const String &json_path);

	SpineSkeletonDataResource();
	virtual ~SpineSkeletonDataResource();

	Array _get_property_list();

	void set_atlas_res(Ref<SpineAtlasResource> a);
	Ref<SpineAtlasResource> get_atlas_res();

	void set_skeleton_json_res(Ref<SpineSkeletonJsonDataResource> s);
	Ref<SpineSkeletonJsonDataResource> get_skeleton_json_res();

	inline spine::SkeletonData *get_skeleton_data() { return skeleton_data; }

	bool is_skeleton_data_loaded() const;

	Array get_animation_names();
	Array get_skin_names();

	// spine api
	Ref<SpineBoneData> find_bone(const String &bone_name);

	// int find_bone_index(const String &bone_name);

	Ref<SpineSlotData> find_slot(const String &slot_name);

	// int find_slot_index(const String &slot_name);

	Ref<SpineSkin> find_skin(const String &skin_name);

	Ref<SpineEventData> find_event(const String &event_data_name);

	Ref<SpineAnimation> find_animation(const String &animation_name);

	Ref<SpineIkConstraintData> find_ik_constraint(const String &constraint_name);
	Ref<SpineTransformConstraintData> find_transform_constraint(const String &constraint_name);
	Ref<SpinePathConstraintData> find_path_constraint(const String &constraint_name);

	// int find_path_constraint_index(const String &path_constraint_name);

	Array get_bones();
	Array get_slots();
	Array get_skins() const;

	Ref<SpineSkin> get_default_skin();
	void set_default_skin(Ref<SpineSkin> v);

	Array get_events();
	Array get_animations();
	Array get_ik_constraints();
	Array get_transform_constraints();
	Array get_path_constraints();

	String get_sk_name();
	void set_sk_name(const String &v);

	float get_x();
	void set_x(float v);

	float get_y();
	void set_y(float v);

	float get_width();
	float get_height();

	String get_version();

	float get_fps();
	void set_fps(float v);
};

} //namespace godot

#endif //GODOT_SPINESKELETONDATARESOURCE_H
