//
// Created by Raymond_Lx on 2020/6/5.
// Ported to GDNative by Razoric on 2021/11.
//

#include "SpineAttachment.h"

namespace godot {

void SpineAttachment::_register_methods() {
	register_method("get_attachment_name", &SpineAttachment::get_attachment_name);
	register_method("copy", &SpineAttachment::copy);
}

SpineAttachment::SpineAttachment() {}
SpineAttachment::~SpineAttachment() {
	if (attachment) {
		attachment->dereference();
		attachment = NULL;
	}
}

void SpineAttachment::_init() {
	attachment = nullptr;
}

String SpineAttachment::get_attachment_name() {
	return attachment->getName().buffer();
}

Ref<SpineAttachment> SpineAttachment::copy() {
	auto a = attachment->copy();
	if (a == NULL)
		return NULL;
	Ref<SpineAttachment> gd_attachment;
	gd_attachment.instance();
	gd_attachment->set_spine_object(a);
	return gd_attachment;
}

} //namespace godot