
//g++ -O3 -Wall --std=c++11 code08.cpp -o code08.out -pthread -lboost_system -lboost_thread

#include <thread>
#include <atomic>
#include <iostream>
#include <vector>

#include <boost/lockfree/queue.hpp>

std::atomic_int producer_count(0);
std::atomic_int consumer_count(0);
std::atomic<bool> done(false);

boost::lockfree::queue<int> queue(128);

const int iterations = 10000000;
const int producer_thread_count = 4;
const int consumer_thread_count = 4;

void producer(void)
{
	for (int i = 0; i != iterations; ++i) {
		int value = ++producer_count;
		while (!queue.push(value))
			;
	}
}

void consumer(void)
{
	int value;
	while (!done) {
		while (queue.pop(value))
			++consumer_count;
	}
	while (queue.pop(value))
		++consumer_count;
}

int main(int argc, char* argv[])
{
	std::cout << "boost::lockfree::queue is ";
	if (!queue.is_lock_free())
		std::cout << "not ";
	std::cout << "lockfree" << std::endl;

	std::vector<std::thread> producer_threads;
	std::vector<std::thread> consumer_threads;

	for (int i = 0; i != producer_thread_count; ++i)
		producer_threads.push_back(std::thread(producer));

	for (int i = 0; i != consumer_thread_count; ++i)
		consumer_threads.push_back(std::thread(consumer));

	std::cout << "All threads created.\n";
	for (auto& i : producer_threads) {
		i.join();
	}
	std::cout << "All producers joined.\n";
	done = true;
	std::cout << "joining consumers.\n";
	for (auto& i : consumer_threads) {
		i.join();
	}
	std::cout << "all consumer threads joined\n";

	std::cout << "produced " << producer_count << " objects." << std::endl;
	std::cout << "consumed " << consumer_count << " objects." << std::endl;
}
