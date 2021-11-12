//
// Created by Raymond_Lx on 2020/6/7.
//

#ifndef GODOT_SPINESPRITEMESHINSTANCE2D_H
#define GODOT_SPINESPRITEMESHINSTANCE2D_H

#include <Godot.hpp>
#include <MeshInstance2D.hpp>

#include "SpineSlot.h"

class SpineSpriteMeshInstance2D : public godot::MeshInstance2D {
	GODOT_CLASS(SpineSpriteMeshInstance2D, godot::MeshInstance2D);

protected:
	static void _register_methods();

	godot::Ref<SpineSlot> slot;
public:
	SpineSpriteMeshInstance2D();
	~SpineSpriteMeshInstance2D();

	inline void set_slot(godot::Ref<SpineSlot> s){
		slot = s;
	}
	godot::Ref<SpineSlot> get_slot();

	void apply_transform_2d(godot::Variant o);
};

#endif //GODOT_SPINESPRITEMESHINSTANCE2D_H
