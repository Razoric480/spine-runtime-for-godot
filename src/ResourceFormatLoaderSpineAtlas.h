//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
#define GODOT_RESOURCEFORMATLOADERSPINEATLAS_H

#include <godot_cpp/classes/resource_format_loader.hpp>

namespace godot {

class ResourceFormatLoaderSpineAtlas : public ResourceFormatLoader {
	GDCLASS(ResourceFormatLoaderSpineAtlas, ResourceFormatLoader);

protected:
	static void _bind_methods();

public:
	virtual Variant load(const String &path, const String &original_path, bool use_sub_threads, int64_t cache_mode) const;
	virtual PackedStringArray get_recognized_extensions() const;
	virtual bool handles_type(const StringName &type) const;
	virtual String get_resource_type(const String &path) const;
};

} //namespace godot

#endif //GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
