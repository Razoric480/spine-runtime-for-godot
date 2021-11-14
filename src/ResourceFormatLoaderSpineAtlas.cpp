//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineAtlasResource.h"
#include <ClassDB.hpp>

namespace godot {

void ResourceFormatLoaderSpineAtlas::_register_methods() {
	register_method("load", &ResourceFormatLoaderSpineAtlas::load);
	register_method("get_recognized_extensions", &ResourceFormatLoaderSpineAtlas::get_recognized_extensions);
	register_method("get_resource_type", &ResourceFormatLoaderSpineAtlas::get_resource_type);
	register_method("handles_type", &ResourceFormatLoaderSpineAtlas::handles_type);
}

void ResourceFormatLoaderSpineAtlas::_init() {}

Variant ResourceFormatLoaderSpineAtlas::load(const String path, const String original_path) {
	Ref<SpineAtlasResource> atlas;
	atlas.instance();
	atlas->load_from_file(path);

	return atlas;
}

PoolStringArray ResourceFormatLoaderSpineAtlas::get_recognized_extensions() {
	PoolStringArray extensions;
	extensions.push_back("spatlas");
	return extensions;
}

String ResourceFormatLoaderSpineAtlas::get_resource_type(const String path) {
	if (path.get_extension() == "spatlas") {
		return "Resource";
	}
	return "";
}

bool ResourceFormatLoaderSpineAtlas::handles_type(const String _typename) {
	return _typename == "Resource" || ClassDB::get_singleton()->is_parent_class(_typename, "Resource");
}

} //namespace godot