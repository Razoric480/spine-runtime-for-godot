//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSprite.h"

#include "SpineEvent.h"
#include "SpineTrackEntry.h"
#include <CanvasItemMaterial.hpp>
#include <VisualServer.hpp>

void SpineSprite::_register_methods() {
	godot::register_method("set_animation_state_data_res", &SpineSprite::set_animation_state_data_res);
	godot::register_method("get_animation_state_data_res", &SpineSprite::get_animation_state_data_res);
	godot::register_method("_on_animation_data_created", &SpineSprite::_on_animation_data_created);
	godot::register_method("get_skeleton", &SpineSprite::get_skeleton);
	godot::register_method("get_animation_state", &SpineSprite::get_animation_state);
	godot::register_method("_on_animation_data_changed", &SpineSprite::_on_animation_data_changed);

	godot::register_method("get_current_animations", &SpineSprite::get_current_animations);
	godot::register_method("set_current_animations", &SpineSprite::set_current_animations);

	godot::register_method("get_select_track_id", &SpineSprite::get_select_track_id);
	godot::register_method("set_select_track_id", &SpineSprite::set_select_track_id);
	godot::register_method("get_clear_track", &SpineSprite::get_clear_track);
	godot::register_method("set_clear_track", &SpineSprite::set_clear_track);
	godot::register_method("get_clear_tracks", &SpineSprite::get_clear_tracks);
	godot::register_method("set_clear_tracks", &SpineSprite::set_clear_tracks);

	godot::register_method("get_empty_animation_duration", &SpineSprite::get_empty_animation_duration);
	godot::register_method("set_empty_animation_duration", &SpineSprite::set_empty_animation_duration);
	godot::register_method("get_set_empty_animation", &SpineSprite::get_set_empty_animation);
	godot::register_method("set_set_empty_animation", &SpineSprite::set_set_empty_animation);
	godot::register_method("get_set_empty_animations", &SpineSprite::get_set_empty_animations);
	godot::register_method("set_set_empty_animations", &SpineSprite::set_set_empty_animations);

	godot::register_method("get_bind_slot_nodes", &SpineSprite::get_bind_slot_nodes);
	godot::register_method("set_bind_slot_nodes", &SpineSprite::set_bind_slot_nodes);
	godot::register_method("get_overlap", &SpineSprite::get_overlap);
	godot::register_method("set_overlap", &SpineSprite::set_overlap);
	godot::register_method("set_skin", &SpineSprite::set_skin);
	godot::register_method("get_skin", &SpineSprite::get_skin);
	godot::register_method("_on_skin_property_changed", &SpineSprite::_on_skin_property_changed);
	godot::register_method("gen_spine_skin_from_packed_resource", &SpineSprite::gen_spine_skin_from_packed_resource);

	godot::register_method("bone_get_global_transform", &SpineSprite::bone_get_global_transform);
	godot::register_method("bone_set_global_transform", &SpineSprite::bone_set_global_transform);

	godot::register_method("set_process_mode", &SpineSprite::set_process_mode);
	godot::register_method("get_process_mode", &SpineSprite::get_process_mode);

	godot::register_method("manual_update", &SpineSprite::_update_all);

	godot::register_method("_get_property_list", &SpineSprite::_get_property_list);
	godot::register_method("_get", &SpineSprite::_get);
	godot::register_method("_set", &SpineSprite::_set);

	godot::register_signal<SpineSprite>("animation_state_ready", "animation_state", "skeleton");
	godot::register_signal<SpineSprite>("animation_start", "animation_state", "track_entry", "event");
	godot::register_signal<SpineSprite>("animation_interrupt", "animation_state", "track_entry", "event");
	godot::register_signal<SpineSprite>("animation_end", "animation_state", "track_entry", "event");
	godot::register_signal<SpineSprite>("animation_complete", "animation_state", "track_entry", "event");
	godot::register_signal<SpineSprite>("animation_dispose", "animation_state", "track_entry", "event");
	godot::register_signal<SpineSprite>("animation_event", "animation_state", "track_entry", "event");

	godot::register_property<SpineSprite, godot::Ref<SpineAnimationStateDataResource>>("animation_state_data_res", &SpineSprite::set_animation_state_data_res, &SpineSprite::get_animation_state_data_res, nullptr, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_RESOURCE_TYPE, "SpineAnimationStateDataResource");

	godot::register_property<SpineSprite, bool>("overlap", &SpineSprite::set_overlap, &SpineSprite::get_overlap, false);
	godot::register_property<SpineSprite, godot::Array>("bind_slot_nodes", &SpineSprite::set_bind_slot_nodes, &SpineSprite::get_bind_slot_nodes, godot::Array());
	godot::register_property<SpineSprite, godot::Ref<PackedSpineSkinResource>>("packed_skin_resource", &SpineSprite::set_skin, &SpineSprite::get_skin, nullptr, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_RESOURCE_TYPE, "PackedSpineSkinResource");

	godot::register_property<SpineSprite, int>("process_mode", &SpineSprite::set_process_mode, &SpineSprite::get_process_mode, 0, GODOT_METHOD_RPC_MODE_DISABLED, GODOT_PROPERTY_USAGE_DEFAULT, GODOT_PROPERTY_HINT_ENUM, "Process,Physics,Manually");
	godot::register_property<SpineSprite, godot::Array>("current_animations", &SpineSprite::set_current_animations, &SpineSprite::get_current_animations, godot::Array());
}

SpineSprite::SpineSprite() {}

SpineSprite::~SpineSprite() {
	delete skeleton_clipper;
}

void SpineSprite::_init() {
	select_track_id = 0;
	empty_animation_duration = 0.2f;
	skeleton_clipper = nullptr;
	overlap = false;
	process_mode = ProcessMode_Process;
	skeleton_clipper = new spine::SkeletonClipping();
}

void SpineSprite::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY: {
			set_process_internal(process_mode == ProcessMode_Process);
			set_physics_process_internal(process_mode == ProcessMode_Physics);
			remove_redundant_mesh_instances();
		} break;
		case NOTIFICATION_INTERNAL_PROCESS: {
			if (process_mode == ProcessMode_Process)
				_update_all(get_process_delta_time());
		} break;
		case NOTIFICATION_INTERNAL_PHYSICS_PROCESS: {
			if (process_mode == ProcessMode_Physics)
				_update_all(get_physics_process_delta_time());
		} break;
	}
}

void SpineSprite::_update_all(float delta) {
	if (!(skeleton.is_valid() && animation_state.is_valid()) || mesh_instances.empty())
		return;

	animation_state->update(delta);
	if (!is_visible_in_tree())
		return;

	animation_state->apply(skeleton);

	skeleton->update_world_transform();

	update_mesh_from_skeleton(skeleton);

	update();

	update_bind_slot_nodes();
}

void SpineSprite::update_bind_slot_nodes() {
	if (animation_state.is_valid() && skeleton.is_valid()) {
		for (size_t i = 0, n = bind_slot_nodes.size(); i < n; ++i) {
			auto a = bind_slot_nodes[i];
			if (a.get_type() == godot::Variant::DICTIONARY) {
				auto d = (godot::Dictionary)a;
				if (d.has("slot_name") && d.has("node_path")) {
					godot::NodePath node_path = d["node_path"];
					Node *node = get_node_or_null(node_path);
					if (node && node->is_class("Node2D")) {
						Node2D *node2d = (Node2D *)node;

						godot::String slot_name = d["slot_name"];
						auto slot = skeleton->find_slot(slot_name);
						if (slot.is_valid()) {
							auto bone = slot->get_bone();
							if (bone.is_valid()) {
								update_bind_slot_node_transform(bone, node2d);
								update_bind_slot_node_draw_order(slot_name, node2d);
							}
						}
					}
				}
			} else if (a.get_type() == godot::Variant::ARRAY) {
				auto as = (godot::Array)a; // 0: slot_name, 1: node_path
				if (as.size() >= 2 && as[0].get_type() == godot::Variant::STRING && as[1].get_type() == godot::Variant::NODE_PATH) {
					godot::NodePath node_path = as[1];
					Node *node = get_node_or_null(node_path);
					if (node && node->is_class("Node2D")) {
						Node2D *node2d = (Node2D *)node;

						godot::String slot_name = as[0];
						auto slot = skeleton->find_slot(slot_name);
						if (slot.is_valid()) {
							auto bone = slot->get_bone();
							if (bone.is_valid()) {
								update_bind_slot_node_transform(bone, node2d);
								update_bind_slot_node_draw_order(slot_name, node2d);
							}
						}
					}
				}
			}
		}
	}
}
void SpineSprite::update_bind_slot_node_transform(godot::Ref<SpineBone> bone, Node2D *node2d) {
	bone->apply_world_transform_2d(node2d);
}
void SpineSprite::update_bind_slot_node_draw_order(const godot::String &slot_name, Node2D *node2d) {
	auto mesh_ins = find_node(slot_name);
	if (mesh_ins) {
		auto pos = mesh_ins->get_index();

		// get child
		auto node = find_child_node_by_node(node2d);
		if (node && node->get_index() != pos + 1) {
			move_child(node, pos + 1);
		}
	}
}

godot::Node *SpineSprite::find_child_node_by_node(godot::Node *node) {
	if (node == NULL)
		return NULL;
	while (node && node->get_parent() != this)
		node = node->get_parent();
	return node;
}

void SpineSprite::set_animation_state_data_res(godot::Ref<SpineAnimationStateDataResource> s) {
	animation_state_data_res = s;

	// update run time skeleton and meshes
	_on_animation_data_changed();
}

godot::Ref<SpineAnimationStateDataResource> SpineSprite::get_animation_state_data_res() {
	return animation_state_data_res;
}

void SpineSprite::_on_animation_data_created() {
	//	print_line("_on_animation_data_created");
	skeleton.instance();
	skeleton->load_skeleton(animation_state_data_res->get_skeleton());
	skeleton->set_spine_sprite(this);
	//	print_line("Run time skeleton created.");

	animation_state.instance();
	animation_state->load_animation_state(animation_state_data_res);
	animation_state->get_animation_state()->setListener(this);
	//	print_line("Run time animation state created.");

	// add mesh instances related by current skeleton
	animation_state->update(0);
	animation_state->apply(skeleton);
	skeleton->update_world_transform();
	gen_mesh_from_skeleton(skeleton);

	if (process_mode == ProcessMode_Process) {
		_notification(NOTIFICATION_INTERNAL_PROCESS);
	} else if (process_mode == ProcessMode_Physics) {
		_notification(NOTIFICATION_INTERNAL_PHYSICS_PROCESS);
	}

	emit_signal("animation_state_ready", animation_state, skeleton);
}

void SpineSprite::_on_animation_data_changed() {
	//	print_line("_on_animation_data_changed");
	remove_mesh_instances();
	skeleton.unref();
	animation_state.unref();
	if (!animation_state_data_res.is_null()) {
		if (!animation_state_data_res->is_connected("animation_state_data_created", this, "_on_animation_data_created"))
			animation_state_data_res->connect("animation_state_data_created", this, "_on_animation_data_created");
		if (!animation_state_data_res->is_connected("skeleton_data_res_changed", this, "_on_animation_data_changed"))
			animation_state_data_res->connect("skeleton_data_res_changed", this, "_on_animation_data_changed");
		if (!animation_state_data_res->is_connected("animation_state_data_changed", this, "_on_animation_data_changed"))
			animation_state_data_res->connect("animation_state_data_changed", this, "_on_animation_data_changed");

		if (animation_state_data_res->is_animation_state_data_created()) {
			_on_animation_data_created();
		}
	}
}

godot::Ref<SpineSkeleton> SpineSprite::get_skeleton() {
	return skeleton;
}

godot::Ref<SpineAnimationState> SpineSprite::get_animation_state() {
	return animation_state;
}

void SpineSprite::gen_mesh_from_skeleton(godot::Ref<SpineSkeleton> s) {
	auto sk = s->get_spine_object();
	for (size_t i = 0, n = sk->getSlots().size(); i < n; ++i) {
		// creat a mesh instance 2d for every slot
		auto mesh_ins = SpineSpriteMeshInstance2D::_new();
		add_child(mesh_ins);
		mesh_ins->set_position(godot::Vector2(0, 0));
		mesh_ins->set_owner(this);
		mesh_instances.push_back(mesh_ins);

		spine::Slot *slot = sk->getDrawOrder()[i];
		mesh_ins->set_name(slot->getData().getName().buffer());
		godot::Ref<SpineSlot> gd_slot;
		gd_slot.instance();
		gd_slot->set_spine_object(slot);
		mesh_ins->set_slot(gd_slot);

		// creat a material
		godot::Ref<godot::CanvasItemMaterial> mat;
		mat.instance();
		godot::CanvasItemMaterial::BlendMode blend_mode;
		switch (slot->getData().getBlendMode()) {
			case spine::BlendMode_Normal:
				blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MIX;
				break;
			case spine::BlendMode_Additive:
				blend_mode = godot::CanvasItemMaterial::BLEND_MODE_ADD;
				break;
			case spine::BlendMode_Multiply:
				blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MUL;
				break;
			case spine::BlendMode_Screen:
				blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MIX;
				break;
			default:
				blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MIX;
		}
		mat->set_blend_mode(blend_mode);
		mesh_ins->set_material(mat);
	}
}

void SpineSprite::remove_mesh_instances() {
	for (size_t i = 0; i < mesh_instances.size(); ++i) {
		Node *node = mesh_instances[i];
		remove_child(node);
		node->free();
	}
	mesh_instances.clear();
}

void SpineSprite::remove_redundant_mesh_instances() {
	godot::Array ms;
	// remove the redundant mesh instances that added by duplicating
	//	print_line("start clearing");
	for (size_t i = 0, n = get_child_count(); i < n; ++i) {
		auto node = get_child(i);
		//		print_line(String("get a node: ") + node->get_name());
		if (node && node->is_class("SpineSpriteMeshInstance2D")) {
			if (mesh_instances.find((SpineSpriteMeshInstance2D *)node) == -1) {
				//				print_line("marked clear");
				ms.push_back(node);
			}
		}
	}
	for (size_t i = 0, n = ms.size(); i < n; ++i) {
		Node *node = ms[i];
		remove_child(node);
		node->free();
	}
	ms.clear();
	//	print_line("end clearing");
}

#define TEMP_COPY(t, get_res)                   \
	do {                                        \
		auto &temp_uvs = get_res;               \
		t.setSize(temp_uvs.size(), 0);          \
		for (size_t j = 0; j < t.size(); ++j) { \
			t[j] = temp_uvs[j];                 \
		}                                       \
	} while (false);
void SpineSprite::update_mesh_from_skeleton(godot::Ref<SpineSkeleton> s) {
	static const unsigned short VERTEX_STRIDE = 2;
	static const unsigned short UV_STRIDE = 2;
	static unsigned short quad_indices[] = { 0, 1, 2, 2, 3, 0 };

	auto sk = s->get_spine_object();
	for (size_t i = 0, n = sk->getSlots().size(); i < n; ++i) {
		spine::Vector<float> vertices;
		spine::Vector<float> uvs;
		spine::Vector<unsigned short> indices;

		spine::Slot *slot = sk->getDrawOrder()[i];

		spine::Attachment *attachment = slot->getAttachment();
		Node2D *node = mesh_instances[i];
		if (!attachment) {
			// set invisible to mesh instance
			node->set_visible(false);

			skeleton_clipper->clipEnd(*slot);
			continue;
		}
		node->set_visible(true);

		spine::Color skeleton_color = sk->getColor();
		spine::Color slot_color = slot->getColor();
		spine::Color tint(skeleton_color.r * slot_color.r, skeleton_color.g * slot_color.g, skeleton_color.b * slot_color.b, skeleton_color.a * slot_color.a);

		godot::Ref<godot::Texture> tex;
		godot::Ref<godot::Texture> normal_tex;
		size_t v_num = 0;

		if (attachment->getRTTI().isExactly(spine::RegionAttachment::rtti)) {
			spine::RegionAttachment *region_attachment = (spine::RegionAttachment *)attachment;

			auto p_spine_renderer_object = (SpineRendererObject *)((spine::AtlasRegion *)region_attachment->getRendererObject())->page->getRendererObject();
			tex = p_spine_renderer_object->tex;
			normal_tex = p_spine_renderer_object->normal_tex;

			v_num = 4;
			vertices.setSize(v_num * VERTEX_STRIDE, 0);

			region_attachment->computeWorldVertices(slot->getBone(), vertices, 0);

			TEMP_COPY(uvs, region_attachment->getUVs());

			indices.setSize(sizeof(quad_indices) / sizeof(unsigned short), 0);
			for (size_t j = 0, qn = indices.size(); j < qn; ++j) {
				indices[j] = quad_indices[j];
			}

			auto attachment_color = region_attachment->getColor();
			tint.r *= attachment_color.r;
			tint.g *= attachment_color.g;
			tint.b *= attachment_color.b;
			tint.a *= attachment_color.a;
		} else if (attachment->getRTTI().isExactly(spine::MeshAttachment::rtti)) {
			spine::MeshAttachment *mesh = (spine::MeshAttachment *)attachment;

			auto p_spine_renderer_object = (SpineRendererObject *)((spine::AtlasRegion *)mesh->getRendererObject())->page->getRendererObject();
			tex = p_spine_renderer_object->tex;
			normal_tex = p_spine_renderer_object->normal_tex;

			v_num = mesh->getWorldVerticesLength() / VERTEX_STRIDE;
			vertices.setSize(mesh->getWorldVerticesLength(), 0);

			mesh->computeWorldVertices(*slot, vertices);

			//			uvs = mesh->getUVs();
			//			indices = mesh->getTriangles();
			TEMP_COPY(uvs, mesh->getUVs());
			TEMP_COPY(indices, mesh->getTriangles());

			auto attachment_color = mesh->getColor();
			tint.r *= attachment_color.r;
			tint.g *= attachment_color.g;
			tint.b *= attachment_color.b;
			tint.a *= attachment_color.a;
		} else if (attachment->getRTTI().isExactly(spine::ClippingAttachment::rtti)) {
			auto clip = (spine::ClippingAttachment *)attachment;
			skeleton_clipper->clipStart(*slot, clip);
			continue;
		} else {
			skeleton_clipper->clipEnd(*slot);
			continue;
		}

		Node2D *mesh_ins = mesh_instances[i];
		godot::VisualServer::get_singleton()->canvas_item_clear(mesh_ins->get_canvas_item());

		if (skeleton_clipper->isClipping()) {
			skeleton_clipper->clipTriangles(vertices, indices, uvs, VERTEX_STRIDE);

			if (skeleton_clipper->getClippedTriangles().size() == 0) {
				skeleton_clipper->clipEnd(*slot);
				continue;
			}

			auto &clipped_vertices = skeleton_clipper->getClippedVertices();
			v_num = clipped_vertices.size() / VERTEX_STRIDE;
			auto &clipped_uvs = skeleton_clipper->getClippedUVs();
			auto &clipped_indices = skeleton_clipper->getClippedTriangles();

			if (indices.size() > 0) {
				godot::PoolVector2Array p_points, p_uvs;
				godot::PoolColorArray p_colors;
				godot::PoolIntArray p_indices;
				p_points.resize(v_num);
				p_uvs.resize(v_num);
				p_colors.resize(v_num);
				for (size_t j = 0; j < v_num; j++) {
					p_points.set(j, godot::Vector2(clipped_vertices[j * VERTEX_STRIDE], -clipped_vertices[j * VERTEX_STRIDE + 1]));
					p_uvs.set(j, godot::Vector2(clipped_uvs[j * VERTEX_STRIDE], clipped_uvs[j * VERTEX_STRIDE + 1]));
					p_colors.set(j, godot::Color(tint.r, tint.g, tint.b, tint.a));
				}
				p_indices.resize(clipped_indices.size());
				for (size_t j = 0; j < clipped_indices.size(); ++j) {
					p_indices.set(j, clipped_indices[j]);
				}

				godot::VisualServer::get_singleton()->canvas_item_add_triangle_array(mesh_ins->get_canvas_item(),
						p_indices,
						p_points,
						p_colors,
						p_uvs,
						godot::PoolIntArray(),
						godot::PoolRealArray(),
						tex.is_null() ? godot::RID() : tex->get_rid(),
						-1,
						normal_tex.is_null() ? godot::RID() : normal_tex->get_rid());
			}
		} else {
			if (indices.size() > 0) {
				godot::PoolVector2Array p_points, p_uvs;
				godot::PoolColorArray p_colors;
				godot::PoolIntArray p_indices;
				p_points.resize(v_num);
				p_uvs.resize(v_num);
				p_colors.resize(v_num);
				for (size_t j = 0; j < v_num; j++) {
					p_points.set(j, godot::Vector2(vertices[j * VERTEX_STRIDE], -vertices[j * VERTEX_STRIDE + 1]));
					p_uvs.set(j, godot::Vector2(uvs[j * VERTEX_STRIDE], uvs[j * VERTEX_STRIDE + 1]));
					p_colors.set(j, godot::Color(tint.r, tint.g, tint.b, tint.a));
				}
				p_indices.resize(indices.size());
				for (size_t j = 0; j < indices.size(); ++j) {
					p_indices.set(j, indices[j]);
				}

				godot::VisualServer::get_singleton()->canvas_item_add_triangle_array(mesh_ins->get_canvas_item(),
						p_indices,
						p_points,
						p_colors,
						p_uvs,
						godot::PoolIntArray(),
						godot::PoolRealArray(),
						tex.is_null() ? godot::RID() : tex->get_rid(),
						-1,
						normal_tex.is_null() ? godot::RID() : normal_tex->get_rid());
			}
		}
		skeleton_clipper->clipEnd(*slot);

		if (mesh_ins->get_material()->is_class("CanvasItemMaterial")) {
			godot::Ref<godot::CanvasItemMaterial> mat = mesh_ins->get_material();
			godot::CanvasItemMaterial::BlendMode blend_mode;
			switch (slot->getData().getBlendMode()) {
				case spine::BlendMode_Normal:
					blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MIX;
					break;
				case spine::BlendMode_Additive:
					blend_mode = godot::CanvasItemMaterial::BLEND_MODE_ADD;
					break;
				case spine::BlendMode_Multiply:
					blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MUL;
					break;
				case spine::BlendMode_Screen:
					blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MIX;
					break;
				default:
					blend_mode = godot::CanvasItemMaterial::BLEND_MODE_MIX;
			}
			mat->set_blend_mode(blend_mode);
		}
	}
	skeleton_clipper->clipEnd();
}

void SpineSprite::callback(spine::AnimationState *state, spine::EventType type, spine::TrackEntry *entry, spine::Event *event) {
	godot::Ref<SpineTrackEntry> gd_entry;
	godot::Ref<SpineEvent> gd_event;

	if (entry) {
		gd_entry.instance();
		gd_entry->set_spine_object(entry);
	}
	if (event) {
		gd_event.instance();
		gd_event->set_spine_object(event);
	}

	switch (type) {
		case spine::EventType_Start: {
			emit_signal("animation_start", animation_state, gd_entry, gd_event);
		} break;
		case spine::EventType_Interrupt: {
			emit_signal("animation_interrupt", animation_state, gd_entry, gd_event);
		} break;
		case spine::EventType_End: {
			emit_signal("animation_end", animation_state, gd_entry, gd_event);
		} break;
		case spine::EventType_Complete: {
			emit_signal("animation_complete", animation_state, gd_entry, gd_event);
		} break;
		case spine::EventType_Dispose: {
			emit_signal("animation_dispose", animation_state, gd_entry, gd_event);
		} break;
		case spine::EventType_Event: {
			emit_signal("animation_event", animation_state, gd_entry, gd_event);
		} break;
	}
}

// External feature functions
godot::Array SpineSprite::get_current_animations() {
	return current_animations.duplicate(true);
}

void SpineSprite::set_current_animations(godot::Array as) {
	current_animations = as.duplicate(true);

	// validate it then play the animations
	_validate_and_play_current_animations();
}

int SpineSprite::get_select_track_id() {
	return select_track_id;
}

void SpineSprite::set_select_track_id(int v) {
	select_track_id = v;

	if (select_track_id < 0)
		select_track_id = 0;
}

bool SpineSprite::get_clear_track() {
	return false;
}

void SpineSprite::set_clear_track(bool v) {
	if (v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->clear_track(select_track_id);
}

bool SpineSprite::get_clear_tracks() {
	return false;
}

void SpineSprite::set_clear_tracks(bool v) {
	if (v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->clear_tracks();
}

float SpineSprite::get_empty_animation_duration() {
	return empty_animation_duration;
}

void SpineSprite::set_empty_animation_duration(float v) {
	empty_animation_duration = v;
}

bool SpineSprite::get_set_empty_animation() {
	return false;
}

void SpineSprite::set_set_empty_animation(bool v) {
	if (v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->set_empty_animation(select_track_id, empty_animation_duration);
}

bool SpineSprite::get_set_empty_animations() {
	return false;
}

void SpineSprite::set_set_empty_animations(bool v) {
	if (v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->set_empty_animations(empty_animation_duration);
}

godot::Array SpineSprite::get_bind_slot_nodes() {
	return bind_slot_nodes;
}

void SpineSprite::set_bind_slot_nodes(godot::Array v) {
	bind_slot_nodes = v;
}

bool SpineSprite::get_overlap() {
	return overlap;
}

void SpineSprite::set_overlap(bool v) {
	overlap = v;
}

void SpineSprite::set_skin(godot::Ref<PackedSpineSkinResource> v) {
	if (v != skin && skin.is_valid()) {
		if (skin->is_connected("property_changed", this, "_on_skin_property_changed"))
			skin->disconnect("property_changed", this, "_on_skin_property_changed");
	}

	skin = v;

	if (skin.is_valid()) {
		if (!skin->is_connected("property_changed", this, "_on_skin_property_changed"))
			skin->connect("property_changed", this, "_on_skin_property_changed");
		update_runtime_skin();
	}
}

godot::Ref<PackedSpineSkinResource> SpineSprite::get_skin() {
	return skin;
}

void SpineSprite::update_runtime_skin() {
	auto new_skin = gen_spine_skin_from_packed_resource(skin);

	if (new_skin.is_valid()) {
		skeleton->set_skin(new_skin);
		skeleton->set_to_setup_pose();
	}
}

void SpineSprite::_on_skin_property_changed() {
	update_runtime_skin();
}

godot::Ref<SpineSkin> SpineSprite::gen_spine_skin_from_packed_resource(godot::Ref<PackedSpineSkinResource> res) {
	if (!(animation_state.is_valid() && skeleton.is_valid()))
		return NULL;
	if (!res.is_valid())
		return NULL;
	if (res->get_skin_name().empty())
		return NULL;
	auto exist_skin = animation_state_data_res->get_skeleton()->find_skin(res->get_skin_name());
	if (exist_skin.is_valid()) {
		return exist_skin;
	}

	godot::Ref<SpineSkin> new_skin;
	new_skin.instance();
	new_skin->init(res->get_skin_name());
	auto sub_skin_names = res->get_sub_skin_names();
	for (size_t i = 0; i < sub_skin_names.size(); ++i) {
		auto skin_name = (godot::String)sub_skin_names[i];
		auto sub_skin = animation_state_data_res->get_skeleton()->find_skin(skin_name);
		if (sub_skin.is_valid())
			new_skin->add_skin(sub_skin);
	}
	return new_skin;
}

void SpineSprite::bind_slot_with_node_2d(const godot::String &slot_name, Node2D *n) {
	auto node_path = n->get_path_to(this);

	// check if has the same binding
	for (size_t i = 0, size = bind_slot_nodes.size(); i < size; ++i) {
		auto a = bind_slot_nodes[i];
		if (a.get_type() == godot::Variant::DICTIONARY) {
			auto d = (godot::Dictionary)a;
			if (d.has("slot_name") && d.has("node_path")) {
				if (slot_name == d["slot_name"] && node_path == d["node_path"]) {
					return;
				}
			}
		} else if (a.get_type() == godot::Variant::ARRAY) {
			auto as = (godot::Array)a;
			if (as.size() >= 2 && as[0].get_type() == godot::Variant::STRING && as[1].get_type() == godot::Variant::NODE_PATH) {
				if (slot_name == as[0] && node_path == as[1]) {
					return;
				}
			}
		}
	}

	godot::Array bound;
	bound.resize(2);
	bound[0] = slot_name;
	bound[1] = node_path;

	bind_slot_nodes.append(bound);
}

void SpineSprite::unbind_slot_with_node_2d(const godot::String &slot_name, Node2D *n) {
	auto node_path = n->get_path_to(this);

	for (size_t i = 0, size = bind_slot_nodes.size(); i < size; ++i) {
		auto a = bind_slot_nodes[i];
		if (a.get_type() == godot::Variant::DICTIONARY) {
			auto d = (godot::Dictionary)a;
			if (d.has("slot_name") && d.has("node_path")) {
				if (slot_name == d["slot_name"] && node_path == d["node_path"]) {
					bind_slot_nodes.remove(i);
					return;
				}
			}
		} else if (a.get_type() == godot::Variant::ARRAY) {
			auto as = (godot::Array)a;
			if (as.size() >= 2 && as[0].get_type() == godot::Variant::STRING && as[1].get_type() == godot::Variant::NODE_PATH) {
				if (slot_name == as[0] && node_path == as[1]) {
					bind_slot_nodes.remove(i);
					return;
				}
			}
		}
	}
}

godot::Transform2D SpineSprite::bone_get_global_transform(const godot::String &bone_name) {
	if (!animation_state.is_valid() && !skeleton.is_valid()) {
		return get_global_transform();
	}
	auto bone = skeleton->find_bone(bone_name);
	if (!bone.is_valid()) {
		godot::String message = "Bone: '" + bone_name + "' not found.";
		godot_print_error(message.utf8().get_data(), __FUNCTION__, __FILE__, __LINE__);
		return get_global_transform();
	}
	return bone->get_godot_global_transform();
}

void SpineSprite::bone_set_global_transform(const godot::String &bone_name, godot::Transform2D transform) {
	if (!animation_state.is_valid() && !skeleton.is_valid()) {
		return;
	}
	auto bone = skeleton->find_bone(bone_name);
	if (!bone.is_valid()) {
		return;
	}
	bone->set_godot_global_transform(transform);
}

int SpineSprite::get_process_mode() {
	return process_mode;
}

void SpineSprite::set_process_mode(int v) {
	process_mode = SpineSprite::ProcessMode(v);
	set_process_internal(process_mode == ProcessMode_Process);
	set_physics_process_internal(process_mode == ProcessMode_Physics);
}

godot::Array SpineSprite::_get_property_list() const {
	godot::Array list;

	list.push_back(godot::Dictionary::make("type", godot::Variant::NIL, "name", "Current Animation Editor", "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_CATEGORY));
	list.push_back(godot::Dictionary::make("type", godot::Variant::BOOL, "name", "setup_pose_trigger", "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));
	list.push_back(godot::Dictionary::make("type", godot::Variant::BOOL, "name", "clear_tracks_trigger", "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));
	list.push_back(godot::Dictionary::make("type", godot::Variant::BOOL, "name", "set_empty_animations_trigger", "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));
	list.push_back(godot::Dictionary::make("type", godot::Variant::REAL, "name", "empty_animation_duration"));
	list.push_back(godot::Dictionary::make("type", godot::Variant::INT, "name", "track_count", "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));

	for (size_t i = 0; i < current_animations.size(); ++i) {
		godot::String prefix = "ca/" + i + '/';
		list.push_back(godot::Dictionary::make("type", godot::Variant::NIL, "name", godot::String("ID " + i), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", prefix, "usage_flags", GODOT_PROPERTY_USAGE_GROUP));
		list.push_back(godot::Dictionary::make("type", godot::Variant::INT, "name", godot::String(prefix + "track_id"), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));

		godot::PoolStringArray anim_list;
		if (skeleton.is_valid() && skeleton->get_data().is_valid()) {
			skeleton->get_data()->get_animation_names(anim_list);
		}
		if (anim_list.size() == 0)
			anim_list.push_back("No Animation");

		godot::String hint_string;
		for (int i = 0; i < anim_list.size(); ++i) {
			hint_string += anim_list[i];
			if (i < anim_list.size() - 1) {
				hint_string += ",";
			}
		}
		list.push_back(godot::Dictionary::make("type", godot::Variant::STRING, "name", godot::String(prefix + "animation"), "hint", GODOT_PROPERTY_HINT_ENUM, "hint_string", hint_string, "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));

		list.push_back(godot::Dictionary::make("type", godot::Variant::REAL, "name", godot::String(prefix + "delay"), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));

		list.push_back(godot::Dictionary::make("type", godot::Variant::BOOL, "name", godot::String(prefix + "loop"), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));

		list.push_back(godot::Dictionary::make("type", godot::Variant::BOOL, "name", godot::String(prefix + "empty"), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));
		list.push_back(godot::Dictionary::make("type", godot::Variant::REAL, "name", godot::String(prefix + "empty_animation_duration"), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));

		list.push_back(godot::Dictionary::make("type", godot::Variant::BOOL, "name", godot::String(prefix + "clear"), "hint", GODOT_PROPERTY_HINT_NONE, "hint_string", "", "usage_flags", GODOT_PROPERTY_USAGE_EDITOR));
	}

	return list;
}

godot::Variant SpineSprite::_get(const godot::String &p_property) const {
	if (p_property == "setup_pose_trigger" || p_property == "clear_tracks_trigger" || p_property == "set_empty_animations_trigger") {
		return false;
	}
	if (p_property == "empty_animation_duration") {
		return empty_animation_duration;
	}
	if (p_property == "track_count") {
		return get_current_animation_count();
	}
	godot::String p = p_property;
	if (p.length() > 2 && p[0] == 'c' && p[1] == 'a' && p[2] == '/') {
		godot::PoolStringArray sp = p.split("/");
		if (sp.size() > 2) {
			int64_t id = sp[1].to_int();
			if (id >= 0 && id < current_animations.size()) {
				auto &key = sp[2];
				if (current_animations[id].get_type() == godot::Variant::DICTIONARY) {
					godot::Dictionary dic = current_animations[id];
					if (dic.has(key)) {
						return dic[key];
					} else {
						if (key == "track_id")
							return 0;
						else if (key == "animation")
							return "";
						else if (key == "loop")
							return true;
						else if (key == "empty")
							return false;
						else if (key == "empty_animation_duration")
							return 0.3;
						else if (key == "clear")
							return false;
						else if (key == "delay")
							return 0;
						else {
						godot:
							Object *nothing = nullptr;
							return nothing;
						}
					}
				}
			}
		}
	}

	godot::Object *nothing = nullptr;
	return nothing;
}

bool SpineSprite::_set(const godot::String &p_property, const godot::Variant &p_value) {
	if (p_property == "setup_pose_trigger") {
		if (p_value) {
			if (skeleton.is_valid()) {
				skeleton->set_bones_to_setup_pose();
				skeleton->set_slots_to_setup_pose();
			}
		}
		return true;
	}
	if (p_property == "clear_tracks_trigger") {
		if (p_value) {
			if (animation_state.is_valid() && skeleton.is_valid()) {
				animation_state->clear_tracks();
			}
		}
		return true;
	}
	if (p_property == "set_empty_animations_trigger") {
		if (p_value) {
			if (animation_state.is_valid() && skeleton.is_valid()) {
				animation_state->set_empty_animations(empty_animation_duration);
			}
		}
		return true;
	}
	if (p_property == "empty_animation_duration") {
		empty_animation_duration = p_value;
		return true;
	}
	if (p_property == "track_count") {
		set_current_animation_count(p_value);
		return true;
	}
	godot::String p = p_property;
	if (p.length() > 2 && p[0] == 'c' && p[1] == 'a' && p[2] == '/') {
		godot::PoolStringArray sp = p.split("/");
		if (sp.size() > 2) {
			int64_t id = sp[1].to_int();
			if (id >= 0 && id < current_animations.size()) {
				auto &key = sp[2];
				if (current_animations[id].get_type() != godot::Variant::DICTIONARY) {
					current_animations[id] = godot::Dictionary();
				}

				godot::Dictionary dic = current_animations[id];
				dic[key] = p_value;

				_validate_and_play_current_animations();
				return true;
			}
		}
	}
	return false;
}

int64_t SpineSprite::get_current_animation_count() const {
	return current_animations.size();
}

void SpineSprite::set_current_animation_count(int64_t v) {
	if (v < 0)
		v = 0;
	while (current_animations.size() < v) {
		godot::Dictionary d;
		d["track_id"] = current_animations.size();
		d["animation"] = "";
		d["delay"] = 0;
		d["loop"] = true;
		d["empty"] = false;
		d["empty_animation_duration"] = 0.3;
		d["clear"] = false;
		current_animations.push_back(d);
	}
	while (current_animations.size() > v) {
		if (animation_state.is_valid() && skeleton.is_valid()) {
			if (current_animations.back().get_type() == godot::Variant::DICTIONARY) {
				godot::Dictionary back = current_animations.back();
				if (back.has("track_id")) {
					int64_t track_id = back["track_id"];
					int track_cnt = 0;
					for (size_t i = 0; i < current_animations.size(); ++i) {
						if (current_animations[i].get_type() == godot::Variant::DICTIONARY) {
							godot::Dictionary d = current_animations[i];
							if (d.has("track_id") && track_id == (int64_t)d["track_id"]) {
								track_cnt += 1;
							}
						}
					}
					if (track_cnt == 0)
						animation_state->clear_track(track_id);
				}
			}
		}
		current_animations.pop_back();
	}
	property_list_changed_notify();
}

void SpineSprite::_validate_and_play_current_animations() {
	if (animation_state.is_valid() && skeleton.is_valid()) {
		int64_t track_cnt = 0;
		godot::Dictionary has_track;
		for (size_t i = 0; i < current_animations.size(); ++i) {
			auto a = current_animations[i];
			if (a.get_type() == godot::Variant::DICTIONARY) {
				godot::Dictionary d = a;

				int64_t track_id = 0;
				godot::String animation = "";
				float delay = 0;
				bool loop = true;
				bool empty = false;
				float empty_animation_duration = 0.3;
				bool clear = false;

				if (d.has("track_id"))
					track_id = d["track_id"];
				if (d.has("animation"))
					animation = d["animation"];
				if (d.has("delay"))
					delay = d["delay"];
				if (d.has("loop"))
					loop = d["loop"];
				if (d.has("empty"))
					empty = d["empty"];
				if (d.has("empty_animation_duration"))
					empty_animation_duration = d["empty_animation_duration"];
				if (d.has("clear"))
					clear = d["clear"];

				if (track_id < 0) {
					godot::String message = "track_id at 'ID " + i;
					message += "' can not be less than 0!";
					godot::Godot::print(message);
					continue;
				}

				track_cnt += 1;

				if (empty) {
					if (has_track.has(track_id))
						animation_state->add_empty_animation(track_id, empty_animation_duration, delay);
					else
						animation_state->set_empty_animation(track_id, empty_animation_duration);
					has_track[track_id] = true;
				} else if (clear) {
					animation_state->clear_track(track_id);
				} else if (skeleton->get_data()->find_animation(animation).is_valid()) {
					if (has_track.has(track_id))
						animation_state->add_animation(animation, delay, loop, track_id);
					else
						animation_state->set_animation(animation, loop, track_id);
					has_track[track_id] = true;
				}
			}
		}

		if (track_cnt == 0)
			animation_state->clear_tracks();
	}
}
