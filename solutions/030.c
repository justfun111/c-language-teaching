// 完数：因子 d 和 number / d 成对，平方根只加一次。
#include <stdio.h>

static int is_perfect(int number)
{
    if (number < 2) {
        return 0;
    }

    int sum = 1;
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            int paired = number / divisor;
            sum += divisor;
            if (paired != divisor) {
                sum += paired;
            }
        }
    }
    return sum == number;
}

int main(void)
{
    int lower, upper;
    if (scanf("%d%d", &lower, &upper) != 2) {
        return 1;
    }

    for (int value = lower; value <= upper; ++value) {
        if (is_perfect(value)) {
            printf("%d\n", value);
        }
    }
    return 0;
}
