#include <iostream>
#include <utility>
#include <atomic>
#include <limits>

constexpr int min_int = std::numeric_limits<int>::min();
constexpr int max_int = std::numeric_limits<int>::max();
constexpr int64_t min_int64_t = std::numeric_limits<int64_t>::min();
constexpr int64_t max_int64_t = std::numeric_limits<int64_t>::max();

constexpr int size = 100;
 
struct A { int a[size]; };
struct B { int x, y; };
struct C { int64_t x, y;};
int main()
{
    std::atomic<A> a;
    std::atomic<B> b;
    std::atomic<C> c;

    std::cout << "sizeof int: " << sizeof(int) << '\n';
    std::cout << "sizeof int64_t: " << sizeof(int64_t) << '\n';
    std::cout << "minimum numeric limit of int: " << min_int << '\n'; 			
    std::cout << "maximum numeric limit of int: " << max_int << '\n';
    std::cout << "minimum numeric limit of min_int64_t: " << min_int64_t << '\n';			
    std::cout << "maximum numeric limit of max_int64_t: " << max_int64_t << '\n';
    std::cout << "size of struct A: " << sizeof(int) * size << '\n';
    std::cout << "size of struct B: " << sizeof(b) << '\n';
    std::cout << "size of struct C: " << sizeof(c) << '\n';

    std::cout << std::boolalpha
              << "std::atomic<A> with an array of " << size <<  " is lock free? "
              << std::atomic_is_lock_free(&a) << '\n'
              << "std::atomic<B> with two ints is lock free? "
              << std::atomic_is_lock_free(&b) << '\n'
	      << "std::atomic<C> with two int64_t is lock free? "
	      << std::atomic_is_lock_free(&c) << '\n';
}
