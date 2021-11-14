//
// Created by Raymond_Lx on 2020/6/4.
//
// This class is for wrapping spine classes and providing some api to access spine api

#ifndef GODOT_SPINEANIMATION_H
#define GODOT_SPINEANIMATION_H

#include <Godot.hpp>

#include "SpineConstant.h"

#include <spine/spine.h>

namespace godot {

class SpineEvent;
class SpineSkeleton;
class SpineTimeline;

class SpineAnimation : public Reference {
	GODOT_CLASS(SpineAnimation, Reference);

public:
	void _init();

private:
	spine::Animation *animation;

public:
	static void _register_methods();

public:
	SpineAnimation();
	~SpineAnimation();

	inline void set_spine_object(spine::Animation *a) {
		animation = a;
	}
	inline spine::Animation *get_spine_object() {
		return animation;
	}

	// Vector<Ref<SpineEvent>> pEvents
	void apply(Ref<SpineSkeleton> skeleton, float lastTime, float time, bool loop, Array pEvents, float alpha, int blend, int direction);

	Array get_timelines(); // Vector<Ref<SpineTimeline>>
	bool has_timeline(Array ids); // Vector<SpineConstant::PropertyId>

	String get_anim_name();
	float get_duration();
	void set_duration(float v);
};

} //namespace godot

#endif //GODOT_SPINEANIMATION_H
