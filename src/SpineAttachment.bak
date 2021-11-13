//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineAttachment.h"

void SpineAttachment::_register_methods() {
	godot::register_method("get_attachment_name", &SpineAttachment::get_attachment_name);
	godot::register_method("copy", &SpineAttachment::copy);
}

SpineAttachment::SpineAttachment() :
		attachment(NULL) {}
SpineAttachment::~SpineAttachment() {
	if (attachment) {
		attachment->dereference();
		attachment = NULL;
	}
}

godot::String SpineAttachment::get_attachment_name() {
	return attachment->getName().buffer();
}

godot::Ref<SpineAttachment> SpineAttachment::copy() {
	auto a = attachment->copy();
	if (a == NULL)
		return NULL;
	godot::Ref<SpineAttachment> gd_attachment;
	gd_attachment.instance();

	gd_attachment->set_spine_object(a);
	return gd_attachment;
}
