// 区间整数平方和：两个端点都参与求和。
#include <stdio.h>

int main(void)
{
    int lower, upper;
    if (scanf("%d%d", &lower, &upper) != 2) {
        return 1;
    }

    int sum = 0;
    for (int value = lower; value <= upper; ++value) {
        sum += value * value;
    }
    printf("%d\n", sum);
    return 0;
}
