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

namespace godot {

class SpineAtlasResource : public Resource {
	GODOT_CLASS(SpineAtlasResource, Resource);

public:
	void _init();

protected:
public:
	static void _register_methods();

	spine::Atlas *atlas;

	String source_path;
	String atlas_data;
	String normal_texture_prefix;

	Array tex_list;
	Array ntex_list;

public:
	inline String &get_atlas_data() { return atlas_data; }

	inline spine::Atlas *get_spine_atlas() { return atlas; }

	inline void set_normal_texture_prefix(const String &p) { normal_texture_prefix = p; }

	int load_from_atlas_file(const String &p_path); // .atlas

	int load_from_file(const String &p_path); // .spatlas
	int save_to_file(const String &p_path); // .spatlas

	String get_source_path();
	Array get_textures();
	Array get_normal_textures();

	SpineAtlasResource();
	virtual ~SpineAtlasResource();
};

} //namespace godot
#endif //GODOT_SPINEATLASRESOURCE_H