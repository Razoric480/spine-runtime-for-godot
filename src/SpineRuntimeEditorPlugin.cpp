//
// Created by Raiix on 2021/7/13.
// Edited by Razoric on 2021/11/xx
//

#include "SpineRuntimeEditorPlugin.h"

#include "SpineAtlasResource.h"
#include "SpineSkeletonJsonDataResource.h"
#include "SpineSpriteAnimateDialog.h"
#include <EditorInterface.hpp>
#include <EditorSelection.hpp>
#include <ResourceSaver.hpp>

#include "SpineSprite.h"

godot::Error SpineAtlasResourceImportPlugin::import(const godot::String &p_source_file, const godot::String &p_save_path, const godot::Dictionary &p_options, godot::Array r_platform_variants, godot::Array r_gen_files) {
	godot::Ref<SpineAtlasResource> res;
	res.instance();
	res->set_normal_texture_prefix(p_options["normal_texture_prefix"]);
	res->load_from_atlas_file(p_source_file);

	godot::String file_name = p_save_path + "." + get_save_extension();
	auto err = godot::ResourceSaver::get_singleton()->save(file_name, res);
	return err;
}

godot::Array SpineAtlasResourceImportPlugin::get_import_options(int p_preset) const {
	godot::Array options;
	if (p_preset == 0) {
		godot::Dictionary op;
		op["name"] = "normal_texture_prefix";
		op["type"] = godot::Variant::STRING;
		op["hint_string"] = "String";
		op["default_value"] = godot::String("n");
		options.push_back(op);
	}
	return options;
}

godot::Error SpineJsonResourceImportPlugin::import(const godot::String &p_source_file, const godot::String &p_save_path, const godot::Dictionary &p_options, godot::Array r_platform_variants, godot::Array r_gen_files) {
	godot::Ref<SpineSkeletonJsonDataResource> res;
	res.instance();
	res->load_from_file(p_source_file);

	godot::String file_name = p_save_path + "." + get_save_extension();
	auto err = godot::ResourceSaver::get_singleton()->save(file_name, res);
	return err;
}

//=======================| SpineRuntimeEditorPlugin |============================
SpineRuntimeEditorPlugin::SpineRuntimeEditorPlugin() {
	godot::Ref<SpineAtlasResourceImportPlugin> atlas_importer;
	atlas_importer.instance();
	godot::Ref<SpineJsonResourceImportPlugin> json_importer;
	json_importer.instance();
	add_import_plugin(atlas_importer);
	add_import_plugin(json_importer);

	godot::ToolButton *animate_button = godot::ToolButton::_new();
	animate_button->set_text("Animate");
	add_control_to_container(CONTAINER_CANVAS_EDITOR_MENU, animate_button);

	animate_dialog = SpineSpriteAnimateDialog::_new();
	get_editor_interface()->get_base_control()->add_child(animate_dialog);
	animate_dialog->set_animate_button(animate_button);
	animate_dialog->set_plugin(this);
}

void SpineRuntimeEditorPlugin::_init() {
}

SpineRuntimeEditorPlugin::~SpineRuntimeEditorPlugin() {
}

bool SpineRuntimeEditorPlugin::handles(Object *p_object) const {
	return p_object->is_class("SpineSprite");
}

void SpineRuntimeEditorPlugin::make_visible(bool p_visible) {
	if (get_editor_interface()->get_selection()->get_selected_nodes().size() != 1) {
		p_visible = false;
	}
	animate_dialog->get_animate_button()->set_visible(p_visible);
}
