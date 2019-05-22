/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  05/22/19 11:09:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Y"Peng Li"<aqnote@aqnote.com>
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG

///////////////////////////////
/// UTIL
///////////////////////////////
int remove_newline_char(char *input);
int split_name(char *fullname, char *firstname, char *middlename,
               char *lastname);

///////////////////////////////
// TestCase
///////////////////////////////
int test_fgets();

int main(int argc, char **argv) {
    test_fgets();

    return 0;
}

// 读取包含空格的字符串输入
int test_fgets() {
    char *fullname   = malloc(256);
    char *firstname  = malloc(50);
    char *middlename = malloc(50);
    char *lastname   = malloc(50);
    printf("full name: ");
    // 读取字符串，以换行符结束（包括换行符）
    fgets(fullname, 256, stdin);
    // 过滤换行符
    remove_newline_char(fullname);
    printf("full name: [%s]\n", fullname);

    split_name(fullname, firstname, middlename, lastname);
    printf("first name: %s\n", firstname);
    printf("middle name: %s\n", middlename);
    printf("last name: %s\n", lastname);

    free(fullname);
    free(firstname);
    free(middlename);
    free(lastname);

    return 0;
}

/**
 * 去除字符串结尾的换行符
 * @param input 字符串首地址
 * @param size 字符串长度
 */
int remove_newline_char(char *input) {
    int len = strlen(input);
    for (int i = len - 1; i > 0; i--) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    return 0;
}

int split_name(char *fullname, char *firstname, char *middlename,
               char *lastname) {
    int len       = strlen(fullname);
    int step      = 0;
    int tmp_index = 0;
    for (int i = 0; i < len; i++) {
        if (fullname[i] == ' ' || i == len - 1) {
            int tmp_len = i - tmp_index;
#ifdef DEBUG
            printf("[DEBUG] i=%d, step=%d, tmp_index=%d, tmp_len=%d\n", i, step,
                   tmp_index, tmp_len);
#endif
            if (step == 0) {
                strncpy(firstname, fullname, tmp_len);
                firstname[tmp_len] = '\0';
                tmp_index          = i;
                step++;
            } else if (step == 1) {
                strncpy(middlename, fullname + tmp_index + 1, tmp_len);
                middlename[tmp_len] = '\0';
                tmp_index           = i;
                step++;
            } else if (step == 2) {
                strncpy(lastname, fullname + tmp_index + 1, tmp_len);
                lastname[tmp_len] = '\0';
            }
        }
    }

    return 0;
}

/*
aqnote@aqnote:std.stdio$ ./bin/std.stdio.app
Input:
123 456 789
Input: [123 456 789]
 */