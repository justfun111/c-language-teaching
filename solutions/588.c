// 阶乘运算：题给公式 m! / (n! (m-n)!) 对应组合数 C(m,n)。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int total, selected;  // total 和 selected 分别是元素总数和选择数。
    // 读取组合数的两个参数，并要求选择数大于 0 且小于总数。
    if (scanf("%d%d", &total, &selected) != 2 || selected < 1 || selected >= total) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    if (selected > total - selected) {  // 根据组合数的对称性，可以选择较小的那一边来减少循环次数。
        selected = total - selected;  // 用选中元素的补集大小代替原选择数。
    }  // 结束当前条件分支。

    int combinations = 1;  // 从只选零个元素的组合数 1 开始递推。
    for (int i = 1; i <= selected; ++i) {  // i 依次表示实际递推到的选择数。
        // 由 C(total, i - 1) 乘 total - i + 1 再除以 i 得到 C(total, i)。
        combinations = combinations * (total - i + 1) / i;
    }  // 结束本层 for 循环。
    printf("%d\n", combinations);  // 输出按题目公式得到的组合数。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
