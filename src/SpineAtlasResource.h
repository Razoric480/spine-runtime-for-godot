//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINEATLASRESOURCE_H
#define GODOT_SPINEATLASRESOURCE_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture.hpp>
#include <godot_cpp/classes/resource_loader.hpp>


#include "SpineRendererObject.h"
#include <spine/Atlas.h>
#include <spine/SpineString.h>
#include <spine/TextureLoader.h>


namespace godot {

class SpineAtlasResource : public Resource {
	GDCLASS(SpineAtlasResource, Resource);

protected:
	static void _bind_methods();

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

	Error load_from_atlas_file(const String &p_path); // .atlas

	Error load_from_file(const String &p_path); // .spatlas
	Error save_to_file(const String &p_path); // .spatlas

	String get_source_path();
	Array get_textures();
	Array get_normal_textures();

	SpineAtlasResource();
	virtual ~SpineAtlasResource();
};

} //namespace godot

#endif //GODOT_SPINEATLASRESOURCE_H
