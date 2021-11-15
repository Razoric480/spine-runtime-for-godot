//
// Created by Raiix on 2021/7/15.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINECOLLISIONSHAPEPROXY_H
#define GODOT_SPINECOLLISIONSHAPEPROXY_H

#include <Godot.hpp>
#include <CollisionPolygon2D.hpp>

namespace godot {

class SpineSprite;
class SpineAnimationState;
class SpineSkeleton;

class SpineCollisionShapeProxy : public CollisionPolygon2D {
	GODOT_CLASS(SpineCollisionShapeProxy, CollisionPolygon2D)

public:
	static void _register_methods();
    void _init();

	NodePath spine_sprite_path;

	String slot;

	bool sync_transform;

protected:
	void _notification(int p_what);
	Array _get_property_list();
	bool _set(const String property, const Variant value);
	Variant _get(const String property) const;

	SpineSprite *get_spine_sprite() const;

	void _update_polygon_from_spine_sprite(SpineSprite *sprite);
	void _clear_polygon();
	void _sync_transform(SpineSprite *sprite);

	Array _get_slot_list();

public:
	SpineCollisionShapeProxy();
	~SpineCollisionShapeProxy();

	NodePath get_spine_sprite_path();
	void set_spine_sprite_path(NodePath v);

	String get_slot() const;
	void set_slot(const String &v);

	bool get_sync_transform();
	void set_sync_transform(bool v);
};

} //namespace godot

#endif //GODOT_SPINECOLLISIONSHAPEPROXY_H
