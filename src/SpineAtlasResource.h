//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINEATLASRESOURCE_H
#define GODOT_SPINEATLASRESOURCE_H

#include <Godot.hpp>

#include "SpineRendererObject.h"
#include <spine/Atlas.h>
#include <spine/SpineString.h>
#include <spine/TextureLoader.h>
#include <Texture.hpp>

class SpineAtlasResource : public godot::Resource {
	GODOT_CLASS(SpineAtlasResource, godot::Resource);

public:
	static void _register_methods();

protected:
	spine::Atlas *atlas;

	godot::String source_path;
	godot::String atlas_data;
	godot::String normal_texture_prefix;

	godot::Array tex_list;
	godot::Array ntex_list;

public:
	void _init();

	inline godot::String &get_atlas_data() { return atlas_data; }

	inline spine::Atlas *get_spine_atlas() { return atlas; }

	inline void set_normal_texture_prefix(const godot::String &p) { normal_texture_prefix = p; }

	int load_from_atlas_file(const godot::String &p_path); // .atlas

	int load_from_file(const godot::String &p_path); // .spatlas
	int save_to_file(const godot::String &p_path); // .spatlas

	godot::String get_source_path();
	godot::Array get_textures();
	godot::Array get_normal_textures();

	SpineAtlasResource();
	virtual ~SpineAtlasResource();
};

#endif //GODOT_SPINEATLASRESOURCE_H
