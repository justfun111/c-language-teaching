// 区间整数平方和：两个端点都参与求和。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int lower, upper;  // lower 和 upper 保存闭区间的两个端点。
    if (scanf("%d%d", &lower, &upper) != 2) {  // 通过标准输入读取区间的下界和上界。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int sum = 0;  // 平方和从 0 开始累计。
    for (int value = lower; value <= upper; ++value) {  // 从下界逐个取整数，处理到上界为止。
        sum += value * value;  // 用当前整数乘以自身，再将平方加入总和。
    }  // 结束本层 for 循环。
    printf("%d\n", sum);  // 输出闭区间内各个整数的平方和。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
