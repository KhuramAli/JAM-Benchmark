﻿//g++ -O3 -Wall --std=c++11 -pthread code03.cpp -o code03.out

#include <queue>
#include <thread>
#include <mutex>
#include <iostream>

std::queue<int> q;
int sum = 0;
std::mutex mtx;

void produce()
{
	for (int i = 1; i <= 10000; ++i){
		std::lock_guard<std::mutex> lock(mtx);
		q.push(i);
	}
}

void consume()
{
	while (!q.empty()){
		std::lock_guard<std::mutex> lock(mtx);
		if(!q.empty()){
			sum += q.front();
			q.pop();
		}
	}
}

int main()
{
	std::thread t1{produce};
	std::thread t2{consume};
	std::thread t3{consume};
	t1.join();
	t2.join();
	t3.join();
	consume();
	std::cout << sum << '\n';
}
