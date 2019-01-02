//gcc -pthread code02.c -o code02.out

#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
 
atomic_int acnt;
int cnt;
 
void* f()
{
    for(int n = 0; n < 1000; ++n) {
        atomic_fetch_add_explicit(&acnt, 1, memory_order_relaxed); // atomic
        ++cnt; // undefined behavior, in practice some updates missed
    }
    return 0;
}
 
int main(void)
{
    pthread_t thr[10];
    for(int n = 0; n < 10; ++n)
        pthread_create(&thr[n], NULL, f, NULL);
    for(int n = 0; n < 10; ++n)
        pthread_join(thr[n], NULL);
 
    printf("The atomic counter is %u\n", acnt);
    printf("The non-atomic counter is %u\n", cnt);
}
