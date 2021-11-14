//
// Created by Raiix on 2021/7/13.
//

#ifndef GODOT_RESOURCEFORMATSAVERSPINEATLAS_H
#define GODOT_RESOURCEFORMATSAVERSPINEATLAS_H

#include <Godot.hpp>
#include <ResourceFormatSaver.hpp>

namespace godot {

class ResourceFormatSaverSpineAtlas : public ResourceFormatSaver {
	GODOT_CLASS(ResourceFormatSaverSpineAtlas, ResourceFormatSaver);

public:
	static void _register_methods();
	void _init();

public:
	int64_t save(const String path, const Ref<Resource> resource, const int64_t flags);
	PoolStringArray get_recognized_extensions(const Ref<Resource> resource);
	bool recognize(const Ref<Resource> resource);
};

} //namespace godot

#endif //GODOT_RESOURCEFORMATSAVERSPINEATLAS_H
