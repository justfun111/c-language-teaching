// 质数求和：按从小到大的顺序找到并编号，只累加指定的 11 项。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

static int is_prime(int number)  // 定义素数判断函数，供主循环逐个检验候选数。
{  // 开始辅助函数的函数体。
    // 从 2 开始试除，整除比较写法能避免平方溢出。
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {  // 检查当前试除数能否整除候选数。
            return 0;  // 找到一个非平凡因子，返回 0 表示不是素数。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    return number >= 2;  // 未找到因子时，仍然需要排除小于 2 的整数。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int first;  // first 保存第一个要计入总和的素数序号。
    if (scanf("%d", &first) != 1 || first < 1) {  // 读入起始序号，并要求它为正数。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int index = 0, sum = 0;  // index 记录已找到多少个素数，sum 累加所需的素数值。
    for (int number = 2; index < first + 10; ++number) {  // 从 2 往上枚举，找到序号 first + 10 的素数后结束。
        if (is_prime(number)) {  // 只有当前候选数是素数时才进入计数。
            ++index;  // 为新找到的素数分配下一个序号。
            if (index >= first) {  // 跳过起始序号之前找到的素数。
                sum += number;  // 把区间内的这个素数计入总和。
            }  // 结束当前条件分支。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    printf("%d\n", sum);  // 输出从第 first 个到第 first + 10 个素数的总和。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
