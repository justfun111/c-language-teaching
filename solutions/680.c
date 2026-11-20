// 函数的最大值：用整数下标枚举网格点，避免累加步长带来的漂移。
#include <stdio.h>

int main(void)
{
    double coefficient;
    if (scanf("%lf", &coefficient) != 1) {
        return 1;
    }

    double maximum = 0;
    for (int step = 1; step <= 100000; ++step) {
        double x = step / 10000.0;
        double value = x * x * (coefficient - x);
        if (value > maximum) {
            maximum = value;
        }
    }
    printf("%.2f\n", maximum);
    return 0;
}
