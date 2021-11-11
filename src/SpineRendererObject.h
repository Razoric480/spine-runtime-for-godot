
#ifndef GODOT_SPINERENDEREROBJECT_H
#define GODOT_SPINERENDEREROBJECT_H

#include <Godot.hpp>
#include <Texture.hpp>

struct SpineRendererObject {
	godot::Ref<godot::Texture> tex;
	godot::Ref<godot::Texture> normal_tex;
};

#endif
