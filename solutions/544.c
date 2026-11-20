// 整数拆分：枚举第一部分，剩余部分可以保持原样，也可以继续拆分。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int number;  // number 保存要拆分的正整数。
    // 读入待拆分的数，检查它在 2 至 50 的范围内。
    if (scanf("%d", &number) != 1 || number < 2 || number > 50) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    long long best[51] = {0};  // best[k] 记录把 k 拆成至少两个正整数后的最大乘积。
    for (int total = 2; total <= number; ++total) {  // 按从小到大的顺序计算，使较小的状态可以被复用。
        for (int first = 1; first < total; ++first) {  // 枚举拆出的第一部分，给剩余部分至少留出 1。
            int rest = total - first;  // 从总和中减去第一部分，得到剩余的正整数。
            // 比较剩余部分的最大拆分乘积和保留它本身的值。
            long long best_rest = best[rest] > rest ? best[rest] : rest;
            long long product = first * best_rest;  // 用第一部分乘以剩余部分能提供的最大值。
            if (product > best[total]) {  // 只在候选乘积变大时更新当前总和的答案。
                best[total] = product;  // 记录当前总和下最大的拆分乘积。
            }  // 结束当前条件分支。
        }  // 结束本层 for 循环。
    }  // 结束本层 for 循环。

    printf("%lld\n", best[number]);  // 输出原输入整数对应的最大乘积。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
