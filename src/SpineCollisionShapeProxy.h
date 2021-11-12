//
// Created by Raiix on 2021/7/15.
// Edited by Razoric on 2021/11/xx
//

#ifndef GODOT_SPINECOLLISIONSHAPEPROXY_H
#define GODOT_SPINECOLLISIONSHAPEPROXY_H

#include <CollisionPolygon2D.hpp>
#include <Godot.hpp>


class SpineSprite;
class SpineAnimationState;
class SpineSkeleton;

class SpineCollisionShapeProxy : public godot::CollisionPolygon2D {
	GODOT_CLASS(SpineCollisionShapeProxy, godot::CollisionPolygon2D)
    
protected:
	static void _register_methods();

	godot::NodePath spine_sprite_path;

	godot::String slot;

	bool sync_transform;

protected:
	void _notification(int p_what);
	godot::Array _get_property_list() const;
	godot::Variant _get(const godot::String &p_property) const;
	bool _set(const godot::String &p_property, const godot::Variant &p_value);

	SpineSprite *get_spine_sprite() const;

	void _update_polygon_from_spine_sprite(SpineSprite *sprite);
	void _clear_polygon();
	void _sync_transform(SpineSprite *sprite);

	void _get_slot_list(godot::PoolStringArray &res) const;

public:
	SpineCollisionShapeProxy();
	~SpineCollisionShapeProxy();
	
	void _init();

	godot::NodePath get_spine_sprite_path();
	void set_spine_sprite_path(godot::NodePath v);

	godot::String get_slot() const;
	void set_slot(const godot::String &v);

	bool get_sync_transform();
	void set_sync_transform(bool v);
};

#endif //GODOT_SPINECOLLISIONSHAPEPROXY_H
