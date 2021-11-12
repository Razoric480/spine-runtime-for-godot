//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineAtlasResource.h"
#include <ClassDB.hpp>

void ResourceFormatLoaderSpineAtlas::_register_methods() {
	godot::register_method("load", &ResourceFormatLoaderSpineAtlas::load);
	godot::register_method("get_recognized_extensions", &ResourceFormatLoaderSpineAtlas::get_recognized_extensions);
	godot::register_method("get_resource_type", &ResourceFormatLoaderSpineAtlas::get_resource_type);
	godot::register_method("handles_type", &ResourceFormatLoaderSpineAtlas::handles_type);
}

godot::Variant ResourceFormatLoaderSpineAtlas::load(const godot::String &p_path, const godot::String &p_original_path) {
	godot::Ref<SpineAtlasResource> atlas;
	atlas.instance();
	atlas->load_from_file(p_path);

	return atlas;
}

void ResourceFormatLoaderSpineAtlas::_init() {
}

godot::PoolStringArray ResourceFormatLoaderSpineAtlas::get_recognized_extensions() const {
	godot::PoolStringArray extensions;
	extensions.push_back("spatlas");
	return extensions;
}

godot::String ResourceFormatLoaderSpineAtlas::get_resource_type(const godot::String &p_path) const {
	return "SpineAtlasResource";
}

bool ResourceFormatLoaderSpineAtlas::handles_type(const godot::String &p_type) const {
	return p_type == "SpineAtlasResource" || godot::ClassDB::get_singleton()->is_parent_class(p_type, "SpineAtlasResource");
}
