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
	static void _register_methods() {
		godot::register_method("get_importer_name", &SpineAtlasResourceImportPlugin::get_importer_name);
		godot::register_method("get_visible_name", &SpineAtlasResourceImportPlugin::get_visible_name);
		godot::register_method("get_recognized_extensions", &SpineAtlasResourceImportPlugin::get_recognized_extensions);
		godot::register_method("get_preset_name", &SpineAtlasResourceImportPlugin::get_preset_name);
		godot::register_method("get_preset_count", &SpineAtlasResourceImportPlugin::get_preset_count);
		godot::register_method("get_save_extension", &SpineAtlasResourceImportPlugin::get_save_extension);
		godot::register_method("get_resource_type", &SpineAtlasResourceImportPlugin::get_resource_type);
		godot::register_method("get_import_options", &SpineAtlasResourceImportPlugin::get_import_options);
		godot::register_method("get_option_visibility", &SpineAtlasResourceImportPlugin::get_option_visibility);
		godot::register_method("import", &SpineAtlasResourceImportPlugin::import);
	}

public:
	void _init() {}

	godot::String get_importer_name() const { return "raiix.spine_runtime.atlas"; }
	godot::String get_visible_name() const { return "Spine Runtime Atlas"; }
	godot::Array get_recognized_extensions() const {
		godot::Array extensions;
		extensions.push_back("atlas");
		return extensions;
	}

	godot::String get_preset_name(int p_idx) const {
		if (p_idx == 0)
			return "Default";
		else
			return "Unknown";
	}
	int get_preset_count() const { return 1; }
	godot::String get_save_extension() const { return "spatlas"; }
	godot::String get_resource_type() const { return "SpineAtlasResource"; }
	godot::Array get_import_options(int p_preset) const;
	bool get_option_visibility(const godot::String &p_option, const godot::Dictionary &p_options) const { return true; }
	int import(const godot::String &p_source_file, const godot::String &p_save_path, const godot::Dictionary &p_options, godot::Array r_platform_variants, godot::Array r_gen_files);
};

class SpineJsonResourceImportPlugin : public godot::EditorImportPlugin {
	GODOT_CLASS(SpineJsonResourceImportPlugin, godot::EditorImportPlugin);

public:
	static void _register_methods() {
		godot::register_method("get_importer_name", &SpineJsonResourceImportPlugin::get_importer_name);
		godot::register_method("get_visible_name", &SpineJsonResourceImportPlugin::get_visible_name);
		godot::register_method("get_recognized_extensions", &SpineJsonResourceImportPlugin::get_recognized_extensions);
		godot::register_method("get_preset_name", &SpineJsonResourceImportPlugin::get_preset_name);
		godot::register_method("get_preset_count", &SpineJsonResourceImportPlugin::get_preset_count);
		godot::register_method("get_save_extension", &SpineJsonResourceImportPlugin::get_save_extension);
		godot::register_method("get_resource_type", &SpineJsonResourceImportPlugin::get_resource_type);
		godot::register_method("get_import_options", &SpineJsonResourceImportPlugin::get_import_options);
		godot::register_method("get_option_visibility", &SpineJsonResourceImportPlugin::get_option_visibility);
		godot::register_method("import", &SpineJsonResourceImportPlugin::import);
	}

public:
	void _init() {}

	godot::String get_importer_name() const { return "raiix.spine_runtime.json"; }
	godot::String get_visible_name() const { return "Spine Runtime Json"; }
	godot::Array get_recognized_extensions() const {
		godot::Array extensions;
		extensions.push_back("json");
		return extensions;
	}
	godot::String get_preset_name(int p_idx) const {
		if (p_idx == 0)
			return "Default";
		else
			return "Unknown";
	}
	int get_preset_count() const { return 1; }
	godot::String get_save_extension() const { return "spjson"; }
	godot::String get_resource_type() const { return "SpineSkeletonJsonDataResource"; }
	godot::Array get_import_options(int p_preset) const { return godot::Array(); }
	bool get_option_visibility(const godot::String &p_option, const godot::Dictionary &p_options) const { return true; }
	int import(const godot::String &p_source_file, const godot::String &p_save_path, const godot::Dictionary &p_options, godot::Array r_platform_variants, godot::Array r_gen_files);
};

class SpineSpriteAnimateDialog;

class SpineRuntimeEditorPlugin : public godot::EditorPlugin {
	GODOT_CLASS(SpineRuntimeEditorPlugin, godot::EditorPlugin);

protected:
	SpineSpriteAnimateDialog *animate_dialog;

public:
	static void _register_methods() {
		godot::register_method("get_name", &SpineRuntimeEditorPlugin::get_name);
		godot::register_method("handles", &SpineRuntimeEditorPlugin::handles);
		godot::register_method("make_visible", &SpineRuntimeEditorPlugin::make_visible);
		godot::register_method("has_main_screen", &SpineRuntimeEditorPlugin::has_main_screen);
	}

public:
	SpineRuntimeEditorPlugin();
	~SpineRuntimeEditorPlugin();

	void _init();

	godot::String get_name() const { return "SpineRuntimeEditorPlugin"; }
	bool has_main_screen() const { return false; }

	bool handles(godot::Object *p_object) const;
	void make_visible(bool p_visible);

	void _on_animate_button_pressed();
};

#endif //GODOT_SPINERUNTIMEEDITORPLUGIN_H
