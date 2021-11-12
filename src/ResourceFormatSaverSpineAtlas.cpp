//
// Created by Raiix on 2021/7/13.
// Edited by Razoric on 2021/11/xx
//

#include "ResourceFormatSaverSpineAtlas.h"

#include "SpineAtlasResource.h"

void ResourceFormatSaverSpineAtlas::_register_methods() {
    godot::register_method("save", &ResourceFormatSaverSpineAtlas::save);
    godot::register_method("get_recognized_extensions", &ResourceFormatSaverSpineAtlas::get_recognized_extensions);
    godot::register_method("recognize", &ResourceFormatSaverSpineAtlas::recognize);
}

void ResourceFormatSaverSpineAtlas::_init() {}

int ResourceFormatSaverSpineAtlas::save(const godot::String &p_path, const godot::Ref<godot::Resource> &p_resource, uint32_t p_flags) {
    godot::Ref<SpineAtlasResource> res = p_resource.ptr();
    int error = res->save_to_file(p_path);
    return error;
}

godot::PoolStringArray ResourceFormatSaverSpineAtlas::get_recognized_extensions(const godot::Ref<godot::Resource> &p_resource) const {
    godot::PoolStringArray extensions;
    if (Object::cast_to<SpineAtlasResource>(*p_resource)) {
        extensions.push_back("spatlas");
    }
    return extensions;
}

bool ResourceFormatSaverSpineAtlas::recognize(const godot::Ref<godot::Resource> &p_resource) const {
    return godot::Object::cast_to<SpineAtlasResource>(*p_resource) != nullptr;
}
