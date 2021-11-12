//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineAnimation.h"

#include "SpineEvent.h"
#include "SpineSkeleton.h"
#include "SpineTimeline.h"

void SpineAnimation::_register_methods() {
	godot::register_method("get_anim_name", &SpineAnimation::get_anim_name);
	godot::register_method("get_duration", &SpineAnimation::get_duration);
	godot::register_method("set_duration", &SpineAnimation::set_duration);

	godot::register_method("apply", &SpineAnimation::apply);
	godot::register_method("get_timelines", &SpineAnimation::get_timelines);
	godot::register_method("has_timeline", &SpineAnimation::has_timeline);
}

SpineAnimation::SpineAnimation() {}
SpineAnimation::~SpineAnimation() {}

void SpineAnimation::_init() {
	animation = nullptr;
}

godot::String SpineAnimation::get_anim_name() {
	return animation->getName().buffer();
}

float SpineAnimation::get_duration() {
	return animation->getDuration();
}

void SpineAnimation::set_duration(float v) {
	animation->setDuration(v);
}

void SpineAnimation::apply(godot::Ref<SpineSkeleton> skeleton, float lastTime, float time, bool loop,
		godot::Array pEvents, float alpha, SpineConstant::MixBlend blend,
		SpineConstant::MixDirection direction) {
	spine::Vector<spine::Event *> events;
	events.setSize(pEvents.size(), nullptr);
	for (size_t i = 0; i < events.size(); ++i) {
		events[i] = ((godot::Ref<SpineEvent>)(pEvents[i]))->get_spine_object();
	}
	animation->apply(*(skeleton->get_spine_object()), lastTime, time, loop, &events, alpha, (spine::MixBlend)blend, (spine::MixDirection)direction);
}

godot::Array SpineAnimation::get_timelines() {
	auto &timelines = animation->getTimelines();
	godot::Array res;
	res.resize(timelines.size());

	for (size_t i = 0; i < res.size(); ++i) {
		godot::Ref<SpineTimeline> a;
		a.instance();
		a->set_spine_object(timelines[i]);
		res[i] = a;
	}

	return res;
}

bool SpineAnimation::has_timeline(godot::Array ids) {
	spine::Vector<spine::PropertyId> list;
	list.setSize(ids.size(), 0);

	for (size_t i = 0; i < list.size(); ++i) {
		list[i] = (int64_t)ids[i];
	}
	return animation->hasTimeline(list);
}
