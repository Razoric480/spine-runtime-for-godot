
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
#include "SpineRuntimeEditorPlugin.h"
#include "SceneTreeDialog.h"

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_tool_class<PackedSpineSkinResource>();
	godot::register_tool_class<ResourceFormatLoaderSpineAtlas>();
	godot::register_tool_class<ResourceFormatLoaderSpineSkeletonJsonData>();
	godot::register_tool_class<ResourceFormatSaverSpineAtlas>();
	godot::register_tool_class<ResourceFormatSaverSpineSkeletonJsonData>();
	godot::register_tool_class<godot::SceneTreeDialog>();
	godot::register_tool_class<SpineRuntime>();
	godot::register_tool_class<SpineAnimation>();
	godot::register_tool_class<SpineAnimationState>();
	godot::register_tool_class<SpineAnimationStateDataResource>();
	godot::register_tool_class<SpineAtlasResource>();
	godot::register_tool_class<SpineAnimationStateDataResource>();
	godot::register_tool_class<SpineAtlasResource>();
	godot::register_tool_class<SpineAttachment>();
	godot::register_tool_class<SpineBone>();
	godot::register_tool_class<SpineBoneData>();
	godot::register_tool_class<SpineCollisionShapeProxy>();
	godot::register_tool_class<SpineConstant>();
	godot::register_tool_class<SpineConstraintData>();
	godot::register_tool_class<SpineEvent>();
	godot::register_tool_class<SpineEventData>();
	godot::register_tool_class<SpineIkConstraint>();
	godot::register_tool_class<SpineIkConstraintData>();
	godot::register_tool_class<SpinePathConstraint>();
	godot::register_tool_class<SpinePathConstraintData>();
	godot::register_tool_class<SpineAtlasResourceImportPlugin>();
	godot::register_tool_class<SpineJsonResourceImportPlugin>();
	godot::register_tool_class<SpineRuntimeEditorPlugin>();
	godot::register_tool_class<SpineSkeleton>();
	godot::register_tool_class<SpineSkeletonDataResource>();
	godot::register_tool_class<SpineSkeletonJsonDataResource>();
	godot::register_tool_class<SpineSkin>();
	godot::register_tool_class<SpineSkinAttachmentMapEntry>();
	godot::register_tool_class<SpineSlot>();
	godot::register_tool_class<SpineSlotData>();
	godot::register_tool_class<SpineSprite>();
	godot::register_tool_class<SpineSpriteAnimateDialog>();
	godot::register_tool_class<SpineSpriteMeshInstance2D>();
	godot::register_tool_class<SpineTimeline>();
	godot::register_tool_class<SpineTrackEntry>();
	godot::register_tool_class<SpineTransformConstraint>();
	godot::register_tool_class<SpineTransformConstraintData>();
}