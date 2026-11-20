// 计算某月天数：整百年份只有能被 400 整除时才是闰年。
#include <stdio.h>

int main(void)
{
    const int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month;
    if (scanf("%d%d", &year, &month) != 2 || month < 1 || month > 12) {
        return 1;
    }

    int days = days_per_month[month - 1];
    int leap_year = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    if (month == 2 && leap_year) {
        ++days;
    }

    printf("%d\n", days);
    return 0;
}
