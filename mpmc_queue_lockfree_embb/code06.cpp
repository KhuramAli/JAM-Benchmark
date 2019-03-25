
//g++ -O3 -Wall --std=c++11 code06.cpp -o code06.out -lembb_dataflow_cpp -lembb_algorithms_cpp -lembb_containers_cpp -lembb_mtapi_cpp -lembb_mtapi_c -lembb_base_cpp -lembb_base_c -lpthread

#include<embb/containers/lock_free_mpmc_queue.h>
#include <thread>
#include <atomic>
#include <iostream>

embb::containers::LockFreeMPMCQueue<int> queue(100);
std::atomic<int> sum{0};

void produce()
{
	for (int i = 1; i <= 100; ++i)
		queue.TryEnqueue(i);
}

void consume()
{
	int i;
	while (queue.TryDequeue(i))
		sum += i;
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
