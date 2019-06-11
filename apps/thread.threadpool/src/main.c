/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/17/2018 12:22:46 PM
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
#include "threadpool.h"

void *myprocess(void *arg) {
    printf("threadid is 0x%x, working on task %d\n", pthread_self(),
           *(int *)arg);
    /*休息一秒，延长任务的执行时间*/
    sleep(1);
    return NULL;
}

int main(int argc, char **argv) {
    /*线程池中最多三个活动线程*/
    pool_init(3);

    /*连续向池中投入10个任务*/
    int *workingnum = (int *)malloc(sizeof(int) * 10);
    int  i;
    for (i = 0; i < 10; i++) {
        workingnum[i] = i;
        pool_add_worker(myprocess, &workingnum[i]);
    }
    /*等待所有任务完成*/
    sleep(5);

    /*销毁线程池*/
    pool_destroy();

    free(workingnum);
    return 0;
}