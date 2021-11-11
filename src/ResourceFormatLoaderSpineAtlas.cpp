//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineAtlasResource.h"
#include <ClassDB.hpp>

void ResourceFormatLoaderSpineAtlas::_register_methods() {
	register_method("load", &ResourceFormatLoaderSpineAtlas::load);
	register_method("get_recognized_extensions", &ResourceFormatLoaderSpineAtlas::get_recognized_extensions);
	register_method("get_resource_type", &ResourceFormatLoaderSpineAtlas::get_resource_type);
	register_method("handles_type", &ResourceFormatLoaderSpineAtlas::handles_type);
}

godot::Ref<godot::Resource> ResourceFormatLoaderSpineAtlas::load(const godot::String &p_path, const godot::String &p_original_path, godot::Error *r_error) {
	godot::Ref<SpineAtlasResource> atlas;
	atlas.instance();
	atlas->load_from_file(p_path);

	if (r_error) {
		*r_error = godot::Error::OK;
	}

	return atlas;
}

void ResourceFormatLoaderSpineAtlas::_init() {}

void ResourceFormatLoaderSpineAtlas::get_recognized_extensions(godot::PoolStringArray &r_extensions) const {
	const char atlas_ext[] = "spatlas";
    bool has_atlas_ext = false;
    for(int i=0; i<r_extensions.size(); ++i) {
        if(r_extensions[i] == atlas_ext) {
            has_atlas_ext = true;
            break;
        }
    }
	if (!has_atlas_ext) {
		r_extensions.push_back(atlas_ext);
	}
}

godot::String ResourceFormatLoaderSpineAtlas::get_resource_type(const godot::String &p_path) const {
	return "SpineAtlasResource";
}

bool ResourceFormatLoaderSpineAtlas::handles_type(const godot::String &p_type) const {
    return p_type == "SpineAtlasResource" || godot::ClassDB::get_singleton()->is_parent_class(p_type, "SpineAtlasResource");
}