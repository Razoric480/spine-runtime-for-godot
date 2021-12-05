
#include "register_types.h"

#include <godot/gdnative_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "PackedSpineSkinResource.h"
#include "ResourceFormatLoaderSpineAtlas.h"
#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "ResourceFormatSaverSpineAtlas.h"
#include "ResourceFormatSaverSpineSkeletonJsonData.h"
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
#include "SpineRuntimeEditorPlugin.h"
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
#include "spine_runtime.h"

namespace godot {

static Ref<ResourceFormatLoaderSpineAtlas> atlas_loader;
static Ref<ResourceFormatSaverSpineAtlas> atlas_saver;
static Ref<ResourceFormatLoaderSpineSkeletonJsonData> json_skeleton_loader;
static Ref<ResourceFormatSaverSpineSkeletonJsonData> json_skeleton_saver;

void register_spine_runtime_types() {
	ClassDB::register_class<SpineSpriteAnimateDialog>();

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
	
	atlas_loader.instantiate();
	atlas_saver.instantiate();
	json_skeleton_loader.instantiate();
	json_skeleton_saver.instantiate();
}

void unregister_spine_runtime_types() {
	atlas_loader.unref();
	atlas_saver.unref();
	json_skeleton_loader.unref();
	json_skeleton_saver.unref();
}
} //namespace godot

extern "C" {
GDNativeBool GDN_EXPORT example_library_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_scene_initializer(register_spine_runtime_types);
	init_obj.register_scene_terminator(unregister_spine_runtime_types);

	return init_obj.init();
}
}