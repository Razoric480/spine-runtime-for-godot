//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpineSkinAttachmentMapEntries.h"

namespace godot {

void SpineSkinAttachmentMapEntry::_register_methods() {
	register_method("get_slot_index", &SpineSkinAttachmentMapEntry::get_slot_index);
	register_method("set_slot_index", &SpineSkinAttachmentMapEntry::set_slot_index);
	register_method("get_entry_name", &SpineSkinAttachmentMapEntry::get_entry_name);
	register_method("set_entry_name", &SpineSkinAttachmentMapEntry::set_entry_name);
	register_method("get_attachment", &SpineSkinAttachmentMapEntry::get_attachment);
	register_method("set_attachment", &SpineSkinAttachmentMapEntry::set_attachment);
}

SpineSkinAttachmentMapEntry::SpineSkinAttachmentMapEntry() {}
SpineSkinAttachmentMapEntry::~SpineSkinAttachmentMapEntry() {}

void SpineSkinAttachmentMapEntry::_init() {
	entry = nullptr;
}

uint64_t SpineSkinAttachmentMapEntry::get_slot_index() {
	return entry->_slotIndex;
}
void SpineSkinAttachmentMapEntry::set_slot_index(uint64_t v) {
	entry->_slotIndex = v;
}

String SpineSkinAttachmentMapEntry::get_entry_name() {
	return entry->_name.buffer();
}
void SpineSkinAttachmentMapEntry::set_entry_name(const String &v) {
	entry->_name = spine::String(v.alloc_c_string());
}

Ref<SpineAttachment> SpineSkinAttachmentMapEntry::get_attachment() {
	if (entry->_attachment == NULL)
		return NULL;
	Ref<SpineAttachment> gd_attachment;
	gd_attachment.instance();
	;
	gd_attachment->set_spine_object(entry->_attachment);
	return gd_attachment;
}
void SpineSkinAttachmentMapEntry::set_attachment(Ref<SpineAttachment> v) {
	if (v.is_valid()) {
		entry->_attachment = v->get_spine_object();
	} else {
		entry->_attachment = NULL;
	}
}

void SpineSkinAttachmentMapEntries::_register_methods() {
	register_method("has_next", &SpineSkinAttachmentMapEntries::has_next);
	register_method("next", &SpineSkinAttachmentMapEntries::next);
}

SpineSkinAttachmentMapEntries::SpineSkinAttachmentMapEntries() {}
SpineSkinAttachmentMapEntries::~SpineSkinAttachmentMapEntries() {
	if (entries) {
		delete entries;
		return;
	}
}

void SpineSkinAttachmentMapEntries::_init() {
	entries = nullptr;
}

bool SpineSkinAttachmentMapEntries::has_next() {
	return entries->hasNext();
}
Ref<SpineSkinAttachmentMapEntry> SpineSkinAttachmentMapEntries::next() {
	auto &e = entries->next();
	Ref<SpineSkinAttachmentMapEntry> gd_entry;
	gd_entry.instance();
	;
	gd_entry->set_spine_object(&e);
	return gd_entry;
}

} //namespace godot