//gcc -pthread code01.c -o code01.out
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
 
atomic_int acnt;
int cnt;
 
void *f()
{
    for(int n = 0; n < 1000; ++n) {
        ++cnt;
        ++acnt;
    }
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
