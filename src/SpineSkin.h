//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINESKIN_H
#define GODOT_SPINESKIN_H

#include <Godot.hpp>

#include <spine/spine.h>

#include "SpineAttachment.h"
#include "SpineSkinAttachmentMapEntries.h"

class SpineSkin : public godot::Reference {
	GODOT_CLASS(SpineSkin, godot::Reference);

public:
	static void _register_methods();

private:
	spine::Skin *skin;

public:
	SpineSkin();
	~SpineSkin();

	void _init();

	inline void set_spine_object(spine::Skin *s) {
		skin = s;
	}
	spine::Skin *get_spine_object() {
		return skin;
	}

	godot::Ref<SpineSkin> init(const godot::String &name);

	void set_attachment(uint64_t slot_index, const godot::String &name, godot::Ref<SpineAttachment> attachment);

	godot::Ref<SpineAttachment> get_attachment(uint64_t slot_index, const godot::String &name);

	void remove_attachment(uint64_t slot_index, const godot::String &name);

	godot::Array find_names_for_slot(uint64_t slot_index);

	godot::Array find_attachments_for_slot(uint64_t slot_index);

	godot::String get_skin_name();

	void add_skin(godot::Ref<SpineSkin> other);

	void copy_skin(godot::Ref<SpineSkin> other);

	godot::Ref<SpineSkinAttachmentMapEntries> get_attachments();

	godot::Array get_bones();

	godot::Array get_constraint();
};

#endif //GODOT_SPINESKIN_H
