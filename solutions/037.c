// 按规则排序：先比较奇偶，再按数值从大到小排列。
#include <stdio.h>  // 引入 scanf()、printf()、putchar() 的声明。
#include <stdlib.h>  // 引入 qsort() 的声明。

// 定义比较函数，让 qsort 先按奇偶再按大小排序。
static int compare_by_parity(const void *left, const void *right)
{  // 开始辅助函数的函数体。
    int a = *(const int *)left;  // 通过指针读取左侧的整数。
    int b = *(const int *)right;  // 通过指针读取右侧的整数。
    int a_is_odd = a % 2 != 0;  // 余数不等于 0 时左值是奇数，负奇数也适用。
    int b_is_odd = b % 2 != 0;  // 用同样规则把右值转换为 0 或 1 的奇偶标记。

    if (a_is_odd != b_is_odd) {  // 两个数奇偶不同时，先用奇偶规则决定顺序。
        return a_is_odd - b_is_odd;  // 偶数的标记为 0，奇数为 1，因此偶数排在前面。
    }  // 结束当前条件分支。
    return (a < b) - (a > b);  // 奇偶相同就按数值降序，左值较大时返回负数。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, values[100];  // count 保存数量，values 预留 100 个整数的位置。
    if (scanf("%d", &count) != 1 || count < 0 || count > 100) {  // 读取数量并检查它能否放进数组。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    for (int i = 0; i < count; ++i) {  // 从下标 0 开始填入 count 个元素。
        if (scanf("%d", &values[i]) != 1) {  // 把当前整数读进下标 i 对应的数组位置。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    qsort(values, (size_t)count, sizeof values[0], compare_by_parity);  // 按上述比较函数对整个数组排序。
    for (int i = 0; i < count; ++i) {  // 按数组中已经排好的顺序遍历元素。
        printf("%s%d", i == 0 ? "" : " ", values[i]);  // 第一项前没有空格，后续各项前加一个空格。
    }  // 结束本层 for 循环。
    putchar('\n');  // 输出全部元素后换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
