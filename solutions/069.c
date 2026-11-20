// 0-1 矩阵：遇到 0 时清空当前连续长度。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int rows, columns;  // rows 和 columns 分别保存行数和列数。
    if (scanf("%d%d", &rows, &columns) != 2) {  // 先读取矩阵的两个尺寸。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    for (int row = 0; row < rows; ++row) {  // 每一行独立寻找最长的连续 1。
        // 当前连续长度和最大长度都从 0 开始，无结果时末尾下标为 -1。
        int length = 0, best_length = 0, best_end = -1;
        for (int column = 0; column < columns; ++column) {  // 从左到右扫描这一行的列。
            int value;  // value 保存当前读到的 0 或 1。
            if (scanf("%d", &value) != 1) {  // 读取当前格子的整数值。
                return 1;  // 输入读取或检查失败，返回非零退出状态。
            }  // 结束当前条件分支。
            length = value == 1 ? length + 1 : 0;  // 遇到 1 时延长当前序列，遇到 0 时将长度清零。
            if (length > best_length) {  // 只有当前序列严格变长并超过纪录时才更新结果。
                best_length = length;  // 记录最新的最长连续长度。
                best_end = column;  // 当前列就是这段最长序列的末尾。
            }  // 结束当前条件分支。
        }  // 结束本层 for 循环。

        // 用结束下标减去长度再加 1 得到起点，无连续 1 时用 -1。
        int best_start = best_length == 0 ? -1 : best_end - best_length + 1;
        printf("%d %d\n", best_start, best_end);  // 在同一行输出这一行的起点和终点下标。
    }  // 结束本层 for 循环。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
