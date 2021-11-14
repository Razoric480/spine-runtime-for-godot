#include <Godot.hpp>

#include "SpineAtlasResource.h"
#include "ResourceFormatLoaderSpineAtlas.h"
#include "ResourceFormatSaverSpineAtlas.h"
#include "SpineSkeletonDataResource.h"
#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "ResourceFormatSaverSpineSkeletonJsonData.h"
#include "SpineSprite.h"
#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineAnimationState.h"
#include "SpineEventData.h"
#include "SpineEvent.h"
#include "SpineTrackEntry.h"
#include "SpineBoneData.h"
#include "SpineSlotData.h"
#include "SpineAttachment.h"
#include "SpineSkinAttachmentMapEntries.h"
#include "SpineConstraintData.h"
#include "SpineSkin.h"
#include "SpineIkConstraintData.h"
#include "SpineTransformConstraintData.h"
#include "SpinePathConstraintData.h"
#include "SpineSpriteMeshInstance2D.h"
#include "PackedSpineSkinResource.h"
#include "SpineTimeline.h"
#include "SpineConstant.h"
#include "SpineCollisionShapeProxy.h"
#include "SpineSpriteAnimateDialog.h"
#include "SpineRuntimeEditorPlugin.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
	
	godot::register_tool_class<godot::SpineAtlasResource>();
    godot::register_tool_class<godot::SpineSprite>();
	godot::register_tool_class<godot::SpineSkeletonDataResource>();
	godot::register_tool_class<godot::SpineAnimationStateDataResource>();
	godot::register_tool_class<godot::SpineSkeletonJsonDataResource>();
	godot::register_tool_class<godot::SpineSkeleton>();
	godot::register_tool_class<godot::SpineAnimationState>();
	godot::register_tool_class<godot::SpineAnimation>();
	godot::register_tool_class<godot::SpineEventData>();
	godot::register_tool_class<godot::SpineTrackEntry>();
	godot::register_tool_class<godot::SpineEvent>();
	godot::register_tool_class<godot::SpineBoneData>();
	godot::register_tool_class<godot::SpineSlotData>();
	godot::register_tool_class<godot::SpineAttachment>();
	godot::register_tool_class<godot::SpineSkinAttachmentMapEntry>();
	godot::register_tool_class<godot::SpineSkinAttachmentMapEntries>();
	godot::register_tool_class<godot::SpineConstraintData>();
	godot::register_tool_class<godot::SpineSkin>();
	godot::register_tool_class<godot::SpineIkConstraintData>();
	godot::register_tool_class<godot::SpineTransformConstraintData>();
	godot::register_tool_class<godot::SpinePathConstraintData>();
	godot::register_tool_class<godot::SpineBone>();
	godot::register_tool_class<godot::SpineSlot>();
	godot::register_tool_class<godot::SpineIkConstraint>();
	godot::register_tool_class<godot::SpinePathConstraint>();
	godot::register_tool_class<godot::SpineTransformConstraint>();
	godot::register_tool_class<godot::SpineSpriteMeshInstance2D>();
	godot::register_tool_class<godot::PackedSpineSkinResource>();
	godot::register_tool_class<godot::SpineTimeline>();
	godot::register_tool_class<godot::SpineConstant>();
	godot::register_tool_class<godot::SpineCollisionShapeProxy>();
	godot::register_tool_class<godot::SceneTreeDialog>();
	
	godot::register_tool_class<godot::ResourceFormatLoaderSpineAtlas>();
	godot::register_tool_class<godot::ResourceFormatSaverSpineAtlas>();
	godot::register_tool_class<godot::ResourceFormatLoaderSpineSkeletonJsonData>();
	godot::register_tool_class<godot::ResourceFormatSaverSpineSkeletonJsonData>();
	
	godot::register_tool_class<godot::SpineRuntimeEditorPlugin>();
	godot::register_tool_class<godot::SpineAtlasResourceImportPlugin>();
	godot::register_tool_class<godot::SpineJsonResourceImportPlugin>();
	godot::register_tool_class<godot::SpineSpriteAnimateDialog>();
}


/*
#include "register_types.h"

#include "core/class_db.h"

#include "spine_runtime.h"
#include "SpineAtlasResource.h"
#include "ResourceFormatLoaderSpineAtlas.h"
#include "ResourceFormatSaverSpineAtlas.h"
#include "SpineSkeletonDataResource.h"
#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "ResourceFormatSaverSpineSkeletonJsonData.h"
#include "SpineSprite.h"
#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineAnimationState.h"
#include "SpineEventData.h"
#include "SpineEvent.h"
#include "SpineTrackEntry.h"
#include "SpineBoneData.h"
#include "SpineSlotData.h"
#include "SpineAttachment.h"
#include "SpineSkinAttachmentMapEntries.h"
#include "SpineConstraintData.h"
#include "SpineSkin.h"
#include "SpineIkConstraintData.h"
#include "SpineTransformConstraintData.h"
#include "SpinePathConstraintData.h"
#include "SpineSpriteMeshInstance2D.h"
#include "PackedSpineSkinResource.h"
#include "SpineTimeline.h"
#include "SpineConstant.h"
#include "SpineCollisionShapeProxy.h"
#include "SpineSpriteAnimateDialog.h"


static Ref<ResourceFormatLoaderSpineAtlas> atlas_loader;
static Ref<ResourceFormatSaverSpineAtlas> atlas_saver;
static Ref<ResourceFormatLoaderSpineSkeletonJsonData> json_skeleton_loader;
static Ref<ResourceFormatSaverSpineSkeletonJsonData> json_skeleton_saver;

// editor plugin
#ifdef TOOLS_ENABLED
#include "editor/editor_export.h"
#include "editor/editor_node.h"

#include "SpineRuntimeEditorPlugin.h"

static void editor_init_callback() {
    EditorNode::get_singleton()->add_editor_plugin(memnew(SpineRuntimeEditorPlugin(EditorNode::get_singleton())));
}


#endif

void register_spine_runtime_types(){
#ifdef TOOLS_ENABLED
    ClassDB::register_class<SpineSpriteAnimateDialog>();

	EditorNode::add_init_callback(editor_init_callback);

#endif

    ClassDB::register_class<SpineRuntime>();
    ClassDB::register_class<SpineAtlasResource>();
    ClassDB::register_class<SpineSprite>();
	ClassDB::register_class<SpineSkeletonDataResource>();
	ClassDB::register_class<SpineAnimationStateDataResource>();
	ClassDB::register_class<SpineSkeletonJsonDataResource>();
	ClassDB::register_class<SpineSkeleton>();
	ClassDB::register_class<SpineAnimationState>();
	ClassDB::register_class<SpineAnimation>();
	ClassDB::register_class<SpineEventData>();
	ClassDB::register_class<SpineTrackEntry>();
	ClassDB::register_class<SpineEvent>();
	ClassDB::register_class<SpineBoneData>();
	ClassDB::register_class<SpineSlotData>();
	ClassDB::register_class<SpineAttachment>();
	ClassDB::register_class<SpineSkinAttachmentMapEntry>();
	ClassDB::register_class<SpineSkinAttachmentMapEntries>();
	ClassDB::register_class<SpineConstraintData>();
	ClassDB::register_class<SpineSkin>();
	ClassDB::register_class<SpineIkConstraintData>();
	ClassDB::register_class<SpineTransformConstraintData>();
	ClassDB::register_class<SpinePathConstraintData>();
	ClassDB::register_class<SpineBone>();
	ClassDB::register_class<SpineSlot>();
	ClassDB::register_class<SpineIkConstraint>();
	ClassDB::register_class<SpinePathConstraint>();
	ClassDB::register_class<SpineTransformConstraint>();
	ClassDB::register_class<SpineSpriteMeshInstance2D>();
	ClassDB::register_class<PackedSpineSkinResource>();
	ClassDB::register_class<SpineTimeline>();
	ClassDB::register_class<SpineConstant>();
	ClassDB::register_class<SpineCollisionShapeProxy>();

    atlas_loader.instance();
    ResourceLoader::add_resource_format_loader(atlas_loader);

    atlas_saver.instance();
    ResourceSaver::add_resource_format_saver(atlas_saver);

	json_skeleton_loader.instance();
	ResourceLoader::add_resource_format_loader(json_skeleton_loader);

	json_skeleton_saver.instance();
	ResourceSaver::add_resource_format_saver(json_skeleton_saver);

}

void unregister_spine_runtime_types(){
    ResourceLoader::remove_resource_format_loader(atlas_loader);
    atlas_loader.unref();

    ResourceSaver::remove_resource_format_saver(atlas_saver);
    atlas_saver.unref();

	ResourceLoader::remove_resource_format_loader(json_skeleton_loader);
	json_skeleton_loader.unref();

	ResourceSaver::remove_resource_format_saver(json_skeleton_saver);
	json_skeleton_saver.unref();
}*/