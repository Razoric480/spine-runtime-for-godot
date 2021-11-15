//
// Created by Razoric on 2021/11.
//

#include <Godot.hpp>

#include "SpineAtlasResource.h"
#include "SpineSkeletonDataResource.h"
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
	
	godot::register_tool_class<godot::SpineRuntimeEditorPlugin>();
	godot::register_tool_class<godot::SpineAtlasResourceImportPlugin>();
	godot::register_tool_class<godot::SpineJsonResourceImportPlugin>();
	godot::register_tool_class<godot::SpineSpriteAnimateDialog>();
}
