
#ifndef _GODOT_RAIIX_SPINE_RUNTIME_
#define _GODOT_RAIIX_SPINE_RUNTIME_

#include <godot_cpp/classes/ref_counted.hpp>

namespace godot {
class SpineRuntime : public RefCounted {
	GDCLASS(SpineRuntime, RefCounted);

protected:
	static void _bind_methods();

public:
	void hi();

	SpineRuntime();
};

} // namespace godot

#endif