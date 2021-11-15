//
// Created by Raymond_Lx on 2020/6/4.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpineAnimation.h"

#include "SpineEvent.h"
#include "SpineSkeleton.h"
#include "SpineTimeline.h"

namespace godot {

void SpineAnimation::_register_methods() {
	register_method("get_anim_name", &SpineAnimation::get_anim_name);
	register_method("get_duration", &SpineAnimation::get_duration);
	register_method("set_duration", &SpineAnimation::set_duration);

	register_method("apply", &SpineAnimation::apply);
	register_method("get_timelines", &SpineAnimation::get_timelines);
	register_method("has_timeline", &SpineAnimation::has_timeline);
}

SpineAnimation::SpineAnimation() {}
SpineAnimation::~SpineAnimation() {}

void SpineAnimation::_init() {
	animation = nullptr;
}

String SpineAnimation::get_anim_name() {
	return animation->getName().buffer();
}

float SpineAnimation::get_duration() {
	return animation->getDuration();
}

void SpineAnimation::set_duration(float v) {
	animation->setDuration(v);
}

void SpineAnimation::apply(Ref<SpineSkeleton> skeleton, float lastTime, float time, bool loop,
		Array pEvents, float alpha, int blend,
		int direction) {
	spine::Vector<spine::Event *> events;
	events.setSize(pEvents.size(), nullptr);
	for (size_t i = 0; i < events.size(); ++i) {
		events[i] = ((Ref<SpineEvent>)(pEvents[i]))->get_spine_object();
	}
	animation->apply(*(skeleton->get_spine_object()), lastTime, time, loop, &events, alpha, (spine::MixBlend)blend, (spine::MixDirection)direction);
}

Array SpineAnimation::get_timelines() {
	auto &timelines = animation->getTimelines();
	Array res;
	res.resize(timelines.size());

	for (size_t i = 0; i < res.size(); ++i) {
		Ref<SpineTimeline> a;
		a.instance();
		a->set_spine_object(timelines[i]);
		res[i] = a;
	}

	return res;
}

bool SpineAnimation::has_timeline(Array ids) {
	spine::Vector<spine::PropertyId> list;
	list.setSize(ids.size(), 0);

	for (size_t i = 0; i < list.size(); ++i) {
		list[i] = (int64_t)ids[i];
	}
	return animation->hasTimeline(list);
}

} //namespace godot