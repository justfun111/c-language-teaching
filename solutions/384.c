// 种苹果：疏果量用负数记录，数值越小代表去掉得越多。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int rounds, remaining;  // rounds 保存疏果轮数，remaining 保存当前还有多少个苹果。
    // 读入操作轮数和最初的苹果数，确认至少要处理一轮。
    if (scanf("%d%d", &rounds, &remaining) != 2 || rounds < 1) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int most_removed = 0, best_round = 1;  // 最大疏果量以变化值 0 初始化，默认记录第一轮。
    for (int round = 1; round <= rounds; ++round) {  // 按从 1 开始的轮次顺序，依次读入每轮记录。
        int change;  // change 保存该轮苹果数的变化量。
        if (scanf("%d", &change) != 1) {  // 读取本轮的变化量。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        if (change < most_removed) {  // 变化值越小表示疏果越多，值相同时保留之前的轮次。
            most_removed = change;  // 记下当前最大的疏果量对应的负数变化值。
            best_round = round;  // 同时记录完成这次疏果的轮次。
        }  // 结束当前条件分支。
        remaining += change;  // 把零或负的变化量加到剩余苹果数，得到本轮结束后的数量。
    }  // 结束本层 for 循环。

    printf("%d %d\n", remaining, best_round);  // 输出最后的苹果数和疏果最多的轮次。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
