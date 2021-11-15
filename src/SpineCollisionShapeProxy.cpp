//
// Created by Raiix on 2021/7/15.
//

#include "SpineCollisionShapeProxy.h"

#include "SpineSprite.h"

namespace godot {

void SpineCollisionShapeProxy::_register_methods() {
	register_method("get_spine_sprite_path", &SpineCollisionShapeProxy::get_spine_sprite_path);
	register_method("set_spine_sprite_path", &SpineCollisionShapeProxy::set_spine_sprite_path);

	register_method("get_slot", &SpineCollisionShapeProxy::get_slot);
	register_method("set_slot", &SpineCollisionShapeProxy::set_slot);

	register_method("get_sync_transform", &SpineCollisionShapeProxy::get_sync_transform);
	register_method("set_sync_transform", &SpineCollisionShapeProxy::set_sync_transform);

	register_method("_notification", &SpineCollisionShapeProxy::_notification);
	register_method("_get_property_list", &SpineCollisionShapeProxy::_get_property_list);
	register_method("_set", &SpineCollisionShapeProxy::_set);
	register_method("_get", &SpineCollisionShapeProxy::_get);

	register_property<SpineCollisionShapeProxy, NodePath>("spine_sprite_path", &SpineCollisionShapeProxy::set_spine_sprite_path, &SpineCollisionShapeProxy::get_spine_sprite_path, "");
	register_property<SpineCollisionShapeProxy, bool>("sync_transform", &SpineCollisionShapeProxy::set_sync_transform, &SpineCollisionShapeProxy::get_sync_transform, true);
}

SpineCollisionShapeProxy::SpineCollisionShapeProxy() {
}

void SpineCollisionShapeProxy::_init() {
	sync_transform = true;
}

SpineCollisionShapeProxy::~SpineCollisionShapeProxy() {
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
	return cast_to<SpineSprite>(get_node_or_null(spine_sprite_path));
}

NodePath SpineCollisionShapeProxy::get_spine_sprite_path() {
	return spine_sprite_path;
}

void SpineCollisionShapeProxy::set_spine_sprite_path(NodePath v) {
	spine_sprite_path = v;

	_update_polygon_from_spine_sprite(get_spine_sprite());
}

String SpineCollisionShapeProxy::get_slot() const {
	return slot;
}

void SpineCollisionShapeProxy::set_slot(const String &v) {
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

	spine::Slot *s = sk->findSlot(spine::String(slot.alloc_c_string()));
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

	PoolVector2Array polygon;
	polygon.resize(vertices.size() / 2);
	for (size_t j = 0; j < vertices.size(); j += 2) {
		polygon.set(j / 2, Vector2(vertices[j], -vertices[j + 1]));
	}

	set_polygon(polygon);
}

void SpineCollisionShapeProxy::_clear_polygon() {
	set_polygon(PoolVector2Array());
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

Array SpineCollisionShapeProxy::_get_property_list() {
	Array list;
	Dictionary p;

	p["name"] = "slot";
	p["type"] = Variant::STRING;
	Array res = _get_slot_list();
	if (res.empty())
		res.push_back("No Slot");
	String hint_string;
	for (int i = 0; i < res.size(); ++i) {
		String value = res[i];
		hint_string += value;
		if (i < res.size() - 1) {
			hint_string += ",";
		}
	}
	p["hint_string"] = hint_string;
	p["hint"] = GODOT_PROPERTY_HINT_ENUM;
	list.push_back(p);

	return list;
}

Variant SpineCollisionShapeProxy::_get(const String property) const {
	if (property == "slot") {
		return get_slot();
	}
	Variant var = (Object *)nullptr;
	return var;
}

bool SpineCollisionShapeProxy::_set(const String property, const Variant value) {
	if (property == "slot") {
		set_slot(value);
		return true;
	}
	return false;
}

Array SpineCollisionShapeProxy::_get_slot_list() {
	if (get_spine_sprite() == nullptr) {
		return Array();
	}

	auto sprite = get_spine_sprite();
	if (!sprite->get_skeleton().is_valid()) {
		return Array();
	}

	auto slots = sprite->get_skeleton()->get_slots();
	Array res;
	res.resize(slots.size());
	for (size_t i = 0; i < res.size(); ++i) {
		auto slot = (Ref<SpineSlot>)slots[i];
		if (slot.is_valid())
			res[i] = slot->get_data()->get_slot_name();
	}
	return res;
}

} //namespace godot