// 选号程序：先比较各位数字和，分数相同再比较号码。
#include <stdio.h>

static int digit_sum(int number)
{
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main(void)
{
    int count, best_number = 0, best_sum = -1;
    if (scanf("%d", &count) != 1 || count < 1) {
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        int number;
        if (scanf("%d", &number) != 1) {
            return 1;
        }
        int sum = digit_sum(number);
        if (sum > best_sum || (sum == best_sum && number > best_number)) {
            best_number = number;
            best_sum = sum;
        }
    }

    printf("%d\n", best_number);
    return 0;
}
