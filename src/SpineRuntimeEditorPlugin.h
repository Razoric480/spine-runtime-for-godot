//
// Created by Raiix on 2021/7/13.
//

#ifndef GODOT_SPINERUNTIMEEDITORPLUGIN_H
#define GODOT_SPINERUNTIMEEDITORPLUGIN_H

#include <godot_cpp/classes/editor_import_plugin.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>

namespace godot {

class SpineAtlasResourceImportPlugin : public EditorImportPlugin {
	GDCLASS(SpineAtlasResourceImportPlugin, EditorImportPlugin);

protected:
	static void _bind_methods();

public:
	String get_importer_name() const { return "raiix.spine_runtime.atlas"; }
	String get_visible_name() const { return "Spine Runtime Atlas"; }
	PackedStringArray get_recognized_extensions() const {
		PackedStringArray extensions;
		extensions.push_back("atlas");
		return extensions;
	}
	String get_preset_name(int p_idx) const {
		if (p_idx == 0)
			return "Default";
		else
			return "Unknown";
	}
	int get_preset_count() const { return 1; }
	String get_save_extension() const { return "spatlas"; }
	String get_resource_type() const { return "SpineAtlasResource"; }
	Array get_import_options(const String &p_path, int p_preset) const;
	bool get_option_visibility(const String &path, const StringName &option_name, const Dictionary &options) const { return true; }
	Error import(const String &source_file, const String &save_path, const Dictionary &options, const Array &platform_variants, const Array &gen_files);
};

class SpineJsonResourceImportPlugin : public EditorImportPlugin {
	GDCLASS(SpineJsonResourceImportPlugin, EditorImportPlugin);

protected:
	static void _bind_methods();

public:
	String get_importer_name() const { return "raiix.spine_runtime.json"; }
	String get_visible_name() const { return "Spine Runtime Json"; }
	PackedStringArray get_recognized_extensions() const {
		PackedStringArray extensions;
		extensions.push_back("json");
		return extensions;
	}
	String get_preset_name(int p_idx) const {
		if (p_idx == 0)
			return "Default";
		else
			return "Unknown";
	}
	int get_preset_count() const { return 1; }
	String get_save_extension() const { return "spjson"; }
	String get_resource_type() const { return "SpineSkeletonJsonDataResource"; }
	Array get_import_options(const String &p_path, int p_preset) const { return Array(); }
	bool get_option_visibility(const String &path, const StringName &option_name, const Dictionary &options) const { return true; }
	Error import(const String &source_file, const String &save_path, const Dictionary &options, const Array &platform_variants, const Array &gen_files);
};

class SpineSpriteAnimateDialog;

class SpineRuntimeEditorPlugin : public EditorPlugin {
	GDCLASS(SpineRuntimeEditorPlugin, EditorPlugin);

protected:
	SpineSpriteAnimateDialog *animate_dialog;

protected:
	static void _bind_methods();

public:
	SpineRuntimeEditorPlugin();
	~SpineRuntimeEditorPlugin();

	String get_name() const { return "SpineRuntimeEditorPlugin"; }
	bool has_main_screen() const { return false; }

	bool handles(Object *p_object) const;
	void make_visible(bool p_visible);

	void _on_animate_button_pressed();
};

} //namespace godot

#endif //GODOT_SPINERUNTIMEEDITORPLUGIN_H
