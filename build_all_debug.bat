@echo off
for /f "delims=" %%i in ('where vcvarsall.bat') do set vcvars=%%i
call "%vcvars%" x64
cd godot-cpp
scons platform=windows target=debug -j4
cd ..
scons platform=windows target=debug