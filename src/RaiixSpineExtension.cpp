//
// Created by Raymond_Lx on 2020/6/2.
//

#include "RaiixSpineExtension.h"

#include <spine/SpineString.h>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/file.hpp>

#include <iostream>

spine::SpineExtension *spine::getDefaultExtension() {
    return new RaiixSpineExtension();
}

RaiixSpineExtension::RaiixSpineExtension(){}
RaiixSpineExtension::~RaiixSpineExtension(){}

void *RaiixSpineExtension::_alloc(size_t size, const char *file, int line){
//	std::cout<<"_alloc "<<file<<" "<<line<<std::endl;
    return godot::Memory::alloc_static(size);
}

void *RaiixSpineExtension::_calloc(size_t size, const char *file, int line){
//	std::cout<<"_calloc "<<file<<" "<<line<<std::endl;
    auto p = godot::Memory::alloc_static(size);
    memset(p, 0, size);
    return p;
}

void *RaiixSpineExtension::_realloc(void *ptr, size_t size, const char *file, int line){
//	std::cout<<"_realloc "<<file<<" "<<line<<std::endl;
    return godot::Memory::realloc_static(ptr, size);
}

void RaiixSpineExtension::_free(void *mem, const char *file, int line){
//	std::cout<<"_free "<<file<<" "<<line<<std::endl;
    godot::Memory::free_static(mem);
}

char *RaiixSpineExtension::_readFile(const spine::String &path, int *length){
    int error;
    godot::Ref<godot::File> file;
    file.instantiate();
    if(file->open(godot::String(path.buffer()), godot::File::READ) != godot::OK) {
        if(length) *length = 0;
        return nullptr;
    }
    
    auto res = file->get_as_text();
    file->close();
    
    if(length) *length = res.length();
    auto r = alloc<char>(res.length(), __FILE__, __LINE__);
    for(size_t i=0;i<res.length();++i)
        r[i] = res[i];
    return r;
}