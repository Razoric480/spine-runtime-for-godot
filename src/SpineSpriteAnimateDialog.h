//
// Created by Raiix on 2021/7/16.
//

#ifndef GODOT_SPINESPRITEANIMATEDIALOG_H
#define GODOT_SPINESPRITEANIMATEDIALOG_H

#include <Godot.hpp>
#include <AcceptDialog.hpp>
#include <ToolButton.hpp>
#include <EditorPlugin.hpp>
#include <ConfirmationDialog.hpp>
#include <Tree.hpp>
#include <AnimationPlayer.hpp>
#include <SceneTree.hpp>

class SpineSprite;

class SpineSpriteAnimateDialog : public godot::Control {
    GODOT_CLASS(SpineSpriteAnimateDialog, godot::Control);

protected:
    static void _register_methods();

    godot::AcceptDialog *error_dialog;

    godot::ToolButton *animate_button;
    godot::EditorPlugin *the_plugin;

    godot::ConfirmationDialog *animate_dialog;
    godot::Button *animate_dialog_override_button;
    godot::Tree *animate_dialog_tree;
    godot::Variant *scene_tree_dialog;

    godot::NodePath spine_sprite_path;
    godot::NodePath anim_player_path;

    void add_row(const godot::String &animation, bool loop=true, int64_t track_id=0);
    void clear_tree();

    void error(const godot::String &text, const godot::String &title="Error");

    void load_data_from_sprite(SpineSprite *sprite, bool &err);
    void load_data_from_anim_player(godot::AnimationPlayer *anim_player, bool &err);

    godot::Dictionary get_data_from_tree();

    void gen_new_animation_player(SpineSprite *sprite, bool &err);
    void gen_animations(SpineSprite *sprite, godot::AnimationPlayer *anim_player, const godot::Dictionary &config, float min_duration, bool &err);
    godot::Dictionary gen_current_animation_data(const godot::String &animation, int64_t track_id, bool loop, bool clear, bool empty, bool empty_duration, float delay);
public:
    SpineSpriteAnimateDialog();
    ~SpineSpriteAnimateDialog();

    void set_animate_button(godot::ToolButton *b);
    inline godot::ToolButton *get_animate_button() {return animate_button;}

    inline void set_plugin(godot::EditorPlugin *p) {the_plugin = p;}

    void _on_animate_button_pressed();
    void _on_scene_tree_selected(godot::NodePath path);
    void _on_scene_tree_hide();
    void _on_animate_dialog_action(const godot::String &act);
};

#endif //GODOT_SPINESPRITEANIMATEDIALOG_H
