// 矩阵元素求和并排序：读入时一次累加行、列和符合条件的对角线。
#include <stdio.h>  // 引入 scanf()、printf()、putchar() 的声明。
#include <stdlib.h>  // 引入 qsort() 的声明。

static int compare_descending(const void *left, const void *right)  // 定义 qsort 的降序比较函数。
{  // 开始辅助函数的函数体。
    long long a = *(const long long *)left;  // 将左侧无类型地址转成 long long 指针并取值。
    long long b = *(const long long *)right;  // 通过右侧地址取得另一个 long long 值。
    return (a < b) - (a > b);  // 左值较大时返回 -1，令较大的数排在前面。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int size;  // size 保存方阵的边长。
    if (scanf("%d", &size) != 1 || size < 3 || size > 19) {  // 读取边长，并限制在题目允许的 3 至 19。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    long long sums[40] = {0};  // 前 size 项放行和，随后 size 项放列和，最后两项放对角线和。
    for (int row = 0; row < size; ++row) {  // 外层循环逐行处理矩阵。
        for (int column = 0; column < size; ++column) {  // 内层循环逐列处理当前行。
            int value;  // value 保存当前位置的矩阵元素。
            if (scanf("%d", &value) != 1) {  // 读取当前行当前列的值。
                return 1;  // 输入读取或检查失败，返回非零退出状态。
            }  // 结束当前条件分支。
            sums[row] += value;  // 将元素计入所在行的总和。
            sums[size + column] += value;  // 列和从下标 size 开始，将元素加到对应列。
            if (row == column) {  // 行列下标相等的位置在主对角线上。
                sums[2 * size] += value;  // 把元素加到主对角线的和。
            }  // 结束当前条件分支。
            if (row + column == size - 1) {  // 行列下标之和为 size - 1 的位置在副对角线上。
                sums[2 * size + 1] += value;  // 把元素加到副对角线的和。
            }  // 结束当前条件分支。
        }  // 结束本层 for 循环。
    }  // 结束本层 for 循环。

    int count = 2 * size + 2;  // 共有 size 个行和、size 个列和与两个对角线和。
    // 用自定义比较规则把所有和按从大到小排列。
    qsort(sums, (size_t)count, sizeof sums[0], compare_descending);
    for (int i = 0; i < count; ++i) {  // 从数组头到尾遍历排好序的和。
        printf("%lld ", sums[i]);  // 输出当前的和，按题目要求在后面加空格。
    }  // 结束本层 for 循环。
    putchar('\n');  // 输出所有结果后换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
