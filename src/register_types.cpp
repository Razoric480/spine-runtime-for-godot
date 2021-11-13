
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


extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *o) {
    godot::Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *o) {
    godot::Godot::gdnative_terminate(o);
}

extern "C" void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);

    godot::register_class<SpineSpriteAnimateDialog>();
    godot::register_class<SpineRuntime>();
    godot::register_class<SpineAtlasResource>();
    godot::register_class<SpineSprite>();
	godot::register_class<SpineSkeletonDataResource>();
	godot::register_class<SpineAnimationStateDataResource>();
	godot::register_class<SpineSkeletonJsonDataResource>();
	godot::register_class<SpineSkeleton>();
	godot::register_class<SpineAnimationState>();
	godot::register_class<SpineAnimation>();
	godot::register_class<SpineEventData>();
	godot::register_class<SpineTrackEntry>();
	godot::register_class<SpineEvent>();
	godot::register_class<SpineBoneData>();
	godot::register_class<SpineSlotData>();
	godot::register_class<SpineAttachment>();
	godot::register_class<SpineSkinAttachmentMapEntry>();
	godot::register_class<SpineSkinAttachmentMapEntries>();
	godot::register_class<SpineConstraintData>();
	godot::register_class<SpineSkin>();
	godot::register_class<SpineIkConstraintData>();
	godot::register_class<SpineTransformConstraintData>();
	godot::register_class<SpinePathConstraintData>();
	godot::register_class<SpineBone>();
	godot::register_class<SpineSlot>();
	godot::register_class<SpineIkConstraint>();
	godot::register_class<SpinePathConstraint>();
	godot::register_class<SpineTransformConstraint>();
	godot::register_class<SpineSpriteMeshInstance2D>();
	godot::register_class<PackedSpineSkinResource>();
	godot::register_class<SpineTimeline>();
	godot::register_class<SpineConstant>();
	godot::register_class<SpineCollisionShapeProxy>();
	
	godot::register_class<ResourceFormatLoaderSpineAtlas>();
	godot::register_class<ResourceFormatSaverSpineAtlas>();
	godot::register_class<ResourceFormatLoaderSpineSkeletonJsonData>();
	godot::register_class<ResourceFormatSaverSpineSkeletonJsonData>();
}