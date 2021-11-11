//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINEATTACHMENT_H
#define GODOT_SPINEATTACHMENT_H

#include <Godot.hpp>

#include <spine/spine.h>

class SpineAttachment : public godot::Reference {
	GODOT_CLASS(SpineAttachment, godot::Reference);

protected:
	static void _register_methods();

private:
	spine::Attachment *attachment;

public:
	SpineAttachment();
	~SpineAttachment();

	inline void set_spine_object(spine::Attachment *a){
		attachment = a;
		if(attachment)
			attachment->reference();
	}
	inline spine::Attachment *get_spine_object(){
		return attachment;
	}

	godot::String get_attachment_name();

	godot::Ref<SpineAttachment> copy();
};

#endif //GODOT_SPINEATTACHMENT_H
