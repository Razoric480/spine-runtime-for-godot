//
// Created by Raiix on 2021/7/14.
// Edited by Razoric on 2021/11/xx
//

#ifndef GODOT_SPINETIMELINE_H
#define GODOT_SPINETIMELINE_H

#include <Godot.hpp>

#include "spine/Timeline.h"

#include "SpineConstant.h"

class SpineSkeleton;
class SpineEvent;

class SpineTimeline : public godot::Reference {
	GODOT_CLASS(SpineTimeline, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::Timeline *timeline;

public:
	SpineTimeline();
	~SpineTimeline();

	void _init();

	inline void set_spine_object(spine::Timeline *v) { timeline = v; }
	inline spine::Timeline *get_spine_object() { return timeline; }

	// Vector<Event *>
	void apply(godot::Ref<SpineSkeleton> skeleton, float lastTime, float time, godot::Array pEvents, float alpha, int blend, int direction);

	int64_t get_frame_entries();

	int64_t get_frame_count();

	// Vector<float>
	godot::Array get_frames();

	float get_duration();

	// Vector <PropertyId>
	godot::Array getPropertyIds();
};

#endif //GODOT_SPINETIMELINE_H
