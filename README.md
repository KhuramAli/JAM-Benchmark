
Please run shell script ./buildall.sh to build all examples with all their dependencies. 
It will also install boost and embb libraries. 
You can run make and make clean in the root directory also.

There are three catagories of the examples, 

1- Same program with lock-synchronized and lock-free,


Multi-producer_Multi-consumer_Lock-free_boost

Multi-producer_Multi-consumer_Lock-Synchronized_boost

Single-Producer_Single-Consumer_RingBuffer_Lock-free_boost

Single-Producer_Single-Consumer_RingBuffer_Lock-Synchronized_boost

Summation_lock_free_cppThread

Summation_lock_synchronzied_cppThread



2- Examples with lock-synchronization and lock-free in one program

counter_example_1_pthread

counter_example_2_pthread

lock_and_lockfree



3- examples of lock-free data structures

mpmc_queue_lockfree_embb

stack_lockfree_embb

queue_lockfree_boost

spsc_queue_lockfree_boost

