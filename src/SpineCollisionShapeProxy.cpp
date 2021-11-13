//
// Created by Raiix on 2021/7/15.
// Edited by Razoric on 2021/11/xx
//

#include "SpineCollisionShapeProxy.h"

#include "SpineSprite.h"

void SpineCollisionShapeProxy::_register_methods() {
	godot::register_method("get_spine_sprite_path", &SpineCollisionShapeProxy::get_spine_sprite_path);
	godot::register_method("set_spine_sprite_path", &SpineCollisionShapeProxy::set_spine_sprite_path);

	godot::register_method("get_slot", &SpineCollisionShapeProxy::get_slot);
	godot::register_method("set_slot", &SpineCollisionShapeProxy::set_slot);

	godot::register_method("get_sync_transform", &SpineCollisionShapeProxy::get_sync_transform);
	godot::register_method("set_sync_transform", &SpineCollisionShapeProxy::set_sync_transform);

	godot::register_property<SpineCollisionShapeProxy, godot::NodePath>("spine_sprite_path", &SpineCollisionShapeProxy::set_spine_sprite_path, &SpineCollisionShapeProxy::get_spine_sprite_path, "");
	godot::register_property<SpineCollisionShapeProxy, bool>("sync_transform", &SpineCollisionShapeProxy::set_sync_transform, &SpineCollisionShapeProxy::get_sync_transform, true);
}

SpineCollisionShapeProxy::SpineCollisionShapeProxy() {
}

SpineCollisionShapeProxy::~SpineCollisionShapeProxy() {
}

void SpineCollisionShapeProxy::_init() {
	sync_transform = true;
}

void SpineCollisionShapeProxy::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY: {
			set_process_internal(true);
		} break;
		case NOTIFICATION_INTERNAL_PROCESS: {
			if (!is_disabled()) {
				if (sync_transform)
					_sync_transform(get_spine_sprite());
				_update_polygon_from_spine_sprite(get_spine_sprite());
				if (is_visible())
					update();
			}
		} break;
	}
}

SpineSprite *SpineCollisionShapeProxy::get_spine_sprite() const {
	return (SpineSprite *)get_node_or_null(spine_sprite_path);
}

godot::NodePath SpineCollisionShapeProxy::get_spine_sprite_path() {
	return spine_sprite_path;
}

void SpineCollisionShapeProxy::set_spine_sprite_path(godot::NodePath v) {
	spine_sprite_path = v;

	_update_polygon_from_spine_sprite(get_spine_sprite());
}

godot::String SpineCollisionShapeProxy::get_slot() const {
	return slot;
}

void SpineCollisionShapeProxy::set_slot(const godot::String &v) {
	slot = v;
	_update_polygon_from_spine_sprite(get_spine_sprite());
}

void SpineCollisionShapeProxy::_update_polygon_from_spine_sprite(SpineSprite *sprite) {
	_clear_polygon();
	if (sprite == nullptr || slot.empty()) {
		return;
	}

	if (!sprite->get_skeleton().is_valid()) {
		return;
	}

	auto sk = sprite->get_skeleton()->get_spine_object();

	spine::Vector<float> vertices;

	spine::Slot *s = sk->findSlot(spine::String(slot.utf8().get_data()));
	if (!s) {
		return;
	}
	spine::Attachment *attachment = s->getAttachment();
	if (!attachment) {
		return;
	}

	if (attachment->getRTTI().isExactly(spine::BoundingBoxAttachment::rtti)) {
		auto *box = (spine::BoundingBoxAttachment *)attachment;

		vertices.setSize(box->getWorldVerticesLength(), 0);
		box->computeWorldVertices(*s, vertices);
	} else {
		return;
	}

	godot::PoolVector2Array polygon = get_polygon();
	polygon.resize(vertices.size() / 2);
	for (size_t j = 0; j < vertices.size(); j += 2) {
		polygon.set(j / 2, godot::Vector2(vertices[j], -vertices[j + 1]));
	}

	set_polygon(polygon);
}

void SpineCollisionShapeProxy::_clear_polygon() {
	set_polygon(godot::PoolVector2Array());
}

void SpineCollisionShapeProxy::_sync_transform(SpineSprite *sprite) {
	if (sprite == nullptr)
		return;
	set_global_transform(sprite->get_global_transform());
}

bool SpineCollisionShapeProxy::get_sync_transform() {
	return sync_transform;
}

void SpineCollisionShapeProxy::set_sync_transform(bool v) {
	sync_transform = v;
}

godot::Array SpineCollisionShapeProxy::_get_property_list() const {
	godot::Dictionary p;
	godot::PoolStringArray res;

	p["name"] = "slot";
	p["type"] = godot::Variant::STRING;
	_get_slot_list(res);
	if (res.size() == 0) {
		res.push_back("No Slot");
	}
	godot::String hint_string;
	for (int i = 0; i < res.size(); ++i) {
		hint_string += res[i];
		if (i != res.size() - 1) {
			hint_string += ",";
		}
	}
	p["hint_string"] = hint_string;
	p["hint"] = GODOT_PROPERTY_HINT_ENUM;

	godot::Array output;
	output.push_back(p);
	return output;
}

godot::Variant SpineCollisionShapeProxy::_get(const godot::String &p_property) const {
	if (p_property == "slot") {
		return get_slot();
	}
	godot::Object *none = nullptr;
	return none;
}

bool SpineCollisionShapeProxy::_set(const godot::String &p_property, const godot::Variant &p_value) {
	if (p_property == "slot") {
		set_slot(p_value);
		return true;
	}
	return false;
}

void SpineCollisionShapeProxy::_get_slot_list(godot::PoolStringArray &res) const {
	if (get_spine_sprite() == nullptr) {
		return;
	}

	auto sprite = get_spine_sprite();
	if (!sprite->get_skeleton().is_valid()) {
		return;
	}

	auto slots = sprite->get_skeleton()->get_slots();
	res.resize(slots.size());
	for (size_t i = 0; i < res.size(); ++i) {
		auto slot = (godot::Ref<SpineSlot>)slots[i];
		if (slot.is_valid())
			res.set(i, slot->get_data()->get_slot_name());
	}
}
