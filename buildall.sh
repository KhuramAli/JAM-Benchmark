#!/bin/bash -v

echo "installing boost"
sudo apt-get install libboost-all-dev
echo "installing embb"
sudo chmod u+x embbInstall.sh
sudo ./embbInstall.sh
mkdir bin
gcc -pthread code01.c -o bin/code01.out
gcc -pthread code02.c -o bin/code02.out
g++ -O3 -Wall --std=c++11 -pthread -lboost_system -lboost_thread code03.cpp -o bin/code03.out
g++ -O3 -Wall --std=c++11 -pthread -lboost_system -lboost_thread code04.cpp -o bin/code04.out
g++ -O3 -Wall --std=c++11 code05.cpp -o bin/code05.out -lembb_dataflow_cpp -lembb_algorithms_cpp -lembb_containers_cpp -lembb_mtapi_cpp -lembb_mtapi_c -lembb_base_cpp -lembb_base_c -lpthread
g++ -O3 -Wall --std=c++11 code06.cpp -o bin/code06.out -lembb_dataflow_cpp -lembb_algorithms_cpp -lembb_containers_cpp -lembb_mtapi_cpp -lembb_mtapi_c -lembb_base_cpp -lembb_base_c -lpthread
g++ -O3 -Wall --std=c++11 code07.cpp -o bin/code07.out -pthread
g++ -O3 -Wall --std=c++11 code08.cpp -o bin/code08.out -pthread -lboost_system -lboost_thread
g++ -O3 -Wall --std=c++11 code09.cpp -o bin/code09.out -pthread -lboost_system -lboost_thread
g++ -O3 -Wall --std=c++11 code10.cpp -o bin/code10.out -pthread -lboost_system -lboost_thread
g++ -O3 -Wall --std=c++11 code11.cpp -o bin/code11.out -pthread 
g++ -O3 -Wall --std=c++11 code12.cpp -o bin/code12.out -pthread 
g++ -O3 -Wall --std=c++11 code13.cpp -o bin/code13.out -pthread 
