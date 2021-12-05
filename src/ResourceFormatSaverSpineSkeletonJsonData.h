//
// Created by Raiix on 2021/7/13.
//

#ifndef GODOT_RESOURCEFORMATSAVERSPINESKELETONJSONDATA_H
#define GODOT_RESOURCEFORMATSAVERSPINESKELETONJSONDATA_H

#include <godot_cpp/classes/resource_format_saver.hpp>

namespace godot {

class ResourceFormatSaverSpineSkeletonJsonData : public ResourceFormatSaver {
	GDCLASS(ResourceFormatSaverSpineSkeletonJsonData, ResourceFormatSaver);

public:
	Error save(const String &p_path, const RES &p_resource, uint32_t p_flags = 0) override;
	void get_recognized_extensions(const RES &p_resource, List<String> *p_extensions) const override;
	bool recognize(const RES &p_resource) const override;
};

} //namespace godot

#endif //GODOT_RESOURCEFORMATSAVERSPINESKELETONJSONDATA_H
