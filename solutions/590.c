// 数字个数统计：两个整除条件恰好成立一个时才计数。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int lower, upper;  // lower 和 upper 用来保存两个区间端点。
    if (scanf("%d%d", &lower, &upper) != 2) {  // 读入用户给出的两个整数，暂时不假设输入顺序。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    if (lower > upper) {  // 当第一个数大于第二个数时，需要交换它们。
        int temporary = lower;  // 先保存第一个值，避免下一步覆盖后丢失。
        lower = upper;  // 把较小的端点放入 lower。
        upper = temporary;  // 把暂存的较大端点放入 upper。
    }  // 结束当前条件分支。

    int count = 0;  // 把满足条件的整数个数初始化为 0。
    for (int number = lower; number <= upper; ++number) {  // 从较小端点逐个检查到较大端点，两端都计入。
        int divisible_by_7 = number % 7 == 0;  // 余数为 0 时，将能被 7 整除的标记设为 1。
        int divisible_by_11 = number % 11 == 0;  // 同样用余数判断当前数能否被 11 整除。
        if (divisible_by_7 != divisible_by_11) {  // 两个标记不相等时，恰好只有其中一个整除条件成立。
            ++count;  // 当前整数满足题意，把计数加 1。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    printf("%d\n", count);  // 输出闭区间内所有符合条件的整数数量。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
