//
// Created by Raiix on 2021/7/13.
//

#ifndef GODOT_SPINERUNTIMEEDITORPLUGIN_H
#define GODOT_SPINERUNTIMEEDITORPLUGIN_H

#include <EditorImportPlugin.hpp>
#include <Godot.hpp>
#include <EditorPlugin.hpp>

//#ifdef TOOLS_ENABLED

namespace godot {

class SpineAtlasResourceImportPlugin : public EditorImportPlugin {
	GODOT_CLASS(SpineAtlasResourceImportPlugin, EditorImportPlugin);

public:
    static void _register_methods();
	void _init() {}

public:
	String get_importer_name() { return "raiix.spine_runtime.atlas"; }
	String get_visible_name() { return "Spine Runtime Atlas"; }
	Array get_recognized_extensions() { 
        Array extensions;
        extensions.push_back("atlas");
        return extensions;
    }
	String get_preset_name(const int64_t preset) {
		if (preset == 0)
			return "Default";
		else
			return "Unknown";
	}
	int64_t get_preset_count() { return 1; }
	String get_save_extension() { return "spatlas"; }
	String get_resource_type() { return "Resource"; }
	Array get_import_options(const int64_t preset);
	bool get_option_visibility(const String option, const Dictionary options) { return true; }
	int64_t import(const String source_file, const String save_path, const Dictionary options, const Array platform_variants, const Array gen_files);
};

class SpineJsonResourceImportPlugin : public EditorImportPlugin {
	GODOT_CLASS(SpineJsonResourceImportPlugin, EditorImportPlugin);

public:
    static void _register_methods();
	void _init() {}

public:
	String get_importer_name() { return "raiix.spine_runtime.json"; }
	String get_visible_name() { return "Spine Runtime Json"; }
	Array get_recognized_extensions() {
        Array extensions;
        extensions.push_back("json");
        return extensions;
    }
	String get_preset_name(const int64_t preset) {
		if (preset == 0)
			return "Default";
		else
			return "Unknown";
	}
	int64_t get_preset_count() { return 1; }
	String get_save_extension() { return "spjson"; }
	String get_resource_type() { return "Resource"; }
	Array get_import_options(const int64_t preset) { return Array(); }
	bool get_option_visibility(const String option, const Dictionary options) { return true; }
	int64_t import(const String source_file, const String save_path, const Dictionary options, const Array platform_variants, const Array gen_files);
};

class SpineSpriteAnimateDialog;

class SpineRuntimeEditorPlugin : public EditorPlugin {
	GODOT_CLASS(SpineRuntimeEditorPlugin, EditorPlugin);

public:
    static void _register_methods();
	void _init();

protected:
	SpineSpriteAnimateDialog *animate_dialog;
    ToolButton *animate_button;
    Ref<SpineAtlasResourceImportPlugin> atlas_importer;
    Ref<SpineJsonResourceImportPlugin> json_importer;

public:
	SpineRuntimeEditorPlugin();
	~SpineRuntimeEditorPlugin();

	String get_name() const { return "SpineRuntimeEditorPlugin"; }
	bool has_main_screen() { return false; }

	bool handles(const Object *object);
	void make_visible(const bool visible);

	void _on_animate_button_pressed();
};

//#endif

}

#endif //GODOT_SPINERUNTIMEEDITORPLUGIN_H
