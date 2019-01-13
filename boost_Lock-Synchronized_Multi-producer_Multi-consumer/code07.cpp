
//g++ -O3 -Wall --std=c++11 code07.cpp -o code07.out -pthread

#include <thread>
#include <deque>
#include <iostream>
#include <vector>
#include <mutex>

int producer_count = 0;
int consumer_count = 0;

// a global instance of std::mutex to protect global variable
std::mutex myMutex1;


std::deque<int> queue;

const int iterations = 10000000;
const int producer_thread_count = 4;
const int consumer_thread_count = 4;

void producer(void)
{
	for (int i = 0; i != iterations; ++i) {
		// the addition is mutually exclusive
		myMutex1.lock();
		queue.push_front(++producer_count);
		myMutex1.unlock();
	}
}

bool done = false;
void consumer(void)
{
	int value =0;
	while (!done) {
		myMutex1.lock();
		if (!queue.empty()) {
			value += queue.front();
			++consumer_count;
			queue.pop_front();
		}
		else if(producer_count >= iterations) {
			myMutex1.unlock();
			return;
		}
		myMutex1.unlock();
	}
}

int main(int argc, char* argv[])
{
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
