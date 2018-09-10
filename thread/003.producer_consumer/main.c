/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  同步
 *
 *        Version:  1.0
 *        Created:  08/17/2018 10:09:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

#define PRODUCER_THREAD_NUMS    2
#define CONSUMER_THREAD_NUMS    3
#define MAX_POOL_SIZE           1024

int object_pool_size = 0;
int object_pool_last_index = 0;
int object_pool_first_index = 0;
void *object_pool[MAX_POOL_SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void producer_runnable(void *arg);
void consumer_runnable(void *arg);

int main()
{
    int res;
    pthread_t producer_thread[PRODUCER_THREAD_NUMS];
    pthread_t consumer_thread[CONSUMER_THREAD_NUMS];
    void *thread_result;

    // Producer
    for(int i=0; i < PRODUCER_THREAD_NUMS; i++) 
    {
        res = pthread_create(&producer_thread[i], NULL, (void *)producer_runnable, (void *)&i);
        if(res != 0)
        {
            perror("producer thread_create failure.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Consumer
    for(int i=0; i < CONSUMER_THREAD_NUMS; i++) 
    {
        res = pthread_create(&consumer_thread[i], NULL, (void *)consumer_runnable, (void *)&i);
        if(res != 0)
        {
            perror("consumer thread_create failure.\n");
            exit(EXIT_FAILURE);
        }
    }

    // wait Producer finish
    for (int i=0; i < PRODUCER_THREAD_NUMS; i++)
    {
        res = pthread_join(producer_thread[i], &thread_result);
        if(res == 0) 
            printf("producer thread finished.\n");
        else 
            perror("producer thread finish failure\n");
    }

    // wait Consumer finish
    for (int i=0; i < CONSUMER_THREAD_NUMS; i++)
    {
        res = pthread_join(consumer_thread[i], &thread_result);
        if(res == 0) 
            printf("consumer thread finished.\n");
        else 
            perror("consumer thread finish failure\n");
    }

    exit(EXIT_SUCCESS);
}

// lock必须unlock，锁必须成对出现
void producer_runnable(void *arg)
{
    int i=0;
    int flag = 0;
    while(1)
    {
        // lock
        if(pthread_mutex_lock(&mutex) != 0)
        {
            perror("pthread_mutex_lock failure\n");
            exit(EXIT_FAILURE);
        }

        if(object_pool_size >= MAX_POOL_SIZE) 
        {
            printf("thread pool is full, waiting consumer...\n");
            flag = 1;
        } 
        else 
        {
            object_pool_last_index = (object_pool_last_index + 1)%MAX_POOL_SIZE;
            char tmp_value[10];
            sprintf(tmp_value, "%d", i);
            object_pool[object_pool_last_index] =  tmp_value;
            printf("thread 0x%x producer %d, pool_size %d\n", pthread_self(), i++, ++object_pool_size);
        }

        // unlock
        if(pthread_mutex_unlock(&mutex) != 0)
        {
            perror("pthread_mutex_unlock failure\n");
            exit(EXIT_FAILURE);
        }

        if(flag)
        {
            sleep(1);
            flag = 0;
        }
    }
}

void consumer_runnable(void *arg)
{
    int flag = 0;
    while(1) {
        if(pthread_mutex_lock(&mutex) != 0)
        {
            perror("pthread_mutex_lock failure\n");
            exit(EXIT_FAILURE);
        }

        if(object_pool_size <= 0) 
        {
            printf("thread pool is empty, waiting producer...\n");
            flag = 1;
        } 
        else 
        {
            char *tmpvalue = (char *)object_pool[(object_pool_first_index++)%MAX_POOL_SIZE];
            printf("thread 0x%x consume %s, pool_size %d\n", pthread_self(), tmpvalue, --object_pool_size);   
        }

        if(pthread_mutex_unlock(&mutex) != 0)
        {
            perror("pthread_mutex_unlock failure\n");
            exit(EXIT_FAILURE);
        }

        if(flag)
        {
            sleep(1);
            flag = 0;
        }
    }
}
