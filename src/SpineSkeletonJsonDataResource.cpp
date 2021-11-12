//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineSkeletonJsonDataResource.h"

#include <File.hpp>

void SpineSkeletonJsonDataResource::_register_methods() {
}

int SpineSkeletonJsonDataResource::load_from_file(const godot::String &p_path) {
    int err;
    godot::Ref<godot::File> file;
    file.instance();
    int err = file->open(p_path, godot::File::READ);
    if(err == godot::Error::OK) {
        json_string = file->get_as_text();
        file->close();
    }

    return err;
}

int SpineSkeletonJsonDataResource::save_to_file(const godot::String &p_path) {
    int err;
    godot::Ref<godot::File> file;
    file.instance();
    err = file->open(p_path, godot::File::WRITE);
    if(err != godot::Error::OK) {
        return err;
    }

    file->store_string(json_string);
    file->close();

    return godot::Error::OK;
}
