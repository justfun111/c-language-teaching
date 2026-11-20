// 数字个数统计：每个条件独立统计，同一个数字可以计入多项。
#include <stdio.h>

int main(void)
{
    int count, even = 0, multiple_of_3 = 0, not_multiple_of_7 = 0, sum = 0;
    if (scanf("%d", &count) != 1 || count < 1) {
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }
        even += value % 2 == 0;
        multiple_of_3 += value % 3 == 0;
        not_multiple_of_7 += value % 7 != 0;
        sum += value;
    }

    printf("%d %d %d %d %.2f\n",
           even, count - even, multiple_of_3, not_multiple_of_7, (double)sum / count);
    return 0;
}
