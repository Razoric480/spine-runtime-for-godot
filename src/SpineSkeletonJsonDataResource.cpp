//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineSkeletonJsonDataResource.h"
#include <File.hpp>

namespace godot {

void SpineSkeletonJsonDataResource::_register_methods() {
	register_method("load_from_file", &SpineSkeletonJsonDataResource::load_from_file);
	register_method("save_to_file", &SpineSkeletonJsonDataResource::save_to_file);
}

void SpineSkeletonJsonDataResource::_init() {
    json_string = "";
}

int SpineSkeletonJsonDataResource::load_from_file(String p_path) {
	int err;

	Ref<File> file;
	file.instance();

	err = (int)file->open(p_path, File::READ);
	if (err == GODOT_OK) {
		json_string = file->get_as_text();
		file->close();
	}

	return err;
}

int SpineSkeletonJsonDataResource::save_to_file(String p_path) {
	int err;
	Ref<File> file;
	file.instance();

	err = (int)file->open(p_path, File::WRITE);
	if (err != GODOT_OK) {
		return err;
	}

	file->store_string(json_string);
	file->close();

	return GODOT_OK;
}

} //namespace godot