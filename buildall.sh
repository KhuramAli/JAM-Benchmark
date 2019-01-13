#!/bin/bash -v

echo "installing boost"
sudo apt-get install libboost-all-dev
echo "installing embb"
sudo chmod u+x embbInstall.sh
sudo ./embbInstall.sh

make
