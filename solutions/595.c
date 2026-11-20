// Fibonacci 数列：第 100 项超出 64 位整数范围，用十进制数组逐位相加。
#include <stdio.h>  // 引入 scanf()、printf()、putchar() 的声明。

enum { DIGITS = 24 };  // 每个数用 24 个十进制数位保存，足以容纳题目范围内的项。

static void add_digits(int result[], const int addend[])  // 定义逐位加法函数，把 addend 加到 result 中。
{  // 开始辅助函数的函数体。
    int carry = 0;  // 个位没有来自更低位的进位，初始进位为 0。
    for (int i = 0; i < DIGITS; ++i) {  // 由个位起依次处理数组中的每一个数位。
        int sum = result[i] + addend[i] + carry;  // 将两个数在当前位的数字与上一位的进位相加。
        result[i] = sum % 10;  // 将个位数字写回结果的当前位。
        carry = sum / 10;  // 除以 10 得到传给下一位的进位。
    }  // 结束本层 for 循环。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int index;  // index 保存用户指定的数列下标。
    if (scanf("%d", &index) != 1 || index < 0 || index > 100) {  // 读入下标并检查它在 0 至 100 的范围内。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int first[DIGITS] = {7};  // 数列第 0 项为 7，数组从个位开始保存。
    int second[DIGITS] = {1, 1};  // 数组前两位都为 1，表示数列第 1 项 11。
    int *current = first;  // current 起初指向第 0 项，用来保存迭代的当前项。
    int *next = second;  // next 起初指向第 1 项，始终比 current 多向前一项。
    for (int i = 0; i < index; ++i) {  // 每轮让一对相邻数列项前进一项，直到抵达目标下标。
        add_digits(current, next);  // 把旧的当前项更新为它与下一项之和。
        int *temporary = current;  // 暂存已经存入新和的缓冲区地址。
        current = next;  // 让旧的下一项成为新的当前项。
        next = temporary;  // 把保存新和的缓冲区用作新的下一项。
    }  // 结束本层 for 循环。

    int highest = DIGITS - 1;  // 从数组最高下标开始寻找第一个有效数位。
    while (highest > 0 && current[highest] == 0) {  // 只要高位是 0 且还没到个位，就继续往低位找。
        --highest;  // 跳过一个前导零。
    }  // 结束本层 while 循环。
    printf("%d ", index);  // 先输出题目要求的数列下标，再输出分隔空格。
    for (int i = highest; i >= 0; --i) {  // 从最高有效位倒序遍历到个位，按自然阅读顺序输出。
        putchar('0' + current[i]);  // 将当前数字转换成对应的十进制字符。
    }  // 结束本层 for 循环。
    putchar('\n');  // 整个数列项输出完后换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
