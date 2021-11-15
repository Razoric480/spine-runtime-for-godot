#ifndef SCENE_TREE_DIALOG_H
#define SCENE_TREE_DIALOG_H

#include <ConfirmationDialog.hpp>
#include <Godot.hpp>
#include <LineEdit.hpp>
#include <Texture.hpp>
#include <Tree.hpp>

namespace godot {

class SceneTreeDialog : public ConfirmationDialog {
	GODOT_CLASS(SceneTreeDialog, ConfirmationDialog);

public:
	static void _register_methods();
	void _init();

	Tree *tree;
	LineEdit *filter;
	PoolStringArray valid_types;

public:
	void update_tree();
	void _select();
	void _cancel();
	void _filter_changed(const String &p_filter);
	Node *_get_scene_node();

	bool _add_nodes(Node *p_node, TreeItem *p_parent);
	void _update_tree();

	void _notification(int p_what);
	
	Tree *get_scene_tree() { return tree; }
	void set_valid_types(PoolStringArray p_valid_types);
	LineEdit *get_filter_line_edit() { return filter; }
	SceneTreeDialog();
	~SceneTreeDialog();
};

} //namespace godot

#endif /* SCENE_TREE_DIALOG_H */
