// 序列分段求和：数值变化时开始新段，并继续更新最大段和。
#include <stdio.h>

int main(void)
{
    int count, previous;
    if (scanf("%d%d", &count, &previous) != 2 || count < 1) {
        return 1;
    }

    int current_sum = previous, best_sum = previous;
    for (int i = 1; i < count; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }
        current_sum = value == previous ? current_sum + value : value;
        if (current_sum > best_sum) {
            best_sum = current_sum;
        }
        previous = value;
    }

    printf("%d\n", best_sum);
    return 0;
}
