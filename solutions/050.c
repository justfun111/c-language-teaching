// 选号程序：先比较各位数字和，分数相同再比较号码。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

static int digit_sum(int number)  // 定义辅助函数，计算一个号码的各位数字之和。
{  // 开始辅助函数的函数体。
    int sum = 0;  // 数字之和从 0 开始累计。
    while (number > 0) {  // 只要还有数字没有拆出就继续循环。
        sum += number % 10;  // 对 10 取余得到当前末位，并把它加到和中。
        number /= 10;  // 整除 10 去掉已经处理过的末位。
    }  // 结束本层 while 循环。
    return sum;  // 返回这个号码的各位数字之和。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    // 记录候选数量和当前最佳结果，初始分数 -1 保证首个号码能入选。
    int count, best_number = 0, best_sum = -1;
    if (scanf("%d", &count) != 1 || count < 1) {  // 读取候选数量，并确认至少有一个号码可选。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    for (int i = 0; i < count; ++i) {  // 逐个处理候选号码。
        int number;  // number 保存当前候选号码。
        if (scanf("%d", &number) != 1) {  // 读取一个号码，检查是否成功。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        int sum = digit_sum(number);  // 计算当前号码的各位数字之和。
        // 数字和更大时胜出，数字和相同则选数值更大的号码。
        if (sum > best_sum || (sum == best_sum && number > best_number)) {
            best_number = number;  // 把当前号码记录为最佳号码。
            best_sum = sum;  // 同步记录它的数字和，供后续号码比较。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    printf("%d\n", best_number);  // 输出排名第一的号码。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
