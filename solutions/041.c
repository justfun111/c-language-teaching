// PM2.5：找出读数所在的第一个上限，超出所有上限时归入第六级。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    const int upper_limits[] = {50, 100, 150, 200, 300};  // 依次存放前五个空气质量等级的读数上限。
    int counts[6] = {0};  // 为六个等级各设一个计数器，初始都为 0。
    int days, sum = 0;  // days 保存读数天数，sum 从 0 开始累计读数。
    if (scanf("%d", &days) != 1 || days < 1) {  // 读取天数，并保证后面计算平均值时分母为正。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    for (int i = 0; i < days; ++i) {  // 循环处理每一天的读数。
        int value;  // value 保存当天的 PM2.5 数值。
        if (scanf("%d", &value) != 1) {  // 读取当天的一个整数值。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        int level = 0;  // 从数组下标 0 对应的第一级开始寻找。
        // 当前读数超过本级上限时继续升一级，至多升到第六级。
        while (level < 5 && value > upper_limits[level]) {
            ++level;  // 把等级下标增加 1，再比较下一个上限。
        }  // 结束本层 while 循环。
        ++counts[level];  // 把当天计入找到的空气质量等级。
        sum += value;  // 将当天读数加到总和中。
    }  // 结束本层 for 循环。

    printf("%.2f\n", (double)sum / days);  // 先将总和转换成 double 再除，输出两位小数的平均值。
    printf("%d %d %d %d %d %d\n",  // 第二行需要按照等级顺序输出六个整数。
           // 依次传入从第一级到第六级的统计结果。
           counts[0], counts[1], counts[2], counts[3], counts[4], counts[5]);
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
