// 整除判断
#include <stdio.h>

int main(void)
{
    int dividend, divisor;
    if (scanf("%d%d", &dividend, &divisor) != 2 || divisor == 0) {
        return 1;
    }

    int remainder = dividend % divisor;
    if (remainder == 0) {
        puts("yes");
    } else {
        printf("%d %d\n", dividend / divisor, remainder);
    }
    return 0;
}
