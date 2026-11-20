// 按规则排序：先比较奇偶，再按数值从大到小排列。
#include <stdio.h>
#include <stdlib.h>

static int compare_by_parity(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    int a_is_odd = a % 2 != 0;
    int b_is_odd = b % 2 != 0;

    if (a_is_odd != b_is_odd) {
        return a_is_odd - b_is_odd;
    }
    return (a < b) - (a > b);
}

int main(void)
{
    int count, values[100];
    if (scanf("%d", &count) != 1 || count < 0 || count > 100) {
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            return 1;
        }
    }
    qsort(values, (size_t)count, sizeof values[0], compare_by_parity);
    for (int i = 0; i < count; ++i) {
        printf("%s%d", i == 0 ? "" : " ", values[i]);
    }
    putchar('\n');
    return 0;
}
