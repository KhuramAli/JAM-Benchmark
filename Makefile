SUBDIRS = counter_example_1_pthread	counter_example_2_pthread	is_lockfree	lock_synchronzied_Summation	lock_free_Summation	lock_and_lockfree	mpmc_queue_lockfree_embb	mpmc_queue_lock_synchronized	Multi-producer_Multi-consumer_Lock-free_boost	Multi-producer_Multi-consumer_Lock-Synchronized_boost	Multi-producer_Multi-consumer_Lock-Synchronized_boost	queue_lock-Synchronzied	Single-Producer_Single-Consumer_RingBuffer_Lock-free_boost	Single-Producer_Single-Consumer_RingBuffer_Lock-Synchronized_boost	spsc_queue_lockfree_boost	stack_lockfree_embb	stack_lock-synchronized	Summation_lock_free_cppThread	Summation_lock_synchronzied_cppThread
.PHONY: all clean

all clean:
	for	dir	in	$(SUBDIRS);	do	\
    $(MAKE) -C $$dir -f Makefile $@; \
  done
