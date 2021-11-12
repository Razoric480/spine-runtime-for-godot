//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINEANIMATIONSTATE_H
#define GODOT_SPINEANIMATIONSTATE_H

#include <Godot.hpp>

#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineTrackEntry.h"

class SpineAnimationState : public godot::Reference {
	GODOT_CLASS(SpineAnimationState, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::AnimationState *animation_state;

	godot::Ref<SpineAnimationStateDataResource> anim_state_data_res;

public:
	void load_animation_state(godot::Ref<SpineAnimationStateDataResource> ad);

	inline void set_animation_state(spine::AnimationState *a) {
		animation_state = a;
	}
	inline spine::AnimationState *get_animation_state() {
		return animation_state;
	}

	void reload_animation_state();

	godot::Ref<SpineTrackEntry> set_animation(const godot::String &anim_name, bool loop, uint64_t track_id);
	inline void set_animation_by_ref(godot::Ref<SpineAnimation> anim, bool loop, uint64_t track_id) {
		if (anim.is_valid()) {
			animation_state->setAnimation(track_id, anim->get_spine_object(), loop);
		}
	}
	godot::Ref<SpineTrackEntry> add_animation(const godot::String &anim_name, float delay, bool loop, uint64_t track_id);

	godot::Ref<SpineTrackEntry> set_empty_animation(uint64_t track_id, float mix_duration);
	godot::Ref<SpineTrackEntry> add_empty_animation(uint64_t track_id, float mix_duration, float delay);
	void set_empty_animations(float mix_duration);

	godot::Ref<SpineAnimationStateDataResource> get_data();

	float get_time_scale();
	void set_time_scale(float v);

	void disable_queue();
	void enable_queue();

	void update(float delta);
	bool apply(godot::Ref<SpineSkeleton> skeleton);

	void clear_tracks();
	void clear_track(uint64_t track_id);

	godot::Ref<SpineTrackEntry> get_current(uint64_t track_index);

	SpineAnimationState();
	~SpineAnimationState();
};

#endif //GODOT_SPINEANIMATIONSTATE_H
