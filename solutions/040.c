// 等差数列：升序排列后，检查相邻元素的差是否相同。
#include <stdio.h>  // 引入 scanf()、printf()、puts() 的声明。
#include <stdlib.h>  // 引入 qsort() 的声明。

static int compare_int(const void *left, const void *right)  // 定义 qsort 的整数升序比较函数。
{  // 开始辅助函数的函数体。
    int a = *(const int *)left;  // 从左侧指针取出待比较的整数。
    int b = *(const int *)right;  // 从右侧指针取出另一个整数。
    return (a > b) - (a < b);  // 左值较小时返回 -1，较大时返回 1，相等返回 0。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, values[99];  // count 保存数列长度，values 最多存放 99 个整数。
    // 读取长度并确保至少有一项，且不超过数组容量。
    if (scanf("%d", &count) != 1 || count < 1 || count > 99) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    for (int i = 0; i < count; ++i) {  // 逐个遍历数组的有效位置。
        if (scanf("%d", &values[i]) != 1) {  // 读取一个整数并存入当前位置。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    // 先升序排列数列，让相邻项的公差以非负值表示。
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    // 单元素数列约定公差为 0，否则用前两个元素的差作公差。
    int difference = count == 1 ? 0 : values[1] - values[0];
    for (int i = 2; i < count; ++i) {  // 从第三项开始验证剩余的每组相邻元素。
        if (values[i] - values[i - 1] != difference) {  // 任意一对的差与预期公差不相等，就无法重组。
            puts("no");  // 按要求输出 no。
            return 0;  // 已得到无解的有效结果，正常结束程序。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    printf("%d\n", difference);  // 所有相邻差相等时，输出公差。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
