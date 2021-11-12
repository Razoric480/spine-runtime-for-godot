#include "SceneTreeDialog.h"

#include <VBoxContainer.hpp>
#include <Engine.hpp>
#include <SceneTree.hpp>
#include <TreeItem.hpp>

namespace godot {

void SceneTreeDialog::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_ENTER_TREE: {
			connect("confirmed", this, "_select");
			filter->set_right_icon(get_icon("Search", "EditorIcons"));
			filter->set_clear_button_enabled(true);
		} break;
		case NOTIFICATION_EXIT_TREE: {
			disconnect("confirmed", this, "_select");
		} break;
		case NOTIFICATION_VISIBILITY_CHANGED: {
			if (is_visible_in_tree()) {
				update_tree();
			}
		} break;
	}
}

void SceneTreeDialog::_cancel() {
	hide();
}

void SceneTreeDialog::_select() {
	if (tree->get_selected()) {
		NodePath np = tree->get_selected()->get_metadata(0);
		emit_signal("selected", get_node(np));
		hide();
	}
}

void SceneTreeDialog::_update_tree() {
	tree->clear();
	SceneTree *scene = (SceneTree *)Engine::get_singleton()->get_main_loop();
	_add_nodes(scene->get_edited_scene_root(), nullptr);
}

void SceneTreeDialog::_filter_changed(const String &p_filter) {
	update_tree();
}

bool SceneTreeDialog::_add_nodes(Node *p_node, TreeItem *p_parent) {
	if (!p_node) {
		return false;
	}

	TreeItem *item = tree->create_item((Object *)p_parent);
	item->set_text(0, p_node->get_name());
	item->set_selectable(0, true);
	item->set_metadata(0, p_node->get_path());

	bool keep = filter->get_text().is_subsequence_ofi(String(p_node->get_name()));
	for (int i = 0; i < p_node->get_child_count(); ++i) {
		bool child_keep = _add_nodes(p_node->get_child(i), item);

		keep = keep || child_keep;
	}

	if (!keep) {
		item->free();
		return false;
	} else {
		return true;
	}
}

void SceneTreeDialog::set_valid_types(PoolStringArray p_valid_types) {
	valid_types = p_valid_types;
}

void SceneTreeDialog::_register_methods() {
	register_method("_select", &SceneTreeDialog::_select);
	register_method("_cancel", &SceneTreeDialog::_cancel);
	register_method("_filter_changed", &SceneTreeDialog::_filter_changed);
	register_method("get_scene_tree", &SceneTreeDialog::get_scene_tree);

	register_signal<SceneTreeDialog>("selected", "path");
}

void SceneTreeDialog::_init() {
	set_title("Select a Node");
	VBoxContainer *vbc = VBoxContainer::_new();
	add_child(vbc);

	filter = LineEdit::_new();
	filter->set_h_size_flags(SIZE_EXPAND_FILL);
	filter->set_placeholder("Filter nodes");
	filter->add_constant_override("minimum_spaces", 0);
	filter->connect("text_changed", this, "_filter_changed");
	vbc->add_child(filter);

	tree = Tree::_new();
	tree->set_v_size_flags(SIZE_EXPAND_FILL);
	tree->connect("item_activated", this, "_select");
	vbc->add_child(tree);
}

SceneTreeDialog::SceneTreeDialog() {
}

SceneTreeDialog::~SceneTreeDialog() {
}

} //namespace godot