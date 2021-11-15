//
// Created by Raiix on 2020/7/12.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_PACKEDSPINESKINRESOURCE_H
#define GODOT_PACKEDSPINESKINRESOURCE_H

#include <Godot.hpp>
#include <Resource.hpp>

#include "SpineSkin.h"

namespace godot {

class PackedSpineSkinResource : public Resource {
	GODOT_CLASS(PackedSpineSkinResource, Resource);

public:
	void _init();
	static void _register_methods();

private:
	String skin_name;
	Array sub_skin_names;

public:
	PackedSpineSkinResource();
	virtual ~PackedSpineSkinResource();

	void set_skin_name(String v);
	String get_skin_name();

	void set_sub_skin_names(Array v);
	Array get_sub_skin_names();
};

} //namespace godot

#endif //GODOT_PACKEDSPINESKINRESOURCE_H
