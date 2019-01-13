SUBDIRS = pthread_counter_example_1	pthread_counter_example_2	lock_synchronzied_Summation	lock_free_Summation	lock_and_lockfree	embb_lockfree_stack	embb_lockfree_mpmc_queue	boost_Lock-Synchronized_Single-Producer_Single-Consumer_RingBuffer	boost_Lock-Synchronized_Multi-producer_Multi-consumer	boost_lockfree_spsc_queue	boost_Lock-free_Single-Producer_Single-Consumer_RingBuffer	boost_lockfree_queue	boost_Lock-free_Multi-producer_Multi-consumer

.PHONY: all clean

all clean:
	for	dir	in	$(SUBDIRS);	do	\
    $(MAKE) -C $$dir -f Makefile $@; \
  done
