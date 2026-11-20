// 迭代法求根：用牛顿迭代计算非负实数的平方根。
#include <math.h>  // 引入 isfinite() 的声明。
#include <stdio.h>  // 引入 scanf()、printf()、puts() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    double value;  // value 保存要开平方的实数。
    if (scanf("%lf", &value) != 1 || !isfinite(value) || value < 0) {  // 确保读取到的是有限的非负实数。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    if (value == 0) {  // 单独处理 0，因为从 0 开始迭代会导致除以 0。
        puts("0.00000");  // 0 的平方根是 0，按五位小数格式输出。
        return 0;  // 已完成 0 的处理，直接正常退出。
    }  // 结束当前条件分支。

    double root = value > 1 ? value : 1;  // 取原数和 1 中较大的作为初值，使它在真实平方根的上方或恰好相等。
    for (;;) {  // 反复迭代，由循环内部的收敛条件决定何时结束。
        // 按牛顿公式求当前估计和 value / root 的平均值，分别除以 2 后相加。
        double next = root / 2 + (value / root) / 2;
        double change = root - next;  // 记录本次估计比上次下降的幅度。
        root = next;  // 让新估计成为下一次迭代的起点。
        // 相对阈值防止很小的输入过早停止。舍入后不再下降时已经收敛。
        // 舍入后估计不再下降，或变化量同时满足绝对和相对阈值时停止。
        if (change <= 0 || (change < 1e-5 && change <= 1e-12 * root)) {
            break;  // 达到停止条件，跳出迭代循环。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    printf("%.5f\n", root);  // 将平方根近似值输出到小数点后五位。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
