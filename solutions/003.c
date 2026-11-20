// 最小差值：排序后只需检查相邻元素。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。
#include <stdlib.h>  // 引入 qsort() 的声明。

// 定义 qsort 的升序比较函数，参数是两个元素的地址。
static int compare_int(const void *left, const void *right)
{  // 开始辅助函数的函数体。
    int a = *(const int *)left;  // 将左侧地址转成整数指针，再取出左侧的值。
    int b = *(const int *)right;  // 用同样的方法取出右侧的值。
    return (a > b) - (a < b);  // 左值较大返回 1，较小返回 -1，相等返回 0，避免直接相减。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, values[1000];  // count 保存元素个数，values 最多存放一千个整数。
    // 读取个数并确认有足够的元素作比较，且数组容量足够。
    if (scanf("%d", &count) != 1 || count < 2 || count > 1000) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    for (int i = 0; i < count; ++i) {  // 依次遍历所有待填的数组下标。
        if (scanf("%d", &values[i]) != 1) {  // 直接把一个整数读入下标 i 对应的位置。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    // 用每个元素的大小和升序规则对整个数组排序。
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    int minimum = values[1] - values[0];  // 先用排序后第一对相邻元素的差初始化最小值。
    for (int i = 2; i < count; ++i) {  // 从第三项开始检查剩余的相邻元素对。
        int difference = values[i] - values[i - 1];  // 用当前项减前一项，升序保证差值非负。
        if (difference < minimum) {  // 只在发现更小的差值时更新答案。
            minimum = difference;  // 记录新的最小差值。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    printf("%d\n", minimum);  // 输出找到的最小差值。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
