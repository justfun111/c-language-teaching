// 统计正整数的个数：排序后，相同的数字连续出现。
#include <stdio.h>
#include <stdlib.h>

static int compare_int(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

int main(void)
{
    int count, values[29];
    if (scanf("%d", &count) != 1 || count < 1 || count > 29) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            return 1;
        }
    }
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    for (int start = 0; start < count;) {
        int end = start + 1;
        while (end < count && values[end] == values[start]) {
            ++end;
        }
        printf("%d:%d\n", values[start], end - start);
        start = end;
    }
    return 0;
}
