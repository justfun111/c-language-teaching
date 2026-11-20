// 车牌限行：中度雾霾时，同一天的两个限行尾号模 5 同余。
#include <stdio.h>

int main(void)
{
    int weekday, index, plate;
    if (scanf("%d%d%d", &weekday, &index, &plate) != 3) {
        return 1;
    }

    int last_digit = plate % 10;
    int restricted = 0;
    if (weekday <= 5 && index >= 200) {
        if (index < 400) {
            restricted = last_digit % 5 == weekday % 5;
        } else {
            restricted = last_digit % 2 == weekday % 2;
        }
    }

    printf("%d %s\n", last_digit, restricted ? "yes" : "no");
    return 0;
}
