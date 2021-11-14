//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESPRITE_H
#define GODOT_SPINESPRITE_H

#include <Godot.hpp>

#include "PackedSpineSkinResource.h"
#include "SpineAnimationState.h"
#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineSpriteMeshInstance2D.h"

namespace godot {

class SpineSprite : public Node2D, public spine::AnimationStateListenerObject {
	GODOT_CLASS(SpineSprite, Node2D);

public:
	void _init();
	static void _register_methods();

	void _notification(int p_what);

	Array _get_property_list();
	bool _set(const String property, const Variant value);
	Variant _get(const String property) const;

	void _validate_and_play_current_animations();

public:
	enum ProcessMode {
		ProcessMode_Process,
		ProcessMode_Physics,
		ProcessMode_Manual
	};

private:
	Ref<SpineAnimationStateDataResource> animation_state_data_res;

	Ref<SpineSkeleton> skeleton;
	Ref<SpineAnimationState> animation_state;

	Array mesh_instances;

	Array current_animations;
	int select_track_id;
	float empty_animation_duration;

	Array bind_slot_nodes;
	bool overlap;
	Ref<PackedSpineSkinResource> skin;

	ProcessMode process_mode;

	spine::SkeletonClipping *skeleton_clipper;

public:
	SpineSprite();
	~SpineSprite();

	void set_animation_state_data_res(Ref<SpineAnimationStateDataResource> a);
	Ref<SpineAnimationStateDataResource> get_animation_state_data_res();

	Ref<SpineSkeleton> get_skeleton();
	Ref<SpineAnimationState> get_animation_state();

	void gen_mesh_from_skeleton(Ref<SpineSkeleton> s);
	void remove_mesh_instances();
	void remove_redundant_mesh_instances();

	void update_mesh_from_skeleton(Ref<SpineSkeleton> s);

	void update_bind_slot_nodes();
	void update_bind_slot_node_transform(Ref<SpineBone> bone, Node2D *node2d);
	void update_bind_slot_node_draw_order(const String &slot_name, Node2D *node2d);
	Node *find_child_node_by_node(Node *node);

	virtual void callback(spine::AnimationState *state, spine::EventType type, spine::TrackEntry *entry, spine::Event *event);

	void _on_animation_data_created();
	void _on_animation_data_changed();

	void _update_all(float delta);

	// External feature functions
	Array get_current_animations();
	void set_current_animations(Array as);

	int get_select_track_id();
	void set_select_track_id(int v);

	bool get_clear_track();
	void set_clear_track(bool v);

	bool get_clear_tracks();
	void set_clear_tracks(bool v);

	float get_empty_animation_duration();
	void set_empty_animation_duration(float v);

	bool get_set_empty_animation();
	void set_set_empty_animation(bool v);

	bool get_set_empty_animations();
	void set_set_empty_animations(bool v);

	Array get_bind_slot_nodes();
	void set_bind_slot_nodes(Array v);

	void bind_slot_with_node_2d(const String &slot_name, Node2D *n);
	void unbind_slot_with_node_2d(const String &slot_name, Node2D *n);

	// bone manipulations
	Transform2D bone_get_global_transform(const String &bone_name);
	void bone_set_global_transform(const String &bone_name, Transform2D transform);

	//allow z-manipulation
	bool get_overlap();
	void set_overlap(bool v);

	void set_skin(Ref<PackedSpineSkinResource> v);
	Ref<PackedSpineSkinResource> get_skin();
	void _on_skin_property_changed();
	void update_runtime_skin();

	Ref<SpineSkin> gen_spine_skin_from_packed_resource(Ref<PackedSpineSkinResource> res);

	// current animation count
	int64_t get_current_animation_count() const;
	void set_current_animation_count(int64_t v);

	int get_process_mode();
	void set_process_mode(int v);
};

} //namespace godot

#endif //GODOT_SPINESPRITE_H
