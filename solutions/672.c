// 计算正弦函数：用相邻项的比值递推，避免单独计算大阶乘。
#include <stdio.h>

int main(void)
{
    int terms;
    double x;
    if (scanf("%d%lf", &terms, &x) != 2 || terms < 1) {
        return 1;
    }

    double term = x, sum = x;
    for (int i = 1; i < terms; ++i) {
        term *= -(x * x) / ((2.0 * i) * (2.0 * i + 1));
        sum += term;
    }
    printf("%.4f\n", sum);
    return 0;
}
