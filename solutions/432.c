// 整数位数计算：每除以 10 去掉一位，0 本身也有一位。
#include <stdio.h>

int main(void)
{
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    int digits = 1;
    while (number >= 10) {
        number /= 10;
        ++digits;
    }
    printf("%d\n", digits);
    return 0;
}
