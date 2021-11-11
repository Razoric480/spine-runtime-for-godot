//
// Created by Raiix on 2021/7/13.
// Edited by Razoric on 2021/11/xx
//

#ifndef GODOT_SPINERUNTIMEEDITORPLUGIN_H
#define GODOT_SPINERUNTIMEEDITORPLUGIN_H

#include <EditorImportPlugin.hpp>
#include <EditorPlugin.hpp>
#include <Godot.hpp>


class SpineAtlasResourceImportPlugin : public godot::EditorImportPlugin {
	GODOT_CLASS(SpineAtlasResourceImportPlugin, godot::EditorImportPlugin);

public:
	godot::String get_importer_name() const { return "raiix.spine_runtime.atlas"; }
	godot::String get_visible_name() const { return "Spine Runtime Atlas"; }
	void get_recognized_extensions(godot::PoolStringArray *p_extensions) const { p_extensions->push_back("atlas"); }
	godot::String get_preset_name(int p_idx) const {
		if (p_idx == 0)
			return "Default";
		else
			return "Unknown";
	}
	int get_preset_count() const { return 1; }
	godot::String get_save_extension() const { return "spatlas"; }
	godot::String get_resource_type() const { return "SpineAtlasResource"; }
	void get_import_options(godot::Array *r_options, int p_preset) const;
	bool get_option_visibility(const godot::String &p_option, const godot::Dictionary &p_options) const { return true; }
	godot::Error import(const godot::String &p_source_file, const godot::String &p_save_path, const godot::Dictionary &p_options, godot::PoolStringArray *r_platform_variants, godot::PoolStringArray *r_gen_files, godot::Variant *r_metadata);
};

class SpineJsonResourceImportPlugin : public godot::EditorImportPlugin {
	GODOT_CLASS(SpineJsonResourceImportPlugin, godot::EditorImportPlugin);

public:
	godot::String get_importer_name() const { return "raiix.spine_runtime.json"; }
	godot::String get_visible_name() const { return "Spine Runtime Json"; }
	void get_recognized_extensions(godot::PoolStringArray *p_extensions) const { p_extensions->push_back("json"); }
	godot::String get_preset_name(int p_idx) const {
		if (p_idx == 0)
			return "Default";
		else
			return "Unknown";
	}
	int get_preset_count() const { return 1; }
	godot::String get_save_extension() const { return "spjson"; }
	godot::String get_resource_type() const { return "SpineSkeletonJsonDataResource"; }
	void get_import_options(godot::Array *r_options, int p_preset) const {}
	bool get_option_visibility(const godot::String &p_option, const godot::Dictionary &p_options) const { return true; }
	godot::Error import(const godot::String &p_source_file, const godot::String &p_save_path, const godot::Dictionary &p_options, godot::PoolStringArray *r_platform_variants, godot::PoolStringArray *r_gen_files, godot::Variant *r_metadata);
};

class SpineSpriteAnimateDialog;

class SpineRuntimeEditorPlugin : public godot::EditorPlugin {
	GODOT_CLASS(SpineRuntimeEditorPlugin, godot::EditorPlugin);

protected:
	SpineSpriteAnimateDialog *animate_dialog;

public:
	SpineRuntimeEditorPlugin(godot::Variant *p_node);
	~SpineRuntimeEditorPlugin();

	godot::String get_name() const { return "SpineRuntimeEditorPlugin"; }
	bool has_main_screen() const { return false; }

	bool handles(godot::Object *p_object) const;
	void make_visible(bool p_visible);

	void _on_animate_button_pressed();
};

#endif //GODOT_SPINERUNTIMEEDITORPLUGIN_H
