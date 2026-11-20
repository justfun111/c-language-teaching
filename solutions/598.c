// 数字个数统计：每个条件独立统计，同一个数字可以计入多项。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    // 保存输入数量、三类计数和总和，计数器与累加器从 0 开始。
    int count, even = 0, multiple_of_3 = 0, not_multiple_of_7 = 0, sum = 0;
    if (scanf("%d", &count) != 1 || count < 1) {  // 读取整数的个数，要求平均值计算时分母为正。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    for (int i = 0; i < count; ++i) {  // 按顺序处理输入的每一个数。
        int value;  // value 保存当前处理的整数。
        if (scanf("%d", &value) != 1) {  // 读取当前位置的数值。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        even += value % 2 == 0;  // 能被 2 整除时加 1，否则加 0。
        multiple_of_3 += value % 3 == 0;  // 能被 3 整除时，为 3 的倍数计数加 1。
        not_multiple_of_7 += value % 7 != 0;  // 除以 7 有余数时，为不能被 7 整除的计数加 1。
        sum += value;  // 将当前值累加，用于最后计算平均值。
    }  // 结束本层 for 循环。

    printf("%d %d %d %d %.2f\n",  // 四类计数用整数格式输出，平均值保留两位小数。
           // 奇数个数用总数减偶数个数，平均值先转成 double 再做除法。
           even, count - even, multiple_of_3, not_multiple_of_7, (double)sum / count);
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
