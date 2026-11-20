// 数字个数统计：两个整除条件恰好成立一个时才计数。
#include <stdio.h>

int main(void)
{
    int lower, upper;
    if (scanf("%d%d", &lower, &upper) != 2) {
        return 1;
    }
    if (lower > upper) {
        int temporary = lower;
        lower = upper;
        upper = temporary;
    }

    int count = 0;
    for (int number = lower; number <= upper; ++number) {
        int divisible_by_7 = number % 7 == 0;
        int divisible_by_11 = number % 11 == 0;
        if (divisible_by_7 != divisible_by_11) {
            ++count;
        }
    }

    printf("%d\n", count);
    return 0;
}
