// 序列分段求和：数值变化时开始新段，并继续更新最大段和。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, previous;  // count 保存元素数，previous 保存上一次读到的值。
    if (scanf("%d%d", &count, &previous) != 2 || count < 1) {  // 先读长度和首项，并确保数列非空。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int current_sum = previous, best_sum = previous;  // 第一段目前只有首项，当前段和与最大段和都由它初始化。
    for (int i = 1; i < count; ++i) {  // 从第二项开始判断每个新值属于哪一段。
        int value;  // value 保存本轮读到的元素。
        if (scanf("%d", &value) != 1) {  // 读取下一个整数，检查是否成功。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        // 当前值与前项相等就累加到原段，否则用当前值开启新段。
        current_sum = value == previous ? current_sum + value : value;
        if (current_sum > best_sum) {  // 只有当前段和更大时，才更新最终候选值。
            best_sum = current_sum;  // 记录截至现在遇到的最大段和。
        }  // 结束当前条件分支。
        previous = value;  // 保存当前值，供下一轮判断是否开新段。
    }  // 结束本层 for 循环。

    printf("%d\n", best_sum);  // 输出所有相等值连续段中的最大和。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
