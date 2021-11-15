#!/bin/bash

set -x

cd godot-cpp

if [[ "$OSTYPE" == "darwin"* ]]; then
	scons platform=osx target=debug -j4
else
	scons platform=linux target=debug -j4
fi
cd ..

if [[ "$OSTYPE" == "darwin"* ]]; then
	scons platform=osx target=debug
else
	scons platform=linux target=debug
fi
