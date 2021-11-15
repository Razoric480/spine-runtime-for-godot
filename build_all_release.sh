#!/bin/bash

set -x

cd godot-cpp

if [[ "$OSTYPE" == "darwin"* ]]; then
	scons platform=osx target=release -j4
else
	scons platform=linux target=release -j4
fi
cd ..

if [[ "$OSTYPE" == "darwin"* ]]; then
	scons platform=osx target=release
else
	scons platform=linux target=release
fi
