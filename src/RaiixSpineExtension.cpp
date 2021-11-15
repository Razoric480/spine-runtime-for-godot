//
// Created by Raymond_Lx on 2020/6/2.
// Ported to GDNative by Razoric on 2021/11.
//

#include "RaiixSpineExtension.h"

#include <spine/SpineString.h>
#include <Godot.hpp>
#include <File.hpp>

#include <iostream>

spine::SpineExtension *spine::getDefaultExtension() {
	return new RaiixSpineExtension();
}

RaiixSpineExtension::RaiixSpineExtension() {}
RaiixSpineExtension::~RaiixSpineExtension() {}

void *memalloc(size_t size) {
	return malloc(size);
}

void *memrealloc(void *ptr, size_t size) {
	return realloc(ptr, size);
}

void memfree(void *ptr) {
	free(ptr);
}

void *RaiixSpineExtension::_alloc(size_t size, const char *file, int line) {
	//	std::cout<<"_alloc "<<file<<" "<<line<<std::endl;
	return memalloc(size);
}

void *RaiixSpineExtension::_calloc(size_t size, const char *file, int line) {
	//	std::cout<<"_calloc "<<file<<" "<<line<<std::endl;
	auto p = memalloc(size);
	memset(p, 0, size);
	return p;
}

void *RaiixSpineExtension::_realloc(void *ptr, size_t size, const char *file, int line) {
	//	std::cout<<"_realloc "<<file<<" "<<line<<std::endl;
	return memrealloc(ptr, size);
}

void RaiixSpineExtension::_free(void *mem, const char *file, int line) {
	//	std::cout<<"_free "<<file<<" "<<line<<std::endl;
	memfree(mem);
}

char *RaiixSpineExtension::_readFile(const spine::String &path, int *length) {
	int error;
    godot::Ref<godot::File> file;
    file.instance();
    error = (int)file->open(godot::String(path.buffer()), godot::File::READ);
    if(error != GODOT_OK) {
        if(length) {
            *length = 0;
        }
            return nullptr;
    }
    godot::String res = file->get_as_text();
	file->close();
	//    std::cout<<"Spine is loading something: "<<path.buffer()<<std::endl;
	
	if (length) {
		*length = res.length();
    }
	auto r = alloc<char>(res.length(), __FILE__, __LINE__);
	for (size_t i = 0; i < res.length(); ++i) {
        r[i] = res[i];
    }
	return r;
}
