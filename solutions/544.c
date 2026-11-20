// 整数拆分：枚举第一部分，剩余部分可以保持原样，也可以继续拆分。
#include <stdio.h>

int main(void)
{
    int number;
    if (scanf("%d", &number) != 1 || number < 2 || number > 50) {
        return 1;
    }

    long long best[51] = {0};
    for (int total = 2; total <= number; ++total) {
        for (int first = 1; first < total; ++first) {
            int rest = total - first;
            long long best_rest = best[rest] > rest ? best[rest] : rest;
            long long product = first * best_rest;
            if (product > best[total]) {
                best[total] = product;
            }
        }
    }

    printf("%lld\n", best[number]);
    return 0;
}
