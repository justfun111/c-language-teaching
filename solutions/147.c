// 奇数求和：余数非零即可判断奇数，负奇数同样适用。
#include <stdio.h>

int main(void)
{
    long long value, sum = 0;
    while (scanf("%lld", &value) == 1 && value != 0) {
        if (value % 2 != 0) {
            sum += value;
        }
    }

    printf("%lld\n", sum);
    return 0;
}
