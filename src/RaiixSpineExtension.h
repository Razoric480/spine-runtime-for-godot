//
// Created by Raymond_Lx on 2020/6/2.
// Ported to GDNative by Razoric on 2021/11.
//

#ifndef GODOT_RAIIXSPINEEXTENSION_H
#define GODOT_RAIIXSPINEEXTENSION_H

#include <spine/Extension.h>

class RaiixSpineExtension : public spine::SpineExtension {
public:
	RaiixSpineExtension();

	virtual ~RaiixSpineExtension();

protected:
	virtual void *_alloc(size_t size, const char *file, int line);

	virtual void *_calloc(size_t size, const char *file, int line);

	virtual void *_realloc(void *ptr, size_t size, const char *file, int line);

	virtual void _free(void *mem, const char *file, int line);

	virtual char *_readFile(const spine::String &path, int *length);
};

void *memalloc(size_t size);
void *memrealloc(void *ptr, size_t size);
void memfree(void *ptr);

#endif //GODOT_RAIIXSPINEEXTENSION_H
