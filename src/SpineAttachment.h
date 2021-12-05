//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINEATTACHMENT_H
#define GODOT_SPINEATTACHMENT_H

#include <godot_cpp/classes/ref_counted.hpp>

#include <spine/spine.h>

namespace godot {

class SpineAttachment : public RefCounted {
	GDCLASS(SpineAttachment, RefCounted);

protected:
	static void _bind_methods();

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

	String get_attachment_name();

	Ref<SpineAttachment> copy();
};

}

#endif //GODOT_SPINEATTACHMENT_H
