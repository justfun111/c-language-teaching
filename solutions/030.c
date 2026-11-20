// 完数：因子 d 和 number / d 成对，平方根只加一次。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

static int is_perfect(int number)  // 定义一个只在本文件使用的完数判断函数。
{  // 开始辅助函数的函数体。
    if (number < 2) {  // 1 没有比自身小的正因子，和更小的数一起排除。
        return 0;  // 用 0 表示 number 不是完数。
    }  // 结束当前条件分支。

    int sum = 1;  // 对大于 1 的数，1 总是一个真因子。
    // 只试到平方根，使用除法判断可以避免乘法溢出。
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {  // 余数为 0 时，divisor 是 number 的因子。
            int paired = number / divisor;  // 通过商找到与 divisor 配对的另一因子。
            sum += divisor;  // 把较小的因子加到真因子和中。
            if (paired != divisor) {  // 只有两个因子不同才需要加第二次。
                sum += paired;  // 把较大的配对因子也加到和中。
            }  // 结束当前条件分支。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    return sum == number;  // 真因子之和等于原数时返回 1，否则返回 0。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int lower, upper;  // lower 和 upper 分别保存范围的下界和上界。
    if (scanf("%d%d", &lower, &upper) != 2) {  // 读取要检查的两个区间端点。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    for (int value = lower; value <= upper; ++value) {  // 从下界逐个枚举到上界，包含两个端点。
        if (is_perfect(value)) {  // 调用辅助函数判断当前整数是不是完数。
            printf("%d\n", value);  // 每发现一个完数就单独输出一行。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
