/*
 * =====================================================================================
 *
 *       Filename:  aqnote_linked_list.h
 *
 *    Description: 排序头文件
 *
 *        Version:  1.0
 *        Created:  03/31/19 19:17:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef _AQNOTE_ALGORITHM_SORT_H
#define _AQNOTE_ALGORITHM_SORT_H

#ifdef __CPLUSPLUS
extern "C" {
#endif

/**
 * DESC: 冒泡排序
 *
 * @param array
 * @param n
 *
 * @return
 */
void aqnote_sort_bubble(int array[], int n);

/**
 * function: 插入排序
 *
 * @param array
 * @param n
 *
 * @return
 */
void aqnote_sort_insert(int array[], int n);

/**
 * function: 选择排序
 *
 * @param array
 * @param n
 *
 * @return
 */
void aqnote_sort_select(int array[], int n);

/**
 * function: 选择排序
 *
 * @param array
 * @param n
 *
 * @return
 */
void aqnote_sort_quick(int array[], int n);

#ifdef __CPLUSPLUS
}
#endif

#endif