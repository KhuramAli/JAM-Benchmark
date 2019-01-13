#!/bin/bash

#download embb from github
wget https://github.com/siemens/embb/releases/download/v1.0.0/embb-1.0.0.tar.gz

#install cmake
sudo apt-get install cmake

#untar downlaoded file
tar xfz embb-1.0.0.tar.gz

#create subdirectory and change to it
cd embb-1.0.0
mkdir build
cd build

#Generate the build files using CMake: 
cmake ..

#compile Embb
cmake --build .

#run tests
binaries/run_tests.sh

#install
sudo cmake --build . --target install
