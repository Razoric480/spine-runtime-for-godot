//
// Created by Raiix on 2020/7/12.
// Edited by Razoric on 2021/11/xx
//

#ifndef GODOT_PACKEDSPINESKINRESOURCE_H
#define GODOT_PACKEDSPINESKINRESOURCE_H

#include "SpineSkin.h"
#include <Godot.hpp>
#include <Resource.hpp>

class PackedSpineSkinResource : public godot::Resource {
	GODOT_CLASS(PackedSpineSkinResource, godot::Resource);

protected:
	static void _register_methods();

private:
	godot::String skin_name;
	godot::Array sub_skin_names;

public:
	PackedSpineSkinResource();
	virtual ~PackedSpineSkinResource();

	void _init();

	void set_skin_name(const godot::String &v);
	const godot::String &get_skin_name();

	void set_sub_skin_names(godot::Array v);
	godot::Array get_sub_skin_names();
};

#endif //GODOT_PACKEDSPINESKINRESOURCE_H
