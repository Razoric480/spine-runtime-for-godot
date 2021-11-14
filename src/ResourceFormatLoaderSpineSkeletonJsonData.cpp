//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "SpineSkeletonJsonDataResource.h"
#include <ClassDB.hpp>

namespace godot {

void ResourceFormatLoaderSpineSkeletonJsonData::_register_methods() {
	register_method("load", &ResourceFormatLoaderSpineSkeletonJsonData::load);
	register_method("get_recognized_extensions", &ResourceFormatLoaderSpineSkeletonJsonData::get_recognized_extensions);
	register_method("get_resource_type", &ResourceFormatLoaderSpineSkeletonJsonData::get_resource_type);
	register_method("handles_type", &ResourceFormatLoaderSpineSkeletonJsonData::handles_type);
}

void ResourceFormatLoaderSpineSkeletonJsonData::_init() {}

Variant ResourceFormatLoaderSpineSkeletonJsonData::load(const String path, const String original_path) {
	Ref<SpineSkeletonJsonDataResource> skeleton;
	skeleton.instance();
	skeleton->load_from_file(path);

	return skeleton;
}

PoolStringArray ResourceFormatLoaderSpineSkeletonJsonData::get_recognized_extensions() {
	PoolStringArray extensions;
	extensions.push_back("spjson");
	return extensions;
}

String ResourceFormatLoaderSpineSkeletonJsonData::get_resource_type(const String path) {
	if (path.get_extension() == "spjson") {
		return "Resource";
	}
	return "";
}

bool ResourceFormatLoaderSpineSkeletonJsonData::handles_type(const String _typename) {
	return _typename == "Resource" || ClassDB::get_singleton()->is_parent_class(_typename, "Resource");
}

} //namespace godot