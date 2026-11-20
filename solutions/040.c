// 等差数列：升序排列后，检查相邻元素的差是否相同。
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
    int count, values[99];
    if (scanf("%d", &count) != 1 || count < 1 || count > 99) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            return 1;
        }
    }
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    int difference = count == 1 ? 0 : values[1] - values[0];
    for (int i = 2; i < count; ++i) {
        if (values[i] - values[i - 1] != difference) {
            puts("no");
            return 0;
        }
    }

    printf("%d\n", difference);
    return 0;
}
