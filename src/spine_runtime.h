
#ifndef _GODOT_RAIIX_SPINE_RUNTIME_
#define _GODOT_RAIIX_SPINE_RUNTIME_

#include <Godot.hpp>

class SpineRuntime : public godot::Reference {
	GODOT_CLASS(SpineRuntime, godot::Reference);

protected:
	static void _register_methods();

public:
	void _init();
	void hi();

	SpineRuntime();
};

#endif