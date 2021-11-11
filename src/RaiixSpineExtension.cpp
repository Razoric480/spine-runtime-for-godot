//
// Created by Raymond_Lx on 2020/6/2.
//

#include "RaiixSpineExtension.h"

#include <spine/SpineString.h>
#include <File.hpp>
#include <Godot.hpp>

#include <stdlib.h>
#include <iostream>

spine::SpineExtension *spine::getDefaultExtension() {
	return new RaiixSpineExtension();
}

void *do_alloc(size_t size) {
	return malloc(size);
}

void *do_realloc(void *ptr, size_t size) {
	return realloc(ptr, size);
}

void do_free(void *ptr) {
	free(ptr);
}

RaiixSpineExtension::RaiixSpineExtension() {}
RaiixSpineExtension::~RaiixSpineExtension() {}

void *RaiixSpineExtension::_alloc(size_t size, const char *file, int line) {
	//	std::cout<<"_alloc "<<file<<" "<<line<<std::endl;
	return do_malloc(size);
}

void *RaiixSpineExtension::_calloc(size_t size, const char *file, int line) {
	//	std::cout<<"_calloc "<<file<<" "<<line<<std::endl;
	auto p = do_malloc(size);
	memset(p, 0, size);
	return p;
}

void *RaiixSpineExtension::_realloc(void *ptr, size_t size, const char *file, int line) {
	//	std::cout<<"_realloc "<<file<<" "<<line<<std::endl;
	return do_realloc(ptr, size);
}

void RaiixSpineExtension::_free(void *mem, const char *file, int line) {
	//	std::cout<<"_free "<<file<<" "<<line<<std::endl;
	do_free(mem);
}

char *RaiixSpineExtension::_readFile(const spine::String &path, int *length) {
	godot::Error error;

	godot::Ref<godot::File> file;
	file.instance();
	if (file->open(godot::String(path.buffer()), godot::File::ModeFlags::READ) == godot::Error::OK) {
		godot::PoolByteArray res = file->get_buffer(*length);

		if (length) {
			*length = res.size();

			auto r = alloc<char>(res.size(), __FILE__, __LINE__);
			for (size_t i = 0; i < res.size(); ++i) {
				r[i] = res[i];
			}
			return r;
		}
	} else {
		if (length) {
			*length = 0;
		}
		return nullptr;
	}
}