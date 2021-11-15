//
// Created by Raymond_Lx on 2020/6/7.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINESPRITEMESHINSTANCE2D_H
#define GODOT_SPINESPRITEMESHINSTANCE2D_H

#include <Godot.hpp>
#include <MeshInstance2D.hpp>

#include "SpineSlot.h"

namespace godot {

class SpineSpriteMeshInstance2D : public MeshInstance2D {
	GODOT_CLASS(SpineSpriteMeshInstance2D, MeshInstance2D);

public:
	void _init();
	static void _register_methods();

	Ref<SpineSlot> slot;

public:
	SpineSpriteMeshInstance2D();
	~SpineSpriteMeshInstance2D();

	inline void set_slot(Ref<SpineSlot> s) {
		slot = s;
	}
	Ref<SpineSlot> get_slot();

	void apply_transform_2d(Variant o);
};

} //namespace godot

#endif //GODOT_SPINESPRITEMESHINSTANCE2D_H
