// 折点计数：相邻两段趋势方向不同时，中间一天就是折点。
#include <stdio.h>

int main(void)
{
    int days, first, previous;
    if (scanf("%d%d%d", &days, &first, &previous) != 3) {
        return 1;
    }

    int turns = 0;
    int increasing = previous > first;
    for (int i = 2; i < days; ++i) {
        int current;
        if (scanf("%d", &current) != 1) {
            return 1;
        }
        int next_increasing = current > previous;
        if (increasing != next_increasing) {
            ++turns;
        }
        increasing = next_increasing;
        previous = current;
    }

    printf("%d\n", turns);
    return 0;
}
