//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINESKINATTACHMENTMAPENTRIES_H
#define GODOT_SPINESKINATTACHMENTMAPENTRIES_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineAttachment.h"

class SpineSkinAttachmentMapEntry : public godot::Reference {
	GODOT_CLASS(SpineSkinAttachmentMapEntry, godot::Reference);

public:
	static void _register_methods();

private:
	spine::Skin::AttachmentMap::Entry *entry;

public:
	SpineSkinAttachmentMapEntry();
	~SpineSkinAttachmentMapEntry();

	void _init();

	inline void set_spine_object(spine::Skin::AttachmentMap::Entry *e) {
		entry = e;
	}
	inline spine::Skin::AttachmentMap::Entry *get_spine_object() {
		return entry;
	}

	uint64_t get_slot_index();
	void set_slot_index(uint64_t v);

	godot::String get_entry_name();
	void set_entry_name(const godot::String &v);

	godot::Ref<SpineAttachment> get_attachment();
	void set_attachment(godot::Ref<SpineAttachment> v);
};

class SpineSkinAttachmentMapEntries : public godot::Reference {
	GODOT_CLASS(SpineSkinAttachmentMapEntries, godot::Reference);

public:
	static void _register_methods();

private:
	spine::Skin::AttachmentMap::Entries *entries;

public:
	SpineSkinAttachmentMapEntries();
	~SpineSkinAttachmentMapEntries();
	
	void _init();

	inline void set_spine_object(spine::Skin::AttachmentMap::Entries *e) {
		entries = e;
	}
	inline spine::Skin::AttachmentMap::Entries *get_spine_object() {
		return entries;
	}

	bool has_next();
	godot::Ref<SpineSkinAttachmentMapEntry> next();
};

#endif //GODOT_SPINESKINATTACHMENTMAPENTRIES_H
