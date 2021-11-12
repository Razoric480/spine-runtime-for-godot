//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineSkin.h"

#include "SpineBoneData.h"
#include "SpineConstraintData.h"

void SpineSkin::_register_methods() {
	godot::register_method("init", &SpineSkin::init);
	godot::register_method("set_attachment", &SpineSkin::set_attachment);
	godot::register_method("get_attachment", &SpineSkin::get_attachment);
	godot::register_method("remove_attachment", &SpineSkin::remove_attachment);
	godot::register_method("find_names_for_slot", &SpineSkin::find_names_for_slot);
	godot::register_method("find_attachments_for_slot", &SpineSkin::find_attachments_for_slot);
	godot::register_method("get_skin_name", &SpineSkin::get_skin_name);
	godot::register_method("add_skin", &SpineSkin::add_skin);
	godot::register_method("copy_skin", &SpineSkin::copy_skin);
	godot::register_method("get_attachments", &SpineSkin::get_attachments);
	godot::register_method("get_all_bone_data", &SpineSkin::get_bones);
	godot::register_method("get_all_constraint_data", &SpineSkin::get_constraint);
}

SpineSkin::SpineSkin() {}
SpineSkin::~SpineSkin() {}

void SpineSkin::_init() {
	skin = nullptr;
}

#define S_T(x) (spine::String(x.utf8().get_data()))
godot::Ref<SpineSkin> SpineSkin::init(const godot::String &name) {
	skin = new spine::Skin(S_T(name));
	return this;
}

void SpineSkin::set_attachment(uint64_t slot_index, const godot::String &name, godot::Ref<SpineAttachment> attachment) {
	if (!attachment.is_valid()) {
		ERR_PRINT("attachment is invalid!");
		return;
	}
	skin->setAttachment(slot_index, S_T(name), attachment->get_spine_object());
}

godot::Ref<SpineAttachment> SpineSkin::get_attachment(uint64_t slot_index, const godot::String &name) {
	auto a = skin->getAttachment(slot_index, S_T(name));
	if (a == NULL)
		return NULL;
	godot::Ref<SpineAttachment> gd_attachment;
	gd_attachment.instance();
	gd_attachment->set_spine_object(a);
	return gd_attachment;
}

void SpineSkin::remove_attachment(uint64_t slot_index, const godot::String &name) {
	skin->removeAttachment(slot_index, S_T(name));
}

godot::Array SpineSkin::find_names_for_slot(uint64_t slot_index) {
	spine::Vector<spine::String> names;
	skin->findNamesForSlot(slot_index, names);
	godot::Array gd_names;
	gd_names.resize(names.size());
	for (size_t i = 0; i < names.size(); ++i) {
		gd_names[i] = names[i].buffer();
	}
	return gd_names;
}

godot::Array SpineSkin::find_attachments_for_slot(uint64_t slot_index) {
	spine::Vector<spine::Attachment *> as;
	skin->findAttachmentsForSlot(slot_index, as);
	godot::Array gd_as;
	gd_as.resize(as.size());
	for (size_t i = 0; i < as.size(); ++i) {
		if (as[i] == NULL)
			gd_as[i] = godot::Ref<SpineAttachment>(NULL);
		else {
			godot::Ref<SpineAttachment> gd_a;
			gd_a.instance();
			gd_a->set_spine_object(as[i]);
			gd_as[i] = gd_a;
		}
	}
	return gd_as;
}

godot::String SpineSkin::get_skin_name() {
	return skin->getName().buffer();
}

void SpineSkin::add_skin(godot::Ref<SpineSkin> other) {
	if (other.is_valid() && other->get_spine_object()) {
		skin->addSkin(other->get_spine_object());
	} else {
		ERR_PRINT("other is NULL!");
	}
}

void SpineSkin::copy_skin(godot::Ref<SpineSkin> other) {
	if (other.is_valid() && other->get_spine_object()) {
		skin->copySkin(other->get_spine_object());
	} else {
		ERR_PRINT("other is NULL!");
	}
}

godot::Ref<SpineSkinAttachmentMapEntries> SpineSkin::get_attachments() {
	auto *es = new spine::Skin::AttachmentMap::Entries(skin->getAttachments());
	godot::Ref<SpineSkinAttachmentMapEntries> gd_es;
	gd_es.instance();
	gd_es->set_spine_object(es);
	return gd_es;
}

godot::Array SpineSkin::get_bones() {
	auto bs = skin->getBones();
	godot::Array gd_bs;
	gd_bs.resize(bs.size());
	for (size_t i = 0; i < bs.size(); ++i) {
		if (bs[i] == NULL)
			gd_bs[i] = godot::Ref<SpineBoneData>(NULL);
		else {
			godot::Ref<SpineBoneData> gd_b;
			gd_b.instance();
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

godot::Array SpineSkin::get_constraint() {
	auto cs = skin->getConstraints();
	godot::Array gd_cs;
	gd_cs.resize(cs.size());
	for (size_t i = 0; i < cs.size(); ++i) {
		if (cs[i] == NULL)
			gd_cs[i] = godot::Ref<SpineConstraintData>(NULL);
		else {
			godot::Ref<SpineConstraintData> gd_c;
			gd_c.instance();
			gd_c->set_spine_object(cs[i]);
			gd_cs[i] = gd_c;
		}
	}
	return gd_cs;
}