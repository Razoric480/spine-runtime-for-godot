//
// Created by Raymond_Lx on 2020/6/6.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpineBone.h"

#include "SpineSkeleton.h"
#include "SpineSprite.h"

namespace godot {

void SpineBone::_register_methods() {
	register_method("update_world_transform", &SpineBone::update_world_transform);
	//	void set_to_setup_pose();
	//
	//	Vector2 world_to_local(Vector2 world_position);
	//
	//	Vector2 local_to_world(Vector2 local_position);
	//
	//	float world_to_local_rotation(float world_rotation);
	//
	//	float local_to_world_rotation(float local_rotation);
	//
	//	void rotate_world(float degrees);
	register_method("set_to_setup_pose", &SpineBone::set_to_setup_pose);
	register_method("world_to_local", &SpineBone::world_to_local);
	register_method("local_to_world", &SpineBone::local_to_world);
	register_method("world_to_local_rotation", &SpineBone::world_to_local_rotation);
	register_method("local_to_world_rotation", &SpineBone::local_to_world_rotation);
	register_method("rotate_world", &SpineBone::rotate_world);
	//
	//	float get_world_to_local_rotation_x();
	//	float get_world_to_local_rotation_y();
	//
	//	Ref<SpineBoneData> get_data();
	//
	//	Ref<SpineSkeleton> get_skeleton();
	//
	//	Ref<SpineBone> get_parent();
	//
	//	Array get_children();
	register_method("get_world_to_local_rotation_x", &SpineBone::get_world_to_local_rotation_x);
	register_method("get_world_to_local_rotation_y", &SpineBone::get_world_to_local_rotation_y);
	register_method("get_data", &SpineBone::get_data);
	register_method("get_skeleton", &SpineBone::get_skeleton);
	register_method("get_parent", &SpineBone::get_parent);
	register_method("get_children", &SpineBone::get_children);
	//
	//	float get_x();
	//	void set_x(float v);
	//
	//	float get_y();
	//	void set_y(float v);
	//
	//	float get_rotation();
	//	void set_rotation(float v);
	//
	//	float get_scale_x();
	//	void set_scale_x(float v);
	register_method("get_x", &SpineBone::get_x);
	register_method("set_x", &SpineBone::set_x);
	register_method("get_y", &SpineBone::get_y);
	register_method("set_y", &SpineBone::set_y);
	register_method("get_rotation", &SpineBone::get_rotation);
	register_method("set_rotation", &SpineBone::set_rotation);
	register_method("get_scale_x", &SpineBone::get_scale_x);
	register_method("set_scale_x", &SpineBone::set_scale_x);
	//
	//	float get_scale_y();
	//	void set_scale_y(float v);
	//
	//	float get_shear_x();
	//	void set_shear_x(float v);
	//
	//	float get_shear_y();
	//	void set_shear_y(float v);
	//
	//	float get_applied_rotation();
	//	void set_applied_rotation(float v);
	register_method("get_scale_y", &SpineBone::get_scale_y);
	register_method("set_scale_y", &SpineBone::set_scale_y);
	register_method("get_shear_x", &SpineBone::get_shear_x);
	register_method("set_shear_x", &SpineBone::set_shear_x);
	register_method("get_shear_y", &SpineBone::get_shear_y);
	register_method("set_shear_y", &SpineBone::set_shear_y);
	register_method("get_applied_rotation", &SpineBone::get_applied_rotation);
	register_method("set_applied_rotation", &SpineBone::set_applied_rotation);
	//
	//	float get_a_x();
	//	void set_a_x(float v);
	//
	//	float get_a_y();
	//	void set_a_y(float v);
	//
	//	float get_a_scale_x();
	//	void set_a_scale_x(float v);
	//
	//	float get_a_scale_y();
	//	void set_a_scale_y(float v);
	register_method("get_a_x", &SpineBone::get_a_x);
	register_method("set_a_x", &SpineBone::set_a_x);
	register_method("get_a_y", &SpineBone::get_a_y);
	register_method("set_a_y", &SpineBone::set_a_y);
	register_method("get_a_scale_x", &SpineBone::get_a_scale_x);
	register_method("set_a_scale_x", &SpineBone::set_a_scale_x);
	register_method("get_a_scale_y", &SpineBone::get_a_scale_y);
	register_method("set_a_scale_y", &SpineBone::set_a_scale_y);
	//
	//	float get_a_shear_x();
	//	void set_a_shear_x(float v);
	//
	//	float get_a_shear_y();
	//	void set_a_shear_y(float v);
	//
	//	float get_a();
	//	void set_a(float v);
	//
	//	float get_b();
	//	void set_b(float v);
	register_method("get_a_shear_x", &SpineBone::get_a_shear_x);
	register_method("set_a_shear_x", &SpineBone::set_a_shear_x);
	register_method("get_a_shear_y", &SpineBone::get_a_shear_y);
	register_method("set_a_shear_y", &SpineBone::set_a_shear_y);
	register_method("get_a", &SpineBone::get_a);
	register_method("set_a", &SpineBone::set_a);
	register_method("get_b", &SpineBone::get_b);
	register_method("set_b", &SpineBone::set_b);
	//
	//	float get_c();
	//	void set_c(float v);
	//
	//	float get_d();
	//	void set_d(float v);
	//
	//	float get_world_x();
	//	void set_world_x(float v);
	//
	//	float get_world_y();
	//	void set_world_y(float v);
	register_method("get_c", &SpineBone::get_c);
	register_method("set_c", &SpineBone::set_c);
	register_method("get_d", &SpineBone::get_d);
	register_method("set_d", &SpineBone::set_d);
	register_method("get_world_x", &SpineBone::get_world_x);
	register_method("set_world_x", &SpineBone::set_world_x);
	register_method("get_world_y", &SpineBone::get_world_y);
	register_method("set_world_y", &SpineBone::set_world_y);
	//
	//	float get_world_rotation_x();
	//	float get_world_rotation_y();
	//
	//	float get_world_scale_x();
	//	float get_world_scale_y();
	//
	//	bool is_applied_valid();
	//	void set_applied_valid(bool v);
	//
	//	bool is_active();
	//	void set_active(bool v);
	register_method("get_world_rotation_x", &SpineBone::get_world_rotation_x);
	register_method("get_world_rotation_y", &SpineBone::get_world_rotation_y);
	register_method("get_world_scale_x", &SpineBone::get_world_scale_x);
	register_method("get_world_scale_y", &SpineBone::get_world_scale_y);
	register_method("is_active", &SpineBone::is_active);
	register_method("set_active", &SpineBone::set_active);

	register_method("get_godot_transform", &SpineBone::get_godot_transform);
	register_method("set_godot_transform", &SpineBone::set_godot_transform);
	register_method("get_godot_global_transform", &SpineBone::get_godot_global_transform);
	register_method("set_godot_global_transform", &SpineBone::set_godot_global_transform);

	register_method("apply_world_transform_2d", &SpineBone::apply_world_transform_2d);
}

SpineBone::SpineBone() {}
SpineBone::~SpineBone() {}

void SpineBone::_init() {
	bone = nullptr;
	the_sprite = nullptr;
}

void SpineBone::update_world_transform() {
	bone->updateWorldTransform();
}

void SpineBone::set_to_setup_pose() {
	bone->setToSetupPose();
}

Vector2 SpineBone::world_to_local(Vector2 world_position) {
	float x, y;
	bone->worldToLocal(world_position.x, world_position.y, x, y);
	return Vector2(x, y);
}

Vector2 SpineBone::local_to_world(Vector2 local_position) {
	float x, y;
	bone->localToWorld(local_position.x, local_position.y, x, y);
	return Vector2(x, y);
}

float SpineBone::world_to_local_rotation(float world_rotation) {
	return bone->worldToLocalRotation(world_rotation);
}

float SpineBone::local_to_world_rotation(float local_rotation) {
	return bone->localToWorldRotation(local_rotation);
}

void SpineBone::rotate_world(float degrees) {
	bone->rotateWorld(degrees);
}

float SpineBone::get_world_to_local_rotation_x() {
	return bone->getWorldToLocalRotationX();
}
float SpineBone::get_world_to_local_rotation_y() {
	return bone->getWorldToLocalRotationY();
}

Ref<SpineBoneData> SpineBone::get_data() {
	auto &bd = bone->getData();
	Ref<SpineBoneData> gd_bd;
	gd_bd.instance();
	gd_bd->set_spine_object(&bd);
	return gd_bd;
}

Ref<SpineSkeleton> SpineBone::get_skeleton() {
	auto &s = bone->getSkeleton();
	Ref<SpineSkeleton> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(&s);
	gd_s->set_spine_sprite(the_sprite);
	return gd_s;
}

Ref<SpineBone> SpineBone::get_parent() {
	auto b = bone->getParent();
	if (b == NULL)
		return NULL;
	Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(b);
	gd_b->set_spine_sprite(the_sprite);
	return gd_b;
}

Array SpineBone::get_children() {
	auto bs = bone->getChildren();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		auto b = bs[i];
		if (b == NULL)
			gd_bs[i] = Ref<SpineBone>(NULL);
		Ref<SpineBone> gd_b;
		gd_b.instance();
		gd_b->set_spine_object(b);
		gd_b->set_spine_sprite(the_sprite);
		gd_bs[i] = gd_b;
	}
	return gd_bs;
}

float SpineBone::get_x() {
	return bone->getX();
}
void SpineBone::set_x(float v) {
	bone->setX(v);
}

float SpineBone::get_y() {
	return bone->getY();
}
void SpineBone::set_y(float v) {
	bone->setY(v);
}

float SpineBone::get_rotation() {
	return bone->getRotation();
}
void SpineBone::set_rotation(float v) {
	bone->setRotation(v);
}

float SpineBone::get_scale_x() {
	return bone->getScaleX();
}
void SpineBone::set_scale_x(float v) {
	bone->setScaleX(v);
}

float SpineBone::get_scale_y() {
	return bone->getScaleY();
}
void SpineBone::set_scale_y(float v) {
	bone->setScaleY(v);
}

float SpineBone::get_shear_x() {
	return bone->getShearX();
}
void SpineBone::set_shear_x(float v) {
	bone->setShearX(v);
}

float SpineBone::get_shear_y() {
	return bone->getShearY();
}
void SpineBone::set_shear_y(float v) {
	bone->setShearY(v);
}

float SpineBone::get_applied_rotation() {
	return bone->getAppliedRotation();
}
void SpineBone::set_applied_rotation(float v) {
	bone->setAppliedRotation(v);
}

float SpineBone::get_a_x() {
	return bone->getAX();
}
void SpineBone::set_a_x(float v) {
	bone->setAX(v);
}

float SpineBone::get_a_y() {
	return bone->getAY();
}
void SpineBone::set_a_y(float v) {
	bone->setAY(v);
}

float SpineBone::get_a_scale_x() {
	return bone->getAScaleX();
}
void SpineBone::set_a_scale_x(float v) {
	bone->setAScaleX(v);
}

float SpineBone::get_a_scale_y() {
	return bone->getAScaleY();
}
void SpineBone::set_a_scale_y(float v) {
	bone->setAScaleY(v);
}

float SpineBone::get_a_shear_x() {
	return bone->getAShearX();
}
void SpineBone::set_a_shear_x(float v) {
	bone->setAShearX(v);
}

float SpineBone::get_a_shear_y() {
	return bone->getAShearY();
}
void SpineBone::set_a_shear_y(float v) {
	bone->setAShearY(v);
}

float SpineBone::get_a() {
	return bone->getA();
}
void SpineBone::set_a(float v) {
	bone->setA(v);
}

float SpineBone::get_b() {
	return bone->getB();
}
void SpineBone::set_b(float v) {
	bone->setB(v);
}

float SpineBone::get_c() {
	return bone->getC();
}
void SpineBone::set_c(float v) {
	bone->setC(v);
}

float SpineBone::get_d() {
	return bone->getD();
}
void SpineBone::set_d(float v) {
	bone->setD(v);
}

float SpineBone::get_world_x() {
	return bone->getWorldX();
}
void SpineBone::set_world_x(float v) {
	bone->setWorldX(v);
}

float SpineBone::get_world_y() {
	return bone->getWorldY();
}
void SpineBone::set_world_y(float v) {
	bone->setWorldY(v);
}

float SpineBone::get_world_rotation_x() {
	return bone->getWorldRotationX();
}
float SpineBone::get_world_rotation_y() {
	return bone->getWorldRotationY();
}

float SpineBone::get_world_scale_x() {
	return bone->getWorldScaleX();
}
float SpineBone::get_world_scale_y() {
	return bone->getWorldScaleY();
}

bool SpineBone::is_active() {
	return bone->isActive();
}
void SpineBone::set_active(bool v) {
	bone->setActive(v);
}

// External feature functions
void SpineBone::apply_world_transform_2d(Variant o) {
	if (o.get_type() == Variant::OBJECT) {
		auto node = cast_to<Node>(o);
		if (node->is_class("Node2D")) {
			auto node2d = cast_to<Node2D>(node);
			// In godot the y-axis is nag to spine
			node2d->set_transform(Transform2D(
					get_a(), get_c(),
					get_b(), get_d(),
					get_world_x(), -get_world_y()));
			// Fix the rotation
			auto pos = node2d->get_position();
			node2d->translate(-pos);
			node2d->set_rotation(-node2d->get_rotation());
			node2d->translate(pos);
		}
	}
}

Transform2D SpineBone::get_godot_transform() {
	if (get_spine_object() == nullptr)
		return Transform2D();
	Transform2D trans;
	trans.translate(get_x(), -get_y());
	// It seems that spine uses degree for rotation
	trans.rotate(Math::deg2rad(-get_rotation()));
	trans.scale(Size2(get_scale_x(), get_scale_y()));
	return trans;
}

void SpineBone::set_godot_transform(Transform2D trans) {
	if (get_spine_object() == nullptr)
		return;
	Vector2 position = trans.get_origin();
	position.y *= -1;
	real_t rotation = trans.get_rotation();
	rotation = Math::rad2deg(-rotation);
	Vector2 scale = trans.get_scale();

	set_x(position.x);
	set_y(position.y);
	set_rotation(rotation);
	set_scale_x(scale.x);
	set_scale_y(scale.y);
}

Transform2D SpineBone::get_godot_global_transform() {
	if (get_spine_object() == nullptr)
		return Transform2D();
	if (the_sprite == nullptr)
		return get_godot_transform();
	Transform2D res = the_sprite->get_transform();
	res.translate(get_world_x(), -get_world_y());
	res.rotate(Math::deg2rad(-get_world_rotation_x()));
	res.scale(Vector2(get_world_scale_x(), get_world_scale_y()));
	auto p = the_sprite->get_parent() ? Object::cast_to<CanvasItem>(the_sprite->get_parent()) : nullptr;
	if (p) {
		return p->get_global_transform() * res;
	}
	return res;
}

#define ERR_PRINT(msg) Godot::print_error(String(msg), __FUNCTION__, __FILE__, __LINE__)

void SpineBone::set_godot_global_transform(Transform2D transform) {
	if (get_spine_object() == nullptr)
		return;
	if (the_sprite == nullptr)
		set_godot_transform(transform);
	transform = the_sprite->get_global_transform().affine_inverse() * transform;
	Vector2 position = transform.get_origin();
	real_t rotation = transform.get_rotation();
	Vector2 scale = transform.get_scale();
	position.y *= -1;
	auto parent = get_parent();
	if (parent.is_valid()) {
		position = parent->world_to_local(position);
		if (parent->get_world_scale_x() != 0)
			scale.x /= parent->get_world_scale_x();
		else
			ERR_PRINT(String("The parent scale.x is zero."));
		if (parent->get_world_scale_y() != 0)
			scale.y /= parent->get_world_scale_y();
		else
			ERR_PRINT(String("The parent scale.y is zero."));
	}
	rotation = world_to_local_rotation(Math::rad2deg(-rotation));

	set_x(position.x);
	set_y(position.y);
	set_rotation(rotation);
	set_scale_x(scale.x);
	set_scale_y(scale.y);
}

void SpineBone::set_spine_sprite(SpineSprite *s) {
	the_sprite = s;
}

} //namespace godot