// 歌德巴赫猜想：从最小候选素数开始枚举。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

static int is_prime(int number)  // 定义一个只在本文件使用的素数判断函数。
{  // 开始辅助函数的函数体。
    if (number < 2) {  // 排除小于 2 的整数，因为素数从 2 开始。
        return 0;  // 返回 0 表示该整数不是素数。
    }  // 结束当前条件分支。
    // 从 2 试除到平方根即可，更大的因子会与较小因子配对。
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {  // 试除的余数为 0，表示找到了一个非平凡因子。
            return 0;  // 找到一个这样的因子就可以判定为合数。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    return 1;  // 没找到任何因子，返回 1 表示是素数。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int number;  // number 保存要分解的偶数。
    if (scanf("%d", &number) != 1) {  // 读入题目要求分解的一个整数。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    // 从最小候选数 2 枚举到一半，保证较小的素数先被尝试。
    for (int first = 2; first <= number / 2; ++first) {
        int second = number - first;  // 用原数减去第一个候选数，就得到第二个候选数。
        if (is_prime(first) && is_prime(second)) {  // 两个候选数都必须通过素数判断。
            printf("%d %d\n", first, second);  // 按先小后大的顺序输出这一组素数。
            break;  // 找到的第一组两数差距最大，直接结束枚举。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
