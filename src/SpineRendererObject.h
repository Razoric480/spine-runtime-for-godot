
#ifndef GODOT_SPINERENDEREROBJECT_H
#define GODOT_SPINERENDEREROBJECT_H

#include <Texture.hpp>

namespace godot {

struct SpineRendererObject {
	Ref<Texture> tex;
	Ref<Texture> normal_tex;
};

} //namespace godot

#endif
