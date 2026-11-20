// 和最大子序列：用 Kadane 算法维护以当前元素结尾的最大和。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count;  // count 保存序列元素个数。
    long long ending, best;  // ending 记录以当前元素结尾的最大段和，best 记录全局最大段和。
    if (scanf("%d%lld", &count, &ending) != 2 || count < 1) {  // 读取序列长度和第一个元素，保证至少有一项。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    best = ending;  // 只有第一项时，整体最大段和就等于它的值。

    for (int i = 1; i < count; ++i) {  // 从序列的第二项开始更新两个最大值。
        long long value;  // value 保存当前元素。
        if (scanf("%lld", &value) != 1) {  // 读入当前需要处理的数。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        // 前一段的和为负时，直接从当前元素开始。
        // 如果前一段贡献为正，就接到段末，否则从当前值开始新段。
        ending = ending > 0 ? ending + value : value;
        if (ending > best) {  // 检查以当前元素结尾的最优段是否优于全局记录。
            best = ending;  // 用当前段和更新目前找到的最大段和。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    printf("%lld\n", best);  // 输出所有非空连续子序列中的最大和。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
