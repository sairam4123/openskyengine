@echo off
cd %~dp0
cmake -B build -S . -G "NMake Makefiles" 
cd build 
nmake 
start .
cd ..
pause