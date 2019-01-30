
//g++ -O3 -Wall --std=c++11 code06.cpp -o code06.out -lpthread

#include <queue>
#include <thread>
#include <mutex>
#include <iostream>


std::queue<int> stdQueue;
int sum = 0;
std::mutex mt;

void produce()
{
	for (int i = 1; i <= 100; ++i){
		std::lock_guard<std::mutex> lock(mt);
		stdQueue.push(i);
	}
}

void consume()
{
	std::lock_guard<std::mutex> lock(mt);
	while (!stdQueue.empty()){
		sum += stdQueue.front();
		stdQueue.pop();
	}
}

int main()
{
	std::thread t1{produce};
	std::thread t1a{produce};
	std::thread t2{consume};
	std::thread t3{consume};
	t3.join();
	t1.join();
	t2.join();
	t1a.join();
	
	
	std::cout << sum << '\n';
}
