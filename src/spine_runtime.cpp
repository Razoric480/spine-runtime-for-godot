#include "spine_runtime.h"

#include <iostream>

void SpineRuntime::hi() {
	std::cout << "Hi im raiix!~ from spine runtime" << std::endl;
}

void SpineRuntime::_init() {}

void SpineRuntime::_register_methods() {
    godot::register_method("hi", &SpineRuntime::hi);
}

SpineRuntime::SpineRuntime() {
}