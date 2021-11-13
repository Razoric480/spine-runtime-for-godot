//
// Created by Raymond_Lx on 2020/6/4.
//

#ifndef GODOT_SPINETRACKENTRY_H
#define GODOT_SPINETRACKENTRY_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineAnimation.h"

class SpineTrackEntry : public godot::Reference {
	GODOT_CLASS(SpineTrackEntry, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::TrackEntry *track_entry;

public:
	SpineTrackEntry();
	~SpineTrackEntry();

	void _init();

	inline void set_spine_object(spine::TrackEntry *t) {
		track_entry = t;
	}
	inline spine::TrackEntry *get_spine_object() {
		return track_entry;
	}

	enum MixBlend {
		MIXBLEND_SETUP = 0,
		MIXBLEND_FIRST,
		MIXBLEND_REPLACE,
		MIXBLEND_ADD
	};

	int get_track_index();

	godot::Ref<SpineAnimation> get_animation();

	int get_MIXBLEND_SETUP();
	int get_MIXBLEND_FIRST();
	int get_MIXBLEND_REPLACE();
	int get_MIXBLEND_ADD();

	bool get_loop();
	void set_loop(bool v);

	bool get_hold_previous();
	void set_hold_previous(bool v);

	bool get_reverse();
	void set_reverse(bool v);

	float get_delay();
	void set_delay(float v);

	float get_track_time();
	void set_track_time(float v);

	float get_track_end();
	void set_track_end(float v);

	float get_animation_start();
	void set_animation_start(float v);

	float get_animation_last();
	void set_animation_last(float v);

	float get_animation_time();

	float get_time_scale();
	void set_time_scale(float v);

	float get_alpha();
	void set_alpha(float v);

	float get_event_threshold();
	void set_event_threshold(float v);

	float get_attachment_threshold();
	void set_attachment_threshold(float v);

	float get_draw_order_threshold();
	void set_draw_order_threshold(float v);

	godot::Ref<SpineTrackEntry> get_next();

	bool is_complete();

	float get_mix_time();
	void set_mix_time(float v);

	float get_mix_duration();
	void set_mix_duration(float v);

	int get_mix_blend();
	void set_mix_blend(int v);

	godot::Ref<SpineTrackEntry> get_mixing_from();
	godot::Ref<SpineTrackEntry> get_mixing_to();

	void reset_rotation_directions();
};

#endif //GODOT_SPINETRACKENTRY_H
