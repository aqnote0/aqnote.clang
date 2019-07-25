/*
 * ===========================================================================
 *
 *       Filename:  aqnote.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  04/24/19 19:48:20
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  "Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * ===========================================================================
 */

#ifdef __CPLUSPLUS
extern "C" {
#endif

/**
 * 1.直接使用地址&代替指针进行swap
 * 2.使用指针对a，b进行swap
 */
int swap(int *pa, int *pb);
int swap1(int *pa, int *pb);

/**
 * 判断是否闰年
 *
 * @param year 输入年
 * @param result 结果是否闰年
 *    1 表示闰年
 *    0 表示非闰年
 *
 * @return int 返回结果
 *      0 表示执行正常
 */
int is_leap_year(const int year, int *result);

/**
 * 将天转为日期
 *
 * @param noday 输入日期
 * @param year 输出年
 * @param week 输出第几个星期
 * @param day 输出这个星期的星期几
 *
 * @return int 返回结果
 *      0 表示执行正常
 */
int day_to_date(const int noday, int *year, int *week, int *day);

/**
 * 判断输入的三个数中最大的那个数字
 *
 * @param num1 第一个数字
 * @param num2 第二个数字
 * @param num3 第三个数字
 * @param result 最大值，返回地址
 *
 * @return int 返回结果
 *      0 表示执行正常
 */
int max(const int num1, const int num2, const int num3, int *result);

#ifdef __CPLUSPLUS
}
#endif