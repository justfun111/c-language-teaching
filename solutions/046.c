// 折点计数：相邻两段趋势方向不同时，中间一天就是折点。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int days, first, previous;  // days 保存天数，first 和 previous 用来建立第一段趋势。
    if (scanf("%d%d%d", &days, &first, &previous) != 3) {  // 读取天数以及头两天的销量。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int turns = 0;  // 折点总数初始为 0。
    int increasing = previous > first;  // 第二天销量比第一天高时记作上升，否则为下降。
    for (int i = 2; i < days; ++i) {  // 从第三天起，每次都能计算新的相邻趋势。
        int current;  // current 保存新一天的销量。
        if (scanf("%d", &current) != 1) {  // 读取当天的一个销量整数。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        int next_increasing = current > previous;  // 把当前这段趋势编码为 1 表示上升，0 表示下降。
        if (increasing != next_increasing) {  // 两段相邻趋势方向不同，说明它们之间有一个折点。
            ++turns;  // 折点总数增加 1。
        }  // 结束当前条件分支。
        increasing = next_increasing;  // 保存当前这段趋势，供下一轮比较。
        previous = current;  // 保存当天销量，让下一轮可计算新的趋势。
    }  // 结束本层 for 循环。

    printf("%d\n", turns);  // 输出统计到的折点总数。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
