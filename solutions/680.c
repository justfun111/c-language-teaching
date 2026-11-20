// 函数的最大值：用整数下标枚举网格点，避免累加步长带来的漂移。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    double coefficient;  // coefficient 保存函数中 x² 项的系数。
    if (scanf("%lf", &coefficient) != 1) {  // 用 double 格式读取函数的系数。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    double maximum = 0;  // 端点 x = 0 的函数值为 0，用它初始化最大值。
    for (int step = 1; step <= 100000; ++step) {  // 用整数编号枚举剩余网格点，最后一个编号对应 x = 10。
        double x = step / 10000.0;  // 将整数编号除以 10000 得到采样点，相邻点间距为 0.0001。
        double value = x * x * (coefficient - x);  // 用等价式 x²(a - x) 计算当前点的函数值。
        if (value > maximum) {  // 只有这个采样点的函数值更大时才更新最大值。
            maximum = value;  // 记下目前找到的最大函数值。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    printf("%.2f\n", maximum);  // 输出所有采样点中的最大值，保留两位小数。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
