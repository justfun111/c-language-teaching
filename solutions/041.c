// PM2.5：找出读数所在的第一个上限，超出所有上限时归入第六级。
#include <stdio.h>

int main(void)
{
    const int upper_limits[] = {50, 100, 150, 200, 300};
    int counts[6] = {0};
    int days, sum = 0;
    if (scanf("%d", &days) != 1 || days < 1) {
        return 1;
    }

    for (int i = 0; i < days; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }
        int level = 0;
        while (level < 5 && value > upper_limits[level]) {
            ++level;
        }
        ++counts[level];
        sum += value;
    }

    printf("%.2f\n", (double)sum / days);
    printf("%d %d %d %d %d %d\n",
           counts[0], counts[1], counts[2], counts[3], counts[4], counts[5]);
    return 0;
}
