#!/bin/bash

mkdir _BUILD
cd _BUILD
rm CMakeCache.txt cmake_install.cmake comm Makefile
rm -r CMakeFiles
cmake -G"Unix Makefiles" ..
make
./comm
