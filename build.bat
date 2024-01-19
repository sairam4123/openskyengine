@echo off
cd %~dp0
cmake -B nbuild -S . -G "NMake Makefiles" 
cd nbuild 
nmake 
start .
cd ..
pause