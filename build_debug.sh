#!/bin/bash

set -x

if [[ "$OSTYPE" == "darwin"* ]]; then
	scons platform=osx target=debug
else
	scons platform=linux target=debug
fi
