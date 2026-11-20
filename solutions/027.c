// 阶梯电价计费：超出档位的电量才使用更高的单价。
#include <stdio.h>

int main(void)
{
    double usage, bill;
    if (scanf("%lf", &usage) != 1) {
        return 1;
    }

    if (usage <= 110) {
        bill = usage * 0.50;
    } else if (usage <= 210) {
        bill = 110 * 0.50 + (usage - 110) * 0.55;
    } else {
        bill = 110 * 0.50 + 100 * 0.55 + (usage - 210) * 0.70;
    }

    printf("%.2f\n", bill);
    return 0;
}
