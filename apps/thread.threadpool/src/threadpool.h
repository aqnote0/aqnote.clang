/*
 * =====================================================================================
 *
 *       Filename:  threadpool.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/17/2018 12:22:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <pthread.h>

extern void pool_init(int max_thread_num);
extern int  pool_add_worker(void *(*process)(void *arg), void *arg);
int         pool_destroy();

#endif