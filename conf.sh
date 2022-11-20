#!/bin/bash
mkdir build
mkdir lib
cd lib
git clone https://github.com/google/googletest/
cd ..
cd build
make
cd ..