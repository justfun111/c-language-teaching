// 阶乘运算：题给公式 m! / (n! (m-n)!) 对应组合数 C(m,n)。
#include <stdio.h>

int main(void)
{
    int total, selected;
    if (scanf("%d%d", &total, &selected) != 2 || selected < 1 || selected >= total) {
        return 1;
    }
    if (selected > total - selected) {
        selected = total - selected;
    }

    int combinations = 1;
    for (int i = 1; i <= selected; ++i) {
        combinations = combinations * (total - i + 1) / i;
    }
    printf("%d\n", combinations);
    return 0;
}
