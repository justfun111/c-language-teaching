// 歌德巴赫猜想：从最小候选素数开始枚举。
#include <stdio.h>

static int is_prime(int number)
{
    if (number < 2) {
        return 0;
    }
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int number;
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    for (int first = 2; first <= number / 2; ++first) {
        int second = number - first;
        if (is_prime(first) && is_prime(second)) {
            printf("%d %d\n", first, second);
            break;
        }
    }
    return 0;
}
