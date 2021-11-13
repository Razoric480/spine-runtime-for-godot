//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETONJSONDATARESOURCE_H
#define GODOT_SPINESKELETONJSONDATARESOURCE_H

#include <Godot.hpp>
#include <Resource.hpp>

class SpineSkeletonJsonDataResource : public godot::Resource {
	GODOT_CLASS(SpineSkeletonJsonDataResource, godot::Resource);

protected:
	static void _register_methods();

	godot::String json_string;

public:
	void _init();
	inline const godot::String &get_json_string() { return json_string; }

	int load_from_file(const godot::String &p_path);
	int save_to_file(const godot::String &p_path);
};

#endif //GODOT_SPINESKELETONJSONDATARESOURCE_H
