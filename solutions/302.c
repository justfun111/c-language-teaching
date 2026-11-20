// 质数求和：按从小到大的顺序找到并编号，只累加指定的 11 项。
#include <stdio.h>

static int is_prime(int number)
{
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return number >= 2;
}

int main(void)
{
    int first;
    if (scanf("%d", &first) != 1 || first < 1) {
        return 1;
    }

    int index = 0, sum = 0;
    for (int number = 2; index < first + 10; ++number) {
        if (is_prime(number)) {
            ++index;
            if (index >= first) {
                sum += number;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}
