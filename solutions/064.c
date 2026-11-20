// 自然数分解：这 n 个奇数的平均值为 n²，首项为 n² - (n - 1)。
#include <stdio.h>

int main(void)
{
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    int first = number * (number - 1) + 1;
    for (int i = 0; i < number; ++i) {
        printf("%s%d", i == 0 ? "" : " ", first + 2 * i);
    }
    putchar('\n');
    return 0;
}
