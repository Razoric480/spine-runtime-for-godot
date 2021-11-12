//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineAnimationState.h"

void SpineAnimationState::_register_methods() {
	godot::register_method("set_animation", &SpineAnimationState::set_animation);
	godot::register_method("update", &SpineAnimationState::update);
	godot::register_method("apply", &SpineAnimationState::apply);
	godot::register_method("clear_tracks", &SpineAnimationState::clear_tracks);
	godot::register_method("clear_track", &SpineAnimationState::clear_track);
	godot::register_method("add_animation", &SpineAnimationState::add_animation);
	godot::register_method("set_empty_animation", &SpineAnimationState::set_empty_animation);
	godot::register_method("add_empty_animation", &SpineAnimationState::add_empty_animation);
	godot::register_method("set_empty_animations", &SpineAnimationState::set_empty_animations);
	godot::register_method("get_data", &SpineAnimationState::get_data);
	godot::register_method("get_time_scale", &SpineAnimationState::get_time_scale);
	godot::register_method("set_time_scale", &SpineAnimationState::set_time_scale);
	godot::register_method("disable_queue", &SpineAnimationState::disable_queue);
	godot::register_method("enable_queue", &SpineAnimationState::enable_queue);
	//	godot::register_method("reload"), &SpineAnimationState::reload_animation_state);
	godot::register_method("get_current", &SpineAnimationState::get_current);
}

void SpineAnimationState::_init() {
	animation_state = nullptr;
}

SpineAnimationState::SpineAnimationState() {
}

SpineAnimationState::~SpineAnimationState() {
	if (animation_state) {
		delete animation_state;
		animation_state = nullptr;
	}
}

void SpineAnimationState::load_animation_state(godot::Ref<SpineAnimationStateDataResource> ad) {
	if (animation_state) {
		delete animation_state;
		animation_state = nullptr;
	}
	animation_state = new spine::AnimationState(ad->get_animation_state_data());
	anim_state_data_res = ad;
}

void SpineAnimationState::reload_animation_state() {
	if (!anim_state_data_res.is_valid()) {
		ERR_PRINT(" Reload animation state fail, because anim_state_data_res not set!");
		return;
	}
	if (animation_state) {
		delete animation_state;
		animation_state = nullptr;
	}
	animation_state = new spine::AnimationState(anim_state_data_res->get_animation_state_data());
}

#define CHECK_V                                              \
	if (!animation_state) {                                  \
		ERR_PRINT("The animation state is not loaded yet!"); \
		return;                                              \
	}
	
#define CHECK_X(x)                                           \
	if (!animation_state) {                                  \
		ERR_PRINT("The animation state is not loaded yet!"); \
		return x;                                            \
	}
	
#define S_T(x) (spine::String(x.utf8()))

godot::Ref<SpineTrackEntry> SpineAnimationState::set_animation(const godot::String &anim_name, bool loop, uint64_t track) {
	CHECK_X(NULL);
	auto skeleton_data = anim_state_data_res->get_skeleton();
	auto anim = skeleton_data->find_animation(anim_name);
	if (!anim.is_valid() || anim->get_spine_object() == NULL) {
		ERR_PRINT(godot::String("Can not find animation: ") + anim_name);
		return nullptr;
	}
	auto entry = animation_state->setAnimation(track, anim->get_spine_object(), loop);
	godot::Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

godot::Ref<SpineTrackEntry> SpineAnimationState::add_animation(const godot::String &anim_name, float delay, bool loop, uint64_t track) {
	CHECK_X(NULL);
	auto skeleton_data = anim_state_data_res->get_skeleton();
	auto anim = skeleton_data->find_animation(anim_name);
	if (!anim.is_valid() || anim->get_spine_object() == NULL) {
		ERR_PRINT(godot::String("Can not find animation: ") + anim_name);
		return nullptr;
	}
	auto entry = animation_state->addAnimation(track, anim->get_spine_object(), loop, delay);
	godot::Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

godot::Ref<SpineTrackEntry> SpineAnimationState::set_empty_animation(uint64_t track_id, float mix_duration) {
	CHECK_X(NULL);
	auto entry = animation_state->setEmptyAnimation(track_id, mix_duration);
	godot::Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

godot::Ref<SpineTrackEntry> SpineAnimationState::add_empty_animation(uint64_t track_id, float mix_duration, float delay) {
	CHECK_X(NULL);
	auto entry = animation_state->addEmptyAnimation(track_id, mix_duration, delay);
	godot::Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

void SpineAnimationState::set_empty_animations(float mix_duration) {
	CHECK_V;
	animation_state->setEmptyAnimations(mix_duration);
}

void SpineAnimationState::update(float delta) {
	CHECK_V;
	animation_state->update(delta);
}

bool SpineAnimationState::apply(godot::Ref<SpineSkeleton> skeleton) {
	CHECK_X(false);
	return animation_state->apply(*(skeleton->get_spine_object()));
}

void SpineAnimationState::clear_tracks() {
	CHECK_V;
	animation_state->clearTracks();
}

void SpineAnimationState::clear_track(uint64_t track_id) {
	CHECK_V;
	animation_state->clearTrack(track_id);
}

godot::Ref<SpineAnimationStateDataResource> SpineAnimationState::get_data() {
	CHECK_X(NULL);
	return anim_state_data_res;
}

float SpineAnimationState::get_time_scale() {
	CHECK_X(0);
	return animation_state->getTimeScale();
}

void SpineAnimationState::set_time_scale(float v) {
	CHECK_V;
	animation_state->setTimeScale(v);
}

void SpineAnimationState::disable_queue() {
	CHECK_V;
	animation_state->disableQueue();
}

void SpineAnimationState::enable_queue() {
	CHECK_V;
	animation_state->enableQueue();
}

godot::Ref<SpineTrackEntry> SpineAnimationState::get_current(uint64_t track_index) {
	CHECK_X(NULL);
	godot::Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	auto entry = animation_state->getCurrent(track_index);
	if (entry == NULL)
		return NULL;
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

#undef CHECK_V
#undef CHECK_X
