//
// Created by Raymond_Lx on 2020/6/6.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpineSlot.h"

#include "SpineBone.h"
#include "SpineSkeleton.h"

namespace godot {

void SpineSlot::_register_methods() {
	register_method("set_to_setup_pos", &SpineSlot::set_to_setup_pos);
	register_method("get_data", &SpineSlot::get_data);
	register_method("get_bone", &SpineSlot::get_bone);
	register_method("get_skeleton", &SpineSlot::get_skeleton);
	register_method("get_color", &SpineSlot::get_color);
	register_method("set_color", &SpineSlot::set_color);
	register_method("get_dark_color", &SpineSlot::get_dark_color);
	register_method("set_dark_color", &SpineSlot::set_dark_color);
	register_method("has_dark_color", &SpineSlot::has_dark_color);
	register_method("get_attachment", &SpineSlot::get_attachment);
	register_method("set_attachment", &SpineSlot::set_attachment);
	register_method("get_attachment_state", &SpineSlot::get_attachment_state);
	register_method("set_attachment_state", &SpineSlot::set_attachment_state);
	register_method("get_deform", &SpineSlot::get_deform);
	register_method("set_deform", &SpineSlot::set_deform);
}

SpineSlot::SpineSlot() {}
SpineSlot::~SpineSlot() {}

void SpineSlot::_init() {
	slot = nullptr;
}

void SpineSlot::set_to_setup_pos() {
	slot->setToSetupPose();
}

Ref<SpineSlotData> SpineSlot::get_data() {
	auto &sd = slot->getData();
	Ref<SpineSlotData> gd_sd;
	gd_sd.instance();
	gd_sd->set_spine_object(&sd);
	return gd_sd;
}

Ref<SpineBone> SpineSlot::get_bone() {
	auto &b = slot->getBone();
	Ref<SpineBone> gd_b;
	gd_b.instance();
	gd_b->set_spine_object(&b);
	return gd_b;
}

Ref<SpineSkeleton> SpineSlot::get_skeleton() {
	auto &s = slot->getSkeleton();
	Ref<SpineSkeleton> gd_s;
	gd_s.instance();
	gd_s->set_spine_object(&s);
	return gd_s;
}

Color SpineSlot::get_color() {
	auto &c = slot->getColor();
	return Color(c.r, c.g, c.b, c.a);
}
void SpineSlot::set_color(Color v) {
	auto &c = slot->getColor();
	c.set(v.r, v.g, v.b, v.a);
}

Color SpineSlot::get_dark_color() {
	auto &c = slot->getDarkColor();
	return Color(c.r, c.g, c.b, c.a);
}
void SpineSlot::set_dark_color(Color v) {
	auto &c = slot->getDarkColor();
	c.set(v.r, v.g, v.b, v.a);
}

bool SpineSlot::has_dark_color() {
	return slot->hasDarkColor();
}

Ref<SpineAttachment> SpineSlot::get_attachment() {
	auto a = slot->getAttachment();
	if (a == NULL)
		return NULL;
	Ref<SpineAttachment> gd_a;
	gd_a.instance();
	gd_a->set_spine_object(a);
	return gd_a;
}
void SpineSlot::set_attachment(Ref<SpineAttachment> v) {
	if (v.is_valid()) {
		slot->setAttachment(v->get_spine_object());
	} else {
		slot->setAttachment(NULL);
	}
}

int SpineSlot::get_attachment_state() {
	return slot->getAttachmentState();
}
void SpineSlot::set_attachment_state(int v) {
	slot->setAttachmentState(v);
}

float SpineSlot::get_attachment_time() {
	return slot->getAttachmentTime();
}
void SpineSlot::set_attachment_time(float v) {
	slot->setAttachmentTime(v);
}

Array SpineSlot::get_deform() {
	auto &ds = slot->getDeform();
	Array gd_ds;
	gd_ds.resize(ds.size());
	for (size_t i = 0; i < ds.size(); ++i) {
		gd_ds[i] = ds[i];
	}
	return gd_ds;
}
void SpineSlot::set_deform(Array gd_ds) {
	auto &ds = slot->getDeform();
	ds.setSize(gd_ds.size(), 0);
	for (size_t i = 0; i < gd_ds.size(); ++i) {
		ds[i] = gd_ds[i];
	}
}

} //namespace godot