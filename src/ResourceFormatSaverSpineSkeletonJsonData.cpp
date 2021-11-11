//
// Created by Raiix on 2021/7/13.
//

#include "ResourceFormatSaverSpineSkeletonJsonData.h"

#include "SpineSkeletonJsonDataResource.h"

void ResourceFormatSaverSpineSkeletonJsonData::_register_methods() {
    godot::register_method("save", ResourceFormatSaverSpineSkeletonJsonData::save);
    godot::register_method("get_recognized_extensions", ResourceFormatSaverSpineSkeletonJsonData::get_recognized_extensions);
    godot::register_method("recognize", ResourceFormatSaverSpineSkeletonJsonData::recognize);
}

void ResourceFormatSaverSpineSkeletonJsonData::_init() {}

godot::Error ResourceFormatSaverSpineSkeletonJsonData::save(const godot::String &p_path, const godot::Ref<godot::Resource> &p_resource, uint32_t p_flags) {
    godot::Ref<SpineSkeletonJsonDataResource> res = p_resource.ptr();
    godot::Error error = res->save_to_file(p_path);
    return error;
}

godot::PoolStringArray ResourceFormatSaverSpineSkeletonJsonData::get_recognized_extensions(const godot::Ref<godot::Resource> &p_resource) const {
    godot::PoolStringArray extensions;
    if (Object::cast_to<SpineSkeletonJsonDataResource>(*p_resource)) {
        extensions.push_back("spjson");
    }
    return extensions;
}

bool ResourceFormatSaverSpineSkeletonJsonData::recognize(const godot::Ref<godot::Resource> &p_resource) const {
    return Object::cast_to<SpineSkeletonJsonDataResource>(*p_resource) != nullptr;
}
