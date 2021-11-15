# Spine Runtime for Godot Engine

spine runtime version [4.0.x](https://github.com/EsotericSoftware/spine-runtimes/commit/555c124a4440526ac2b89232e12037563c0e0100)

godot engine version 3.x

This project is a GDNative library for Godot engine, used to load Spine's skeleton animation and render and play.

Applicable to Spine 4.0.x version.

# Description
Added SpineSprite node for loading Spine's skeletal animation (need to provide .atlas file, picture file and .json file, atlas resource will automatically load picture), and provide methods for controlling animation playback, animation mixing, etc. At the same time, it provides corresponding signals for processing the events emitted by the skeleton animation.

# Gotchas
Compiling godot for debug (-Od flag) will severely impact performance
Compile with -O2 flag for godot engine and run linker can double fps

# Compilation instructions

## Requirements

- `scons` (Install via `python3 -m pip install scons`, or just `python -m pip install scons` on Windows)
- On Windows: Visual Studio Build Tools (easiest is to install Visual Studio 2019 Community) to gain access to VCVarsall and compiler.

## Steps

1. Run `git submodule update --init --recursive`
2. Run `sh build_all_release.sh` Linux/Mac, or `build_all_release.bat` on Windows.
3. Open `./godot/` project and check `RunSprite.tscn` and `MixAndMatch.tscn` to ensure it works.

## Caveats

There are still some crashes and bugs to iron out due to the conversion from module to GDScript. User discretion is advised.

# License
According to Spine's official statement, the use of spine-runtime-cpp is required under [Spine Runtime License Agreement](http://zh.esotericsoftware.com/spine-runtimes-license).

Other code except those under `spine-cpp` folder is under MIT license.
