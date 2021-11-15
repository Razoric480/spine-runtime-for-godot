//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_SPINESKINATTACHMENTMAPENTRIES_H
#define GODOT_SPINESKINATTACHMENTMAPENTRIES_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineAttachment.h"

namespace godot {

class SpineSkinAttachmentMapEntry : public Reference {
	GODOT_CLASS(SpineSkinAttachmentMapEntry, Reference);

public:
	void _init();
	static void _register_methods();

private:
	spine::Skin::AttachmentMap::Entry *entry;

public:
	SpineSkinAttachmentMapEntry();
	~SpineSkinAttachmentMapEntry();

	inline void set_spine_object(spine::Skin::AttachmentMap::Entry *e) {
		entry = e;
	}
	inline spine::Skin::AttachmentMap::Entry *get_spine_object() {
		return entry;
	}

	uint64_t get_slot_index();
	void set_slot_index(uint64_t v);

	String get_entry_name();
	void set_entry_name(const String &v);

	Ref<SpineAttachment> get_attachment();
	void set_attachment(Ref<SpineAttachment> v);
};

class SpineSkinAttachmentMapEntries : public Reference {
	GODOT_CLASS(SpineSkinAttachmentMapEntries, Reference);

public:
	void _init();
	static void _register_methods();

private:
	spine::Skin::AttachmentMap::Entries *entries;

public:
	SpineSkinAttachmentMapEntries();
	~SpineSkinAttachmentMapEntries();

	inline void set_spine_object(spine::Skin::AttachmentMap::Entries *e) {
		entries = e;
	}
	inline spine::Skin::AttachmentMap::Entries *get_spine_object() {
		return entries;
	}

	bool has_next();
	Ref<SpineSkinAttachmentMapEntry> next();
};

} //namespace godot

#endif //GODOT_SPINESKINATTACHMENTMAPENTRIES_H
