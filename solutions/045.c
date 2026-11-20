// 气温波动：只保存前一天的气温和已经找到的最大差值。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。
#include <stdlib.h>  // 引入 abs() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int days, previous;  // days 保存气温记录天数，previous 保存前一天的气温。
    if (scanf("%d%d", &days, &previous) != 2) {  // 同时读取天数和第一天的气温。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int maximum = 0;  // 最大波动从 0 开始累计比较。
    for (int i = 1; i < days; ++i) {  // 从下标 1 对应的第二天开始逐天比较。
        int temperature;  // temperature 保存当天的气温。
        if (scanf("%d", &temperature) != 1) {  // 读取当天的一个气温整数。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        int change = abs(temperature - previous);  // 对相邻两天的温差取绝对值，上升和下降都算波动。
        if (change > maximum) {  // 只有本次波动比已记录的最大值大时才更新。
            maximum = change;  // 记录更大的气温波动。
        }  // 结束当前条件分支。
        previous = temperature;  // 把当天气温作为下一轮比较时的前一天气温。
    }  // 结束本层 for 循环。

    printf("%d\n", maximum);  // 输出所有相邻天中最大的气温波动。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
