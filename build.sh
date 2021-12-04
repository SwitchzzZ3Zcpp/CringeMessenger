#!/bin/bash 
echo "Building CringeMessenger..."
rm -rf build
mkdir build
cd build
cmake ..
make
cp CringeMessenger ..
cd ..
rm -rf build
if [[ $1 = --run ]]; then
./CringeMessenger
fi
