#!/bin/bash

set -x

if [[ "$OSTYPE" == "darwin"* ]]; then
	scons platform=osx target=release
else
	scons platform=linux target=release
