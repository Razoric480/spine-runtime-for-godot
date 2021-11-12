//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineSkinAttachmentMapEntries.h"

void SpineSkinAttachmentMapEntry::_register_methods() {
	godot::register_method("get_slot_index", &SpineSkinAttachmentMapEntry::get_slot_index);
	godot::register_method("set_slot_index", &SpineSkinAttachmentMapEntry::set_slot_index);
	godot::register_method("get_entry_name", &SpineSkinAttachmentMapEntry::get_entry_name);
	godot::register_method("set_entry_name", &SpineSkinAttachmentMapEntry::set_entry_name);
	godot::register_method("get_attachment", &SpineSkinAttachmentMapEntry::get_attachment);
	godot::register_method("set_attachment", &SpineSkinAttachmentMapEntry::set_attachment);
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

godot::String SpineSkinAttachmentMapEntry::get_entry_name() {
	return entry->_name.buffer();
}

void SpineSkinAttachmentMapEntry::set_entry_name(const godot::String &v) {
	entry->_name = spine::String(v.utf8().get_data());
}

godot::Ref<SpineAttachment> SpineSkinAttachmentMapEntry::get_attachment() {
	if (entry->_attachment == NULL)
		return NULL;
	godot::Ref<SpineAttachment> gd_attachment;
	gd_attachment.instance();
	gd_attachment->set_spine_object(entry->_attachment);
	return gd_attachment;
}

void SpineSkinAttachmentMapEntry::set_attachment(godot::Ref<SpineAttachment> v) {
	if (v.is_valid()) {
		entry->_attachment = v->get_spine_object();
	} else {
		entry->_attachment = NULL;
	}
}

void SpineSkinAttachmentMapEntries::_register_methods() {
	godot::register_method("has_next", &SpineSkinAttachmentMapEntries::has_next);
	godot::register_method("next", &SpineSkinAttachmentMapEntries::next);
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

godot::Ref<SpineSkinAttachmentMapEntry> SpineSkinAttachmentMapEntries::next() {
	auto &e = entries->next();
	godot::Ref<SpineSkinAttachmentMapEntry> gd_entry;
	gd_entry.instance();
	gd_entry->set_spine_object(&e);
	return gd_entry;
}