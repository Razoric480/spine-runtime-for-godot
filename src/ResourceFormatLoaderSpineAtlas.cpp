//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineAtlasResource.h"
#include <godot_cpp/core/class_db.hpp>

namespace godot {

Variant ResourceFormatLoaderSpineAtlas::load(const String &path, const String &original_path, bool use_sub_threads, int64_t cache_mode) const {
    Ref<SpineAtlasResource> atlas = memnew(SpineAtlasResource);
    atlas->load_from_file(path);

    return atlas;
}

PackedStringArray ResourceFormatLoaderSpineAtlas::get_recognized_extensions() const {
    PackedStringArray extensions;
    extensions.push_back("spatlas");
    return extensions;
}

String ResourceFormatLoaderSpineAtlas::get_resource_type(const String &p_path) const {
    return "SpineAtlasResource";
}

bool ResourceFormatLoaderSpineAtlas::handles_type(const StringName &type) const {
    
    return p_type == "SpineAtlasResource" || ClassDB::is_parent_class(p_type, "SpineAtlasResource");
}

}