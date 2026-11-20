// 数列分段：第一个元素以及每一次数值变化，都开始一个新段。
#include <stdio.h>

int main(void)
{
    int count, previous;
    if (scanf("%d%d", &count, &previous) != 2 || count < 1) {
        return 1;
    }

    int segments = 1;
    for (int i = 1; i < count; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }
        if (value != previous) {
            ++segments;
        }
        previous = value;
    }

    printf("%d\n", segments);
    return 0;
}
