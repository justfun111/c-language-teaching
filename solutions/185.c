// 迭代法求根：用牛顿迭代计算非负实数的平方根。
#include <math.h>
#include <stdio.h>

int main(void)
{
    double value;
    if (scanf("%lf", &value) != 1 || !isfinite(value) || value < 0) {
        return 1;
    }
    if (value == 0) {
        puts("0.00000");
        return 0;
    }

    double root = value > 1 ? value : 1;
    for (;;) {
        double next = root / 2 + (value / root) / 2;
        double change = root - next;
        root = next;
        // 相对阈值防止很小的输入过早停止。舍入后不再下降时已经收敛。
        if (change <= 0 || (change < 1e-5 && change <= 1e-12 * root)) {
            break;
        }
    }

    printf("%.5f\n", root);
    return 0;
}
