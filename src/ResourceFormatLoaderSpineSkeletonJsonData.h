//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_RESOURCEFORMATLOADERSPINESKELETONJSONDATA_H
#define GODOT_RESOURCEFORMATLOADERSPINESKELETONJSONDATA_H

#include <Godot.hpp>
#include <Resource.hpp>
#include <ResourceFormatLoader.hpp>

namespace godot {

class ResourceFormatLoaderSpineSkeletonJsonData : public ResourceFormatLoader {
	GODOT_CLASS(ResourceFormatLoaderSpineSkeletonJsonData, ResourceFormatLoader);

public:
	static void _register_methods();
	void _init();

public:
	virtual Variant load(const String path, const String original_path);
	virtual PoolStringArray get_recognized_extensions();
	virtual bool handles_type(const String _typename);
	virtual String get_resource_type(const String path);
};

} //namespace godot

#endif //GODOT_RESOURCEFORMATLOADERSPINESKELETONJSONDATA_H
