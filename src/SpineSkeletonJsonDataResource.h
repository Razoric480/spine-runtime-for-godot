//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETONJSONDATARESOURCE_H
#define GODOT_SPINESKELETONJSONDATARESOURCE_H

#include <godot_cpp/classes/resource.hpp>

namespace godot {

class SpineSkeletonJsonDataResource : public Resource {
	GDCLASS(SpineSkeletonJsonDataResource, Resource);

protected:
	static void _bind_methods();

	String json_string;

public:
	inline const String &get_json_string() { return json_string; }

	Error load_from_file(const String &p_path);
	Error save_to_file(const String &p_path);
};

} //namespace godot

#endif //GODOT_SPINESKELETONJSONDATARESOURCE_H
