//
// Created by Raiix on 2021/7/13.
//

#include "ResourceFormatSaverSpineSkeletonJsonData.h"

#include "SpineSkeletonJsonDataResource.h"

namespace godot {

void ResourceFormatSaverSpineSkeletonJsonData::_register_methods() {
	register_method("save", &ResourceFormatSaverSpineSkeletonJsonData::save);
	register_method("get_recognized_extensions", &ResourceFormatSaverSpineSkeletonJsonData::get_recognized_extensions);
	register_method("recognize", &ResourceFormatSaverSpineSkeletonJsonData::recognize);
}

void ResourceFormatSaverSpineSkeletonJsonData::_init() {
}

int64_t ResourceFormatSaverSpineSkeletonJsonData::save(const String path, const Ref<Resource> resource, const int64_t flags) {
	Ref<SpineSkeletonJsonDataResource> res = resource;
	int error = res->save_to_file(path);
	return error;
}

PoolStringArray ResourceFormatSaverSpineSkeletonJsonData::get_recognized_extensions(const Ref<Resource> resource) {
	Ref<SpineSkeletonJsonDataResource> skeleton = resource;
	PoolStringArray extensions;
	if (skeleton.is_valid()) {
		extensions.push_back("spjson");
	}
	return extensions;
}

bool ResourceFormatSaverSpineSkeletonJsonData::recognize(const Ref<Resource> resource) {
	Ref<SpineSkeletonJsonDataResource> skeleton = resource;
	return skeleton.is_valid();
}

} //namespace godot