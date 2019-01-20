

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 3

void *runnable(void *arg);

int main()
{
    int res;
    pthread_t thread_array[NUM_THREADS];
    void *thread_result;
    for(int i=0; i < NUM_THREADS; i++) 
    {
        res = pthread_create(&thread_array[i], NULL, runnable, (void *)&i);
        if(res != 0)
        {
            perror("thread_create failure.\n");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }

    printf("waiting thread finish ...\n");
    
    for(int i=0; i < NUM_THREADS; i++) 
    {
        res = pthread_join(thread_array[i], &thread_result);
        if(res == 0) 
            printf("a thread finished.\n");
        else 
            perror("thread finish failure\n");
    }
    printf("all thread finished.\n");
    exit(EXIT_SUCCESS);
}

void *runnable(void *arg)
{
    int number = * (int *)arg;
    printf("%d thread is running...\n", number);
    int rand_num = 1 + (int)(9.0 * rand() / (RAND_MAX + 1.0));
    sleep(rand_num);
    printf("%d thread finished.\n", number);


    pthread_exit(NULL);
}
