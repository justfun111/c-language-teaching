// 回文数整除问题：选出前三位 a、b、c，再构造 abcba。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int divisor;  // divisor 保存要检查的除数。
    if (scanf("%d", &divisor) != 1 || divisor < 2) {  // 读入除数，要求它至少为 2。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int count = 0;  // 符合条件的回文数有多少个，从 0 开始统计。
    for (int prefix = 100; prefix <= 999; ++prefix) {  // 遍历 100 到 999，枚举五位回文数的前三位。
        int first = prefix / 100;  // 前缀的百位就是回文数的第一位。
        int second = prefix / 10 % 10;  // 先除以 10 再取余，提取前缀的十位。
        int palindrome = prefix * 100 + second * 10 + first;  // 前缀乘以 100 后，把前两位按相反顺序补在末尾。
        if (palindrome % divisor == 0) {  // 检查生成的五位回文数是否能被给定的除数整除。
            ++count;  // 若整除，就给符合条件的回文数计数加 1。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    printf("%d %d\n", divisor, count);  // 输出给定除数和符合条件的回文数个数。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
