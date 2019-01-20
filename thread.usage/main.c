
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *runnable(void *arg);

char message [] = "PThread Usage";

int main() 
{
    int res;
    pthread_t thread_id;
    void *thread_result;

    res = pthread_create(&thread_id, NULL, runnable, (void *)message);
    if(res != 0) 
    {
        perror("pthread_create failure");
        exit(EXIT_FAILURE);
    }
    printf("waiting for thread ...\n");

    res = pthread_join(thread_id, &thread_result);
    if(res != 0)
    {
        perror("pthread_join failure");
        exit(EXIT_FAILURE);
    }
    printf("thread finished.\n");

    printf("message = %s\n", message);
    exit(EXIT_SUCCESS);
}

void *runnable(void *arg)
{
    printf("thread is running, param is %s\n", arg);
    sleep(5);
    pthread_exit("thread execute finished");
}