// 跳一跳：连续跳到中心时，本次加分比上一次多 2。
#include <stdio.h>

int main(void)
{
    int jump, total = 0, center_score = 0;
    while (scanf("%d", &jump) == 1 && jump != 0) {
        if (jump == 2) {
            center_score += 2;
            total += center_score;
        } else {
            center_score = 0;
            ++total;
        }
    }

    printf("%d\n", total);
    return 0;
}
