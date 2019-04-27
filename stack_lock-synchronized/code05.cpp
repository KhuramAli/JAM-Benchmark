
//g++ -O3 -Wall --std=c++11 code05.cpp -o code05.out -lpthread

#include <thread>
#include <mutex>
#include <stack>
#include <iostream>

std::stack<int> stack; // create
int sum = 0;
std::mutex mtx;

void produce()
{
	for (int i = 1; i <= 100; ++i){
		std::lock_guard < std::mutex > lock(mtx);
		stack.push(i);
	}
}

void consume()
{
	while (!stack.empty()){
		std::lock_guard < std::mutex > lock(mtx);
		sum += stack.top();
		stack.pop();
	}
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
