@echo off
for /f "delims=" %%i in ('where vcvarsall.bat') do set vcvars=%%i
call "%vcvars%" x64
scons platform=windows target=debug