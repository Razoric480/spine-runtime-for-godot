//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
#define GODOT_RESOURCEFORMATLOADERSPINEATLAS_H

#include <Godot.hpp>
#include <ResourceFormatLoader.hpp>

namespace godot {

class ResourceFormatLoaderSpineAtlas : public ResourceFormatLoader {
	GODOT_CLASS(ResourceFormatLoaderSpineAtlas, ResourceFormatLoader);

public:
	void _init();
	static void _register_methods();

public:
	virtual Variant load(const String path, const String original_path);
	virtual PoolStringArray get_recognized_extensions();
	virtual bool handles_type(const String _typename);
	virtual String get_resource_type(const String path);
};

} //namespace godot

#endif //GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
