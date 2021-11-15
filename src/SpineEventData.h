//
// Created by Raymond_Lx on 2020/6/4.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINEEVENTDATA_H
#define GODOT_SPINEEVENTDATA_H

#include <Godot.hpp>

#include <spine/spine.h>

namespace godot {

class SpineEventData : public Reference{
	GODOT_CLASS(SpineEventData, Reference);

public:
	void _init();
	static void _register_methods();
	
private:
	const spine::EventData *event_data;

public:
	SpineEventData();
	~SpineEventData();

	inline void set_spine_object(const spine::EventData *e){
		event_data = e;
	}
	
	inline const spine::EventData *get_spine_object(){
		return event_data;
	}
};

}

#endif //GODOT_SPINEEVENTDATA_H
