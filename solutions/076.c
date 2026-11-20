// 统计正整数的个数：排序后，相同的数字连续出现。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。
#include <stdlib.h>  // 引入 qsort() 的声明。

static int compare_int(const void *left, const void *right)  // 定义整数升序比较函数，供 qsort 使用。
{  // 开始辅助函数的函数体。
    int a = *(const int *)left;  // 把左侧元素地址转成整数指针，再取出元素值。
    int b = *(const int *)right;  // 通过右侧元素地址取出另一个整数值。
    return (a > b) - (a < b);  // 用两个比较的差表示顺序，避免直接对输入整数相减。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, values[29];  // count 保存输入数量，values 最多能存放 29 个数。
    if (scanf("%d", &count) != 1 || count < 1 || count > 29) {  // 读取数量并检查数组容量。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    for (int i = 0; i < count; ++i) {  // 依次访问数组的每个有效下标。
        if (scanf("%d", &values[i]) != 1) {  // 把读到的整数保存到当前下标。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    qsort(values, (size_t)count, sizeof values[0], compare_int);  // 升序排序，使相等的元素排在一起。

    for (int start = 0; start < count;) {  // start 指向下一组的第一项，每次循环处理一组相同值。
        int end = start + 1;  // 这一组至少包含首项，所以 end 从首项之后开始查找。
        // 后续值和组首相同且下标有效时，继续扩展当前组。
        while (end < count && values[end] == values[start]) {
            ++end;  // 将组的右边界向后移一个位置。
        }  // 结束本层 while 循环。
        printf("%d:%d\n", values[start], end - start);  // 右边界本身不属于组，所以 end - start 就是出现次数。
        start = end;  // 从右边界开始处理下一组不同的整数。
    }  // 结束本层 for 循环。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
