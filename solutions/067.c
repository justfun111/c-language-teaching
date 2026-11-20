// 查找：边读边输出匹配的位置，下标从 0 开始。
#include <stdio.h>

int main(void)
{
    int count, target;
    if (scanf("%d%d", &count, &target) != 2) {
        return 1;
    }

    int found = 0;
    for (int i = 0; i < count; ++i) {
        int value;
        if (scanf("%d", &value) != 1) {
            return 1;
        }
        if (value == target) {
            printf("%s%d", found ? " " : "", i);
            found = 1;
        }
    }

    if (!found) {
        printf("-1");
    }
    putchar('\n');
    return 0;
}
