//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineTrackEntry.h"

namespace godot {

void SpineTrackEntry::_register_methods() {
	register_method("get_track_index", &SpineTrackEntry::get_track_index);

	register_method("get_animation", &SpineTrackEntry::get_animation);

	register_method("get_loop", &SpineTrackEntry::get_loop);
	register_method("set_loop", &SpineTrackEntry::set_loop);

	register_method("get_hold_previous", &SpineTrackEntry::get_hold_previous);
	register_method("set_hold_previous", &SpineTrackEntry::set_hold_previous);

	register_method("get_reverse", &SpineTrackEntry::get_reverse);
	register_method("set_reverse", &SpineTrackEntry::set_reverse);

	register_method("get_delay", &SpineTrackEntry::get_delay);
	register_method("set_delay", &SpineTrackEntry::set_delay);

	register_method("get_track_time", &SpineTrackEntry::get_track_time);
	register_method("set_track_time", &SpineTrackEntry::set_track_time);

	register_method("get_track_end", &SpineTrackEntry::get_track_end);
	register_method("set_track_end", &SpineTrackEntry::set_track_end);

	register_method("get_animation_start", &SpineTrackEntry::get_animation_start);
	register_method("set_animation_start", &SpineTrackEntry::set_animation_start);

	register_method("get_animation_last", &SpineTrackEntry::get_animation_last);
	register_method("set_animation_last", &SpineTrackEntry::set_animation_last);

	register_method("get_animation_time", &SpineTrackEntry::get_animation_time);

	register_method("get_time_scale", &SpineTrackEntry::get_time_scale);
	register_method("set_time_scale", &SpineTrackEntry::set_time_scale);

	register_method("get_alpha", &SpineTrackEntry::get_alpha);
	register_method("set_alpha", &SpineTrackEntry::set_alpha);

	register_method("get_event_threshold", &SpineTrackEntry::get_event_threshold);
	register_method("set_event_threshold", &SpineTrackEntry::set_event_threshold);

	register_method("get_attachment_threshold", &SpineTrackEntry::get_attachment_threshold);
	register_method("set_attachment_threshold", &SpineTrackEntry::set_attachment_threshold);

	register_method("get_draw_order_threshold", &SpineTrackEntry::get_draw_order_threshold);
	register_method("set_draw_order_threshold", &SpineTrackEntry::set_draw_order_threshold);

	register_method("get_next", &SpineTrackEntry::get_next);

	register_method("is_complete", &SpineTrackEntry::is_complete);

	register_method("get_mix_time", &SpineTrackEntry::get_mix_time);
	register_method("set_mix_time", &SpineTrackEntry::set_mix_time);

	register_method("get_mix_duration", &SpineTrackEntry::get_mix_duration);
	register_method("set_mix_duration", &SpineTrackEntry::set_mix_duration);

	register_method("get_mix_blend", &SpineTrackEntry::get_mix_blend);
	register_method("set_mix_blend", &SpineTrackEntry::set_mix_blend);

	register_method("get_mixing_from", &SpineTrackEntry::get_mixing_from);
	register_method("get_mixing_to", &SpineTrackEntry::get_mixing_to);

	register_method("reset_rotation_directions", &SpineTrackEntry::reset_rotation_directions);
}

SpineTrackEntry::SpineTrackEntry() {}
SpineTrackEntry::~SpineTrackEntry() {}

void SpineTrackEntry::_init() {
	track_entry = nullptr;
}

int SpineTrackEntry::get_track_index() {
	return track_entry->getTrackIndex();
}

Ref<SpineAnimation> SpineTrackEntry::get_animation() {
	Ref<SpineAnimation> gd_anim;
	gd_anim.instance();
	auto anim = track_entry->getAnimation();
	if (anim == NULL)
		return NULL;
	gd_anim->set_spine_object(anim);
	return gd_anim;
}

bool SpineTrackEntry::get_loop() {
	return track_entry->getLoop();
}

void SpineTrackEntry::set_loop(bool v) {
	track_entry->setLoop(v);
}

bool SpineTrackEntry::get_hold_previous() {
	return track_entry->getHoldPrevious();
}

void SpineTrackEntry::set_hold_previous(bool v) {
	track_entry->setHoldPrevious(v);
}

float SpineTrackEntry::get_delay() {
	return track_entry->getDelay();
}

void SpineTrackEntry::set_delay(float v) {
	track_entry->setDelay(v);
}

float SpineTrackEntry::get_track_time() {
	return track_entry->getTrackTime();
}

void SpineTrackEntry::set_track_time(float v) {
	track_entry->setTrackTime(v);
}

float SpineTrackEntry::get_track_end() {
	return track_entry->getTrackEnd();
}

void SpineTrackEntry::set_track_end(float v) {
	track_entry->setTrackEnd(v);
}

float SpineTrackEntry::get_animation_start() {
	return track_entry->getAnimationStart();
}

void SpineTrackEntry::set_animation_start(float v) {
	track_entry->setAnimationStart(v);
}

float SpineTrackEntry::get_animation_last() {
	return track_entry->getAnimationLast();
}

void SpineTrackEntry::set_animation_last(float v) {
	track_entry->setAnimationLast(v);
}

float SpineTrackEntry::get_animation_time() {
	return track_entry->getAnimationTime();
}

float SpineTrackEntry::get_time_scale() {
	return track_entry->getTimeScale();
}

void SpineTrackEntry::set_time_scale(float v) {
	track_entry->setTimeScale(v);
}

float SpineTrackEntry::get_alpha() {
	return track_entry->getAlpha();
}

void SpineTrackEntry::set_alpha(float v) {
	track_entry->setAlpha(v);
}

float SpineTrackEntry::get_event_threshold() {
	return track_entry->getEventThreshold();
}

void SpineTrackEntry::set_event_threshold(float v) {
	track_entry->setEventThreshold(v);
}

float SpineTrackEntry::get_attachment_threshold() {
	return track_entry->getAttachmentThreshold();
}

void SpineTrackEntry::set_attachment_threshold(float v) {
	track_entry->setAttachmentThreshold(v);
}

float SpineTrackEntry::get_draw_order_threshold() {
	return track_entry->getDrawOrderThreshold();
}

void SpineTrackEntry::set_draw_order_threshold(float v) {
	track_entry->setDrawOrderThreshold(v);
}

Ref<SpineTrackEntry> SpineTrackEntry::get_next() {
	Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	auto entry = track_entry->getNext();
	if (entry == NULL)
		return NULL;
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

bool SpineTrackEntry::is_complete() {
	return track_entry->isComplete();
}

float SpineTrackEntry::get_mix_time() {
	return track_entry->getMixTime();
}

void SpineTrackEntry::set_mix_time(float v) {
	track_entry->setMixTime(v);
}

float SpineTrackEntry::get_mix_duration() {
	return track_entry->getMixDuration();
}

void SpineTrackEntry::set_mix_duration(float v) {
	track_entry->setMixDuration(v);
}

int SpineTrackEntry::get_mix_blend() {
	return track_entry->getMixBlend();
}

void SpineTrackEntry::set_mix_blend(int v) {
	track_entry->setMixBlend((spine::MixBlend)v);
}

Ref<SpineTrackEntry> SpineTrackEntry::get_mixing_from() {
	Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	auto entry = track_entry->getMixingFrom();
	if (entry == NULL)
		return NULL;
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

Ref<SpineTrackEntry> SpineTrackEntry::get_mixing_to() {
	Ref<SpineTrackEntry> gd_entry;
	gd_entry.instance();
	auto entry = track_entry->getMixingTo();
	if (entry == NULL)
		return NULL;
	gd_entry->set_spine_object(entry);
	return gd_entry;
}

void SpineTrackEntry::reset_rotation_directions() {
	track_entry->resetRotationDirections();
}

bool SpineTrackEntry::get_reverse() {
	return track_entry->getReverse();
}

void SpineTrackEntry::set_reverse(bool v) {
	track_entry->setReverse(v);
}

} //namespace godot