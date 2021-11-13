//
// Created by Raiix on 2021/7/16.
// Edited by Razoric on 2021/11/xx
//

#ifndef GODOT_SPINESPRITEANIMATEDIALOG_H
#define GODOT_SPINESPRITEANIMATEDIALOG_H

#include "SceneTreeDialog.h"
#include <AcceptDialog.hpp>
#include <AnimationPlayer.hpp>
#include <ConfirmationDialog.hpp>
#include <EditorPlugin.hpp>
#include <Godot.hpp>
#include <ToolButton.hpp>
#include <Tree.hpp>


class SpineSprite;

class SpineSpriteAnimateDialog : public godot::Control {
	GODOT_CLASS(SpineSpriteAnimateDialog, godot::Control);

protected:
	godot::AcceptDialog *error_dialog;

	godot::ToolButton *animate_button;
	godot::EditorPlugin *the_plugin;

	godot::ConfirmationDialog *animate_dialog;
	godot::Button *animate_dialog_override_button;
	godot::Tree *animate_dialog_tree;
	godot::SceneTreeDialog *scene_tree_dialog;

	godot::NodePath spine_sprite_path;
	godot::NodePath anim_player_path;

	void add_row(const godot::String &animation, bool loop = true, int64_t track_id = 0);
	void clear_tree();

	void error(const godot::String &text, const godot::String &title = "Error");

	void load_data_from_sprite(SpineSprite *sprite, bool &err);
	void load_data_from_anim_player(godot::AnimationPlayer *anim_player, bool &err);

	godot::Dictionary get_data_from_tree();

	void gen_new_animation_player(SpineSprite *sprite, bool &err);
	void gen_animations(SpineSprite *sprite, godot::AnimationPlayer *anim_player, const godot::Dictionary &config, float min_duration, bool &err);
	godot::Dictionary gen_current_animation_data(const godot::String &animation, int64_t track_id, bool loop, bool clear, bool empty, bool empty_duration, float delay);

public:
	static void _register_methods();

	SpineSpriteAnimateDialog();
	~SpineSpriteAnimateDialog();

	void _init();

	void set_animate_button(godot::ToolButton *b);
	inline godot::ToolButton *get_animate_button() { return animate_button; }

	inline void set_plugin(godot::EditorPlugin *p) { the_plugin = p; }

	void _on_animate_button_pressed();
	void _on_scene_tree_selected(godot::NodePath path);
	void _on_scene_tree_hide();
	void _on_animate_dialog_action(const godot::String &act);
};

#endif //GODOT_SPINESPRITEANIMATEDIALOG_H
