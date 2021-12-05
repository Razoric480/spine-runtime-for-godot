//
// Created by Raiix on 2021/7/14.
//

#ifndef GODOT_SPINETIMELINE_H
#define GODOT_SPINETIMELINE_H

#include <godot_cpp/classes/ref_counted.hpp>

#include "spine/Timeline.h"

#include "SpineConstant.h"

namespace godot {

class SpineSkeleton;
class SpineEvent;

class SpineTimeline : public RefCounted {
	GDCLASS(SpineTimeline, RefCounted);

protected:
	static void _bind_methods();

private:
	spine::Timeline *timeline;

public:
	SpineTimeline();
	~SpineTimeline();

	inline void set_spine_object(spine::Timeline *v) { timeline = v; }
	inline spine::Timeline *get_spine_object() { return timeline; }

	// Vector<Event *>
	void apply(Ref<SpineSkeleton> skeleton, float lastTime, float time, Array pEvents, float alpha, SpineConstant::MixBlend blend, SpineConstant::MixDirection direction);

	int64_t get_frame_entries();

	int64_t get_frame_count();

	// Vector<float>
	Array get_frames();

	float get_duration();

	// Vector <PropertyId>
	Array getPropertyIds();
};

} //namespace godot

#endif //GODOT_SPINETIMELINE_H
