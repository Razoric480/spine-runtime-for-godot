//
// Created by Raymond_Lx on 2020/6/3.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINESKELETONJSONDATARESOURCE_H
#define GODOT_SPINESKELETONJSONDATARESOURCE_H

#include <Godot.hpp>
#include <Resource.hpp>

namespace godot {

class SpineSkeletonJsonDataResource : public Resource {
	GODOT_CLASS(SpineSkeletonJsonDataResource, Resource);

public:
	void _init();
	static void _register_methods();

	String json_string;

public:
	inline const String &get_json_string() { return json_string; }

	int load_from_file(String p_path);
	int save_to_file(String p_path);
};

} //namespace godot

#endif //GODOT_SPINESKELETONJSONDATARESOURCE_H
