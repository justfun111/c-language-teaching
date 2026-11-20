// 种苹果：疏果量用负数记录，数值越小代表去掉得越多。
#include <stdio.h>

int main(void)
{
    int rounds, remaining;
    if (scanf("%d%d", &rounds, &remaining) != 2 || rounds < 1) {
        return 1;
    }

    int most_removed = 0, best_round = 1;
    for (int round = 1; round <= rounds; ++round) {
        int change;
        if (scanf("%d", &change) != 1) {
            return 1;
        }
        if (change < most_removed) {
            most_removed = change;
            best_round = round;
        }
        remaining += change;
    }

    printf("%d %d\n", remaining, best_round);
    return 0;
}
