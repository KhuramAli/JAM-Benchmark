
//g++ -O3 -Wall --std=c++11 code09.cpp -o code09.out -pthread -lboost_system -lboost_thread

#include <thread>
#include <boost/circular_buffer.hpp>
#include <iostream>

#include <mutex>

int producer_count = 0;
int consumer_count = 0;
// Create a circular buffer of capacity 1024.
boost::circular_buffer<int> cb(1024);
std::mutex myMutex;
const int iterations = 10000000;

void producer(void)
{
	for (int i = 0; i != iterations; ++i) {
		int value = ++producer_count;
		myMutex.lock();
		cb.push_back(value);
		myMutex.unlock();
	}
}

bool done = false;

void consumer(void)
{
	while (!done) {
		myMutex.lock();
		if(!cb.empty()){
			cb.pop_front();
			++consumer_count;
		}
		myMutex.unlock();
	}
}

int main(int argc, char* argv[])
{
	std::thread producer_thread(producer);
	std::thread consumer_thread(consumer);

	producer_thread.join();

	done = true;
	consumer_thread.join();

	std::cout << "produced " << producer_count << " objects." << std::endl;
	std::cout << "consumed " << consumer_count << " objects." << std::endl;
}

