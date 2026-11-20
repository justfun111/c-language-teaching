// 气温波动：只保存前一天的气温和已经找到的最大差值。
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int days, previous;
    if (scanf("%d%d", &days, &previous) != 2) {
        return 1;
    }

    int maximum = 0;
    for (int i = 1; i < days; ++i) {
        int temperature;
        if (scanf("%d", &temperature) != 1) {
            return 1;
        }
        int change = abs(temperature - previous);
        if (change > maximum) {
            maximum = change;
        }
        previous = temperature;
    }

    printf("%d\n", maximum);
    return 0;
}
