// 最小差值：排序后只需检查相邻元素。
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
    int count, values[1000];
    if (scanf("%d", &count) != 1 || count < 2 || count > 1000) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            return 1;
        }
    }
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    int minimum = values[1] - values[0];
    for (int i = 2; i < count; ++i) {
        int difference = values[i] - values[i - 1];
        if (difference < minimum) {
            minimum = difference;
        }
    }

    printf("%d\n", minimum);
    return 0;
}
