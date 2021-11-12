//
// Created by Raiix on 2021/7/14.
// Edited by Razoric on 2021/11/xx
//

#include "SpineTimeline.h"

#include "SpineEvent.h"
#include "SpineSkeleton.h"

void SpineTimeline::_register_methods() {
	godot::register_method("apply", &SpineTimeline::apply);
	godot::register_method("get_frame_entries", &SpineTimeline::get_frame_entries);
	godot::register_method("get_frame_count", &SpineTimeline::get_frame_count);
	godot::register_method("get_frames", &SpineTimeline::get_frames);
	godot::register_method("get_duration", &SpineTimeline::get_duration);
	godot::register_method("getPropertyIds", &SpineTimeline::getPropertyIds);
}

SpineTimeline::SpineTimeline() {
}

SpineTimeline::~SpineTimeline() {
}

void SpineTimeline::_init() {
	timeline = nullptr;
}

void SpineTimeline::apply(godot::Ref<SpineSkeleton> skeleton, float lastTime, float time, godot::Array pEvents, float alpha,
		SpineConstant::MixBlend blend, SpineConstant::MixDirection direction) {
	spine::Vector<spine::Event *> events;
	events.setSize(pEvents.size(), nullptr);
	for (size_t i = 0; i < events.size(); ++i) {
		events[i] = ((godot::Ref<SpineEvent>)pEvents[i])->get_spine_object();
	}

	timeline->apply(*(skeleton->get_spine_object()), lastTime, time, &events, alpha, (spine::MixBlend)blend, (spine::MixDirection)direction);
}

int64_t SpineTimeline::get_frame_entries() {
	return timeline->getFrameEntries();
}

int64_t SpineTimeline::get_frame_count() {
	return timeline->getFrameCount();
}

godot::Array SpineTimeline::get_frames() {
	auto &frames = timeline->getFrames();
	godot::Array res;
	res.resize(frames.size());

	for (size_t i = 0; i < res.size(); ++i) {
		res[i] = frames[i];
	}

	return res;
}

float SpineTimeline::get_duration() {
	return timeline->getDuration();
}

godot::Array SpineTimeline::getPropertyIds() {
	auto &ids = timeline->getPropertyIds();
	godot::Array res;
	res.resize(ids.size());

	for (size_t i = 0; i < res.size(); ++i) {
		res[i] = (int64_t)ids[i];
	}

	return res;
}
