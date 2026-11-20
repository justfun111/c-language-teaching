// 计算某月天数：整百年份只有能被 400 整除时才是闰年。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    // 按月份顺序列出平年每个月的天数。
    const int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month;  // year 和 month 分别保存年份和月份。
    // 读取年份和月份，并确保月份能映射到有效数组下标。
    if (scanf("%d%d", &year, &month) != 2 || month < 1 || month > 12) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int days = days_per_month[month - 1];  // 月份从 1 开始，数组从 0 开始，因此下标要减 1。
    // 能被 400 整除，或能被 4 整除但不能被 100 整除，就是闰年。
    int leap_year = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    if (month == 2 && leap_year) {  // 只有闰年的二月需要修正常规天数。
        ++days;  // 把二月的天数从 28 增加到 29。
    }  // 结束当前条件分支。

    printf("%d\n", days);  // 输出查到并修正后的天数。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
