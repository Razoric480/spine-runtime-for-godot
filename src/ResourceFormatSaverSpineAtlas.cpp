//
// Created by Raiix on 2021/7/13.
//

#include "ResourceFormatSaverSpineAtlas.h"

#include "SpineAtlasResource.h"

namespace godot {

void ResourceFormatSaverSpineAtlas::_register_methods() {
	register_method("save", &ResourceFormatSaverSpineAtlas::save);
	register_method("get_recognized_extensions", &ResourceFormatSaverSpineAtlas::get_recognized_extensions);
	register_method("recognize", &ResourceFormatSaverSpineAtlas::recognize);
}

void ResourceFormatSaverSpineAtlas::_init() {}

int64_t ResourceFormatSaverSpineAtlas::save(const String path, const Ref<Resource> resource, const int64_t flags) {
	Ref<SpineAtlasResource> atlas = resource;
	int error = atlas->save_to_file(path);
	return error;
}

PoolStringArray ResourceFormatSaverSpineAtlas::get_recognized_extensions(const Ref<Resource> resource) {
	Ref<SpineAtlasResource> atlas = resource;
	PoolStringArray extensions;
	if (atlas.is_valid()) {
		extensions.push_back("spatlas");
	}
	return extensions;
}

bool ResourceFormatSaverSpineAtlas::recognize(const Ref<Resource> resource) {
	Ref<SpineAtlasResource> atlas = resource;
	return atlas.is_valid();
}

} //namespace godot