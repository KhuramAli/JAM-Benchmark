//installing boost
//sudo apt-get install libboost-all-dev
//g++ -O3 -Wall --std=c++11 -pthread -lboost_system -lboost_thread code03.cpp -o code03.out

#include <boost/lockfree/queue.hpp>
#include <thread>
#include <atomic>
#include <iostream>

boost::lockfree::queue<int, boost::lockfree::fixed_sized<true>> q{10000};
std::atomic<int> sum{0};

void produce()
{
	for (int i = 1; i <= 10000; ++i)
		q.push(i);
}

void consume()
{
	int i;
	while (q.pop(i))
		sum += i;
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
