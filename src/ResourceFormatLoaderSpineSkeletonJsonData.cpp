//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "SpineSkeletonJsonDataResource.h"
#include <ClassDB.hpp>

void ResourceFormatLoaderSpineSkeletonJsonData::_register_methods() {
	godot::register_method("load", &ResourceFormatLoaderSpineSkeletonJsonData::load);
	godot::register_method("get_recognized_extensions", &ResourceFormatLoaderSpineSkeletonJsonData::get_recognized_extensions);
	godot::register_method("get_resource_type", &ResourceFormatLoaderSpineSkeletonJsonData::get_resource_type);
	godot::register_method("handles_type", &ResourceFormatLoaderSpineSkeletonJsonData::handles_type);
}

void ResourceFormatLoaderSpineSkeletonJsonData::_init() {}

godot::Variant ResourceFormatLoaderSpineSkeletonJsonData::load(const godot::String &p_path, const godot::String &p_original_path) {
	godot::Ref<SpineSkeletonJsonDataResource> skeleton;
    skeleton.instance();
	skeleton->load_from_file(p_path);

	return skeleton;
}

godot::PoolStringArray ResourceFormatLoaderSpineSkeletonJsonData::get_recognized_extensions() const {
	godot::PoolStringArray extensions;
	extensions.push_back("spjson");
	return extensions;
}

godot::String ResourceFormatLoaderSpineSkeletonJsonData::get_resource_type(const godot::String &p_path) const {
	return "SpineSkeletonJsonDataResource";
}

bool ResourceFormatLoaderSpineSkeletonJsonData::handles_type(const godot::String &p_type) const {
	return p_type == "SpineSkeletonJsonDataResource" || godot::ClassDB::get_singleton()->is_parent_class(p_type, "SpineSkeletonJsonDataResource");
}
