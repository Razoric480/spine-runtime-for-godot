//
// Created by Raiix on 2020/7/12.
//

#ifndef GODOT_PACKEDSPINESKINRESOURCE_H
#define GODOT_PACKEDSPINESKINRESOURCE_H

#include "SpineSkin.h"
#include <Godot.hpp>


class PackedSpineSkinResource : public Resource {
	GODOT_CLASS(PackedSpineSkinResource, Resource);

protected:
	static void _register_methods();

private:
	String skin_name;
	Array sub_skin_names;

public:
	PackedSpineSkinResource();
	virtual ~PackedSpineSkinResource();

	void _init();

	void set_skin_name(const String &v);
	String get_skin_name();

	void set_sub_skin_names(Array v);
	Array get_sub_skin_names();
};

#endif //GODOT_PACKEDSPINESKINRESOURCE_H
