// 数列分段：第一个元素以及每一次数值变化，都开始一个新段。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, previous;  // count 保存元素个数，previous 保存上一个元素。
    if (scanf("%d%d", &count, &previous) != 2 || count < 1) {  // 读取元素个数和首项，确认数列至少有一项。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int segments = 1;  // 首项本身就开始了第一段。
    for (int i = 1; i < count; ++i) {  // 下标从 1 开始，继续处理首项之后的元素。
        int value;  // value 保存当前读到的数。
        if (scanf("%d", &value) != 1) {  // 读取当前元素，检查是否成功读到一个整数。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        if (value != previous) {  // 当前值与前一个值不同时，开始新的一段。
            ++segments;  // 把新发现的一段计入总段数。
        }  // 结束当前条件分支。
        previous = value;  // 把当前值留给下一轮作比较。
    }  // 结束本层 for 循环。

    printf("%d\n", segments);  // 输出总段数并换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
