//installing boost
//sudo apt-get install libboost-all-dev
//g++ -O3 -Wall --std=c++11 -pthread -lboost_system -lboost_thread code04.cpp -o code04.out

#include <boost/lockfree/spsc_queue.hpp>
#include <boost/lockfree/policies.hpp>
#include <thread>
#include <iostream>

using namespace boost::lockfree;

spsc_queue<int, capacity<100>> q;
int sum = 0;

void produce()
{
	for (int i = 1; i <= 100; ++i)
		q.push(i);
}

void consume()
{
	while (q.consume_one([](int i) {sum += i;}));
}

int main()
{
	std::thread t1{produce};
	std::thread t2{consume};
	t1.join();
	t2.join();
	q.consume_all([](int i) {sum += i;});
	std::cout << sum << '\n';
}
