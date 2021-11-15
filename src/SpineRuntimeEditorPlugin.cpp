//
// Created by Raiix on 2021/7/13.
//

//#ifdef TOOLS_ENABLED
#include "SpineRuntimeEditorPlugin.h"

#include "PackedSpineSkinResource.h"
#include "SpineAnimationState.h"
#include "SpineAnimationStateDataResource.h"
#include "SpineAtlasResource.h"
#include "SpineAttachment.h"
#include "SpineBoneData.h"
#include "SpineCollisionShapeProxy.h"
#include "SpineConstant.h"
#include "SpineConstraintData.h"
#include "SpineEvent.h"
#include "SpineEventData.h"
#include "SpineIkConstraintData.h"
#include "SpinePathConstraintData.h"
#include "SpineSkeleton.h"
#include "SpineSkeletonDataResource.h"
#include "SpineSkin.h"
#include "SpineSkinAttachmentMapEntries.h"
#include "SpineSlotData.h"
#include "SpineSprite.h"
#include "SpineSpriteAnimateDialog.h"
#include "SpineSpriteMeshInstance2D.h"
#include "SpineTimeline.h"
#include "SpineTrackEntry.h"
#include "SpineTransformConstraintData.h"

#include <EditorInterface.hpp>
#include <EditorSelection.hpp>
#include <ResourceSaver.hpp>
#include <Script.hpp>
#include <ToolButton.hpp>

namespace godot {

void SpineAtlasResourceImportPlugin::_register_methods() {
	register_method("get_importer_name", &SpineAtlasResourceImportPlugin::get_importer_name);
	register_method("get_visible_name", &SpineAtlasResourceImportPlugin::get_visible_name);
	register_method("get_recognized_extensions", &SpineAtlasResourceImportPlugin::get_recognized_extensions);
	register_method("get_preset_name", &SpineAtlasResourceImportPlugin::get_preset_name);
	register_method("get_preset_count", &SpineAtlasResourceImportPlugin::get_preset_count);
	register_method("get_save_extension", &SpineAtlasResourceImportPlugin::get_save_extension);
	register_method("get_resource_type", &SpineAtlasResourceImportPlugin::get_resource_type);
	register_method("get_import_options", &SpineAtlasResourceImportPlugin::get_import_options);
	register_method("get_option_visibility", &SpineAtlasResourceImportPlugin::get_option_visibility);
	register_method("import", &SpineAtlasResourceImportPlugin::import);
}

int64_t SpineAtlasResourceImportPlugin::import(const String source_file, const String save_path, const Dictionary options, const Array platform_variants, const Array gen_files) {
	Ref<SpineAtlasResource> res;
	res.instance();
	res->set_normal_texture_prefix(options["normal_texture_prefix"]);
	res->load_from_atlas_file(source_file);

	String file_name = String(save_path + '.') + get_save_extension();
	auto err = ResourceSaver::get_singleton()->save(file_name, res);
	return (int)err;
}

Array SpineAtlasResourceImportPlugin::get_import_options(const int64_t preset) {
	Array options;
	if (preset == 0) {
		Dictionary op;
		op["name"] = "normal_texture_prefix";
		op["type"] = Variant::STRING;
		op["hint_string"] = "String";
		op["default_value"] = String("n");
		options.push_back(op);
	}
	return options;
}

void SpineJsonResourceImportPlugin::_register_methods() {
	register_method("get_importer_name", &SpineJsonResourceImportPlugin::get_importer_name);
	register_method("get_visible_name", &SpineJsonResourceImportPlugin::get_visible_name);
	register_method("get_recognized_extensions", &SpineJsonResourceImportPlugin::get_recognized_extensions);
	register_method("get_preset_name", &SpineJsonResourceImportPlugin::get_preset_name);
	register_method("get_preset_count", &SpineJsonResourceImportPlugin::get_preset_count);
	register_method("get_save_extension", &SpineJsonResourceImportPlugin::get_save_extension);
	register_method("get_resource_type", &SpineJsonResourceImportPlugin::get_resource_type);
	register_method("get_import_options", &SpineJsonResourceImportPlugin::get_import_options);
	register_method("get_option_visibility", &SpineJsonResourceImportPlugin::get_option_visibility);
	register_method("import", &SpineJsonResourceImportPlugin::import);
}

int64_t SpineJsonResourceImportPlugin::import(const String source_file, const String save_path, const Dictionary options, const Array platform_variants, const Array gen_files) {
	Ref<SpineSkeletonJsonDataResource> res;
	res.instance();
	res->load_from_file(source_file);

	String file_name = String(save_path + '.') + get_save_extension();
	auto err = ResourceSaver::get_singleton()->save(file_name, res);
	return (int)err;
}

//=======================| SpineRuntimeEditorPlugin |============================

void SpineRuntimeEditorPlugin::_register_methods() {
	register_method("get_name", &SpineRuntimeEditorPlugin::get_name);
	register_method("has_main_screen", &SpineRuntimeEditorPlugin::has_main_screen);
	register_method("handles", &SpineRuntimeEditorPlugin::handles);
	register_method("make_visible", &SpineRuntimeEditorPlugin::make_visible);
}

SpineRuntimeEditorPlugin::SpineRuntimeEditorPlugin() {
}

SpineRuntimeEditorPlugin::~SpineRuntimeEditorPlugin() {
	animate_button->queue_free();
	animate_button = nullptr;
	animate_dialog->queue_free();
	animate_dialog = nullptr;

	remove_import_plugin(atlas_importer);
	remove_import_plugin(json_importer);

	remove_custom_type("SpineAtlasResource");
	remove_custom_type("SpineSprite");
	remove_custom_type("SpineSkeletonDataResource");
	remove_custom_type("SpineAnimationStateDataResource");
	remove_custom_type("SpineSkeletonJsonDataResource");
	remove_custom_type("SpineSkeleton");
	remove_custom_type("SpineAnimationState");
	remove_custom_type("SpineAnimation");
	remove_custom_type("SpineEventData");
	remove_custom_type("SpineTrackEntry");
	remove_custom_type("SpineEvent");
	remove_custom_type("SpineBoneData");
	remove_custom_type("SpineSlotData");
	remove_custom_type("SpineAttachment");
	remove_custom_type("SpineSkinAttachmentMapEntry");
	remove_custom_type("SpineSkinAttachmentMapEntries");
	remove_custom_type("SpineConstraintData");
	remove_custom_type("SpineSkin");
	remove_custom_type("SpineIkConstraintData");
	remove_custom_type("SpineTransformConstraintData");
	remove_custom_type("SpinePathConstraintData");
	remove_custom_type("SpineBone");
	remove_custom_type("SpineSlot");
	remove_custom_type("SpineIkConstraint");
	remove_custom_type("SpinePathConstraint");
	remove_custom_type("SpineTransformConstraint");
	remove_custom_type("SpineSpriteMeshInstance2D");
	remove_custom_type("PackedSpineSkinResource");
	remove_custom_type("SpineTimeline");
	remove_custom_type("SpineConstant");
	remove_custom_type("SpineCollisionShapeProxy");
}

void SpineRuntimeEditorPlugin::_init() {
	{
		Ref<SpineAtlasResource> _SpineAtlasResource;
		_SpineAtlasResource.instance();
		add_custom_type("SpineAtlasResource", "Resource", Ref<Script>(_SpineAtlasResource->get_script()), nullptr);
	}
	{
		SpineSprite *_SpineSprite = SpineSprite::_new();
		add_custom_type("SpineSprite", "Node2D", Ref<Script>(_SpineSprite->get_script()), nullptr);
		_SpineSprite->free();
	}
	{
		Ref<SpineSkeletonDataResource> _SpineSkeletonDataResource;
		_SpineSkeletonDataResource.instance();
		add_custom_type("SpineSkeletonDataResource", "Resource", Ref<Script>(_SpineSkeletonDataResource->get_script()), nullptr);
	}
	{
		Ref<SpineAnimationStateDataResource> _SpineAnimationStateDataResource;
		_SpineAnimationStateDataResource.instance();
		add_custom_type("SpineAnimationStateDataResource", "Resource", Ref<Script>(_SpineAnimationStateDataResource->get_script()), nullptr);
	}
	{
		Ref<SpineSkeletonJsonDataResource> _SpineSkeletonJsonDataResource;
		_SpineSkeletonJsonDataResource.instance();
		add_custom_type("SpineSkeletonJsonDataResource", "Resource", Ref<Script>(_SpineSkeletonJsonDataResource->get_script()), nullptr);
	}
	{
		Ref<SpineSkeleton> _SpineSkeleton;
		_SpineSkeleton.instance();
		add_custom_type("SpineSkeleton", "Reference", Ref<Script>(_SpineSkeleton->get_script()), nullptr);
	}
	{
		Ref<SpineAnimationState> _SpineAnimationState;
		_SpineAnimationState.instance();
		add_custom_type("SpineAnimationState", "Reference", Ref<Script>(_SpineAnimationState->get_script()), nullptr);
	}
	{
		Ref<SpineAnimation> _SpineAnimation;
		_SpineAnimation.instance();
		add_custom_type("SpineAnimation", "Reference", Ref<Script>(_SpineAnimation->get_script()), nullptr);
	}
	{
		Ref<SpineEventData> _SpineEventData;
		_SpineEventData.instance();
		add_custom_type("SpineEventData", "Reference", Ref<Script>(_SpineEventData->get_script()), nullptr);
	}
	{
		Ref<SpineTrackEntry> _SpineTrackEntry;
		_SpineTrackEntry.instance();
		add_custom_type("SpineTrackEntry", "Reference", Ref<Script>(_SpineTrackEntry->get_script()), nullptr);
	}
	{
		Ref<SpineEvent> _SpineEvent;
		_SpineEvent.instance();
		add_custom_type("SpineEvent", "Reference", Ref<Script>(_SpineEvent->get_script()), nullptr);
	}
	{
		Ref<SpineBoneData> _SpineBoneData;
		_SpineBoneData.instance();
		add_custom_type("SpineBoneData", "Reference", Ref<Script>(_SpineBoneData->get_script()), nullptr);
	}
	{
		Ref<SpineSlotData> _SpineSlotData;
		_SpineSlotData.instance();
		add_custom_type("SpineSlotData", "Reference", Ref<Script>(_SpineSlotData->get_script()), nullptr);
	}
	{
		Ref<SpineAttachment> _SpineAttachment;
		_SpineAttachment.instance();
		add_custom_type("SpineAttachment", "Reference", Ref<Script>(_SpineAttachment->get_script()), nullptr);
	}
	{
		Ref<SpineSkinAttachmentMapEntry> _SpineSkinAttachmentMapEntry;
		_SpineSkinAttachmentMapEntry.instance();
		add_custom_type("SpineSkinAttachmentMapEntry", "Reference", Ref<Script>(_SpineSkinAttachmentMapEntry->get_script()), nullptr);
	}
	{
		Ref<SpineSkinAttachmentMapEntries> _SpineSkinAttachmentMapEntries;
		_SpineSkinAttachmentMapEntries.instance();
		add_custom_type("SpineSkinAttachmentMapEntries", "Reference", Ref<Script>(_SpineSkinAttachmentMapEntries->get_script()), nullptr);
	}
	{
		Ref<SpineConstraintData> _SpineConstraintData;
		_SpineConstraintData.instance();
		add_custom_type("SpineConstraintData", "Reference", Ref<Script>(_SpineConstraintData->get_script()), nullptr);
	}
	{
		Ref<SpineSkin> _SpineSkin;
		_SpineSkin.instance();
		add_custom_type("SpineSkin", "Reference", Ref<Script>(_SpineSkin->get_script()), nullptr);
	}
	{
		Ref<SpineIkConstraintData> _SpineIkConstraintData;
		_SpineIkConstraintData.instance();
		add_custom_type("SpineIkConstraintData", "Reference", Ref<Script>(_SpineIkConstraintData->get_script()), nullptr);
	}
	{
		Ref<SpineTransformConstraintData> _SpineTransformConstraintData;
		_SpineTransformConstraintData.instance();
		add_custom_type("SpineTransformConstraintData", "Reference", Ref<Script>(_SpineTransformConstraintData->get_script()), nullptr);
	}
	{
		Ref<SpinePathConstraintData> _SpinePathConstraintData;
		_SpinePathConstraintData.instance();
		add_custom_type("SpinePathConstraintData", "Reference", Ref<Script>(_SpinePathConstraintData->get_script()), nullptr);
	}
	{
		Ref<SpineBone> _SpineBone;
		_SpineBone.instance();
		add_custom_type("SpineBone", "Reference", Ref<Script>(_SpineBone->get_script()), nullptr);
	}
	{
		Ref<SpineSlot> _SpineSlot;
		_SpineSlot.instance();
		add_custom_type("SpineSlot", "Reference", Ref<Script>(_SpineSlot->get_script()), nullptr);
	}
	{
		Ref<SpineIkConstraint> _SpineIkConstraint;
		_SpineIkConstraint.instance();
		add_custom_type("SpineIkConstraint", "Reference", Ref<Script>(_SpineIkConstraint->get_script()), nullptr);
	}
	{
		Ref<SpinePathConstraint> _SpinePathConstraint;
		_SpinePathConstraint.instance();
		add_custom_type("SpinePathConstraint", "Reference", Ref<Script>(_SpinePathConstraint->get_script()), nullptr);
	}
	{
		Ref<SpineTransformConstraint> _SpineTransformConstraint;
		_SpineTransformConstraint.instance();
		add_custom_type("SpineTransformConstraint", "Reference", Ref<Script>(_SpineTransformConstraint->get_script()), nullptr);
	}
	{
		SpineSpriteMeshInstance2D *_SpineSpriteMeshInstance2D = SpineSpriteMeshInstance2D::_new();
		add_custom_type("SpineSpriteMeshInstance2D", "MeshInstance2D", Ref<Script>(_SpineSpriteMeshInstance2D->get_script()), nullptr);
		_SpineSpriteMeshInstance2D->free();
	}
	{
		Ref<PackedSpineSkinResource> _PackedSpineSkinResource;
		_PackedSpineSkinResource.instance();
		add_custom_type("PackedSpineSkinResource", "Resource", Ref<Script>(_PackedSpineSkinResource->get_script()), nullptr);
	}
	{
		Ref<SpineTimeline> _SpineTimeline;
		_SpineTimeline.instance();
		add_custom_type("SpineTimeline", "Reference", Ref<Script>(_SpineTimeline->get_script()), nullptr);
	}
	{
		Ref<SpineConstant> _SpineConstant;
		_SpineConstant.instance();
		add_custom_type("SpineConstant", "Reference", Ref<Script>(_SpineConstant->get_script()), nullptr);
	}
	{
		SpineCollisionShapeProxy *_SpineCollisionShapeProxy = SpineCollisionShapeProxy::_new();
		add_custom_type("SpineCollisionShapeProxy", "CollisionPolygon2D", Ref<Script>(_SpineCollisionShapeProxy->get_script()), nullptr);
		_SpineCollisionShapeProxy->free();
	}
	{
		SceneTreeDialog *_SceneTreeDialog = SceneTreeDialog::_new();
		add_custom_type("SpineCollisionShapeProxy", "ConfirmationDialog", Ref<Script>(_SceneTreeDialog->get_script()), nullptr);
		_SceneTreeDialog->free();
	}
	atlas_importer.instance();
	add_import_plugin(atlas_importer);

	json_importer.instance();
	add_import_plugin(json_importer);

	animate_button = ToolButton::_new();
	animate_button->set_text("Animate");
	add_control_to_container(CONTAINER_CANVAS_EDITOR_MENU, animate_button);

	animate_dialog = SpineSpriteAnimateDialog::_new();
	get_editor_interface()->get_base_control()->add_child(animate_dialog);
	animate_dialog->set_animate_button(animate_button);
	animate_dialog->set_plugin(this);
}

bool SpineRuntimeEditorPlugin::handles(const Object *object) {
	SpineSprite *sprite = cast_to<SpineSprite>(object);
	return sprite != nullptr;
}

void SpineRuntimeEditorPlugin::make_visible(bool p_visible) {
	if (get_editor_interface()->get_selection()->get_selected_nodes().size() != 1) {
		p_visible = false;
	}
	animate_dialog->get_animate_button()->set_visible(p_visible);
}

} //namespace godot

//#endif