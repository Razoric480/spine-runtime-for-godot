//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
#define GODOT_RESOURCEFORMATLOADERSPINEATLAS_H

#include <Godot.hpp>
#include <ResourceFormatLoader.hpp>

class ResourceFormatLoaderSpineAtlas : public godot::ResourceFormatLoader {
	GODOT_CLASS(ResourceFormatLoaderSpineAtlas, godot::ResourceFormatLoader);

public:
	static void _register_methods();

public:
	void _init();
	virtual godot::Variant load(const godot::String &p_path, const godot::String &p_original_path);
	virtual godot::PoolStringArray get_recognized_extensions() const;
	virtual bool handles_type(const godot::String &p_type) const;
	virtual godot::String get_resource_type(const godot::String &p_path) const;
};

#endif //GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
