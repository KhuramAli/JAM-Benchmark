
//g++ -O3 -Wall --std=c++11 code05.cpp -o code05.out -lembb_dataflow_cpp -lembb_algorithms_cpp -lembb_containers_cpp -lembb_mtapi_cpp -lembb_mtapi_c -lembb_base_cpp -lembb_base_c -lpthread

#include <embb/containers/lock_free_stack.h>
#include <thread>
#include <atomic>
#include <iostream>

embb::containers::LockFreeStack<int> stack(100); // create
std::atomic<int> sum{ 0 };

void produce()
{
	for (int i = 1; i <= 100; ++i)
		stack.TryPush(i);
}

void consume()
{
	int i;
	while (stack.TryPop(i))
		sum += i;
}

int main()
{
	std::thread t1{ produce };
	std::thread t2{ consume };
	std::thread t3{ consume };
	t1.join();
	t2.join();
	t3.join();
	consume();
	std::cout << sum << '\n';
}
