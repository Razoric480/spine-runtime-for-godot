#ifndef SCENE_TREE_DIALOG_H
#define SCENE_TREE_DIALOG_H

#include <Godot.hpp>
#include <Texture.hpp>
#include <ConfirmationDialog.hpp>
#include <LineEdit.hpp>
#include <Tree.hpp>

namespace godot {

class SceneTreeDialog : public ConfirmationDialog {
	GODOT_CLASS(SceneTreeDialog, ConfirmationDialog);

	Tree *tree;
	LineEdit *filter;
	PoolStringArray valid_types;

	void update_tree();
	void _select();
	void _cancel();
	void _filter_changed(const String &p_filter);
	
	bool _add_nodes(Node *p_node, TreeItem *p_parent);
	void _update_tree();

protected:
	void _notification(int p_what);
	static void _register_methods();

public:
	Tree *get_scene_tree() { return tree; }
	void set_valid_types(PoolStringArray p_valid_types);
	void _init();
	LineEdit *get_filter_line_edit() { return filter; }
	SceneTreeDialog();
	~SceneTreeDialog();
};

} //namespace godot

#endif /* SCENE_TREE_DIALOG_H */
