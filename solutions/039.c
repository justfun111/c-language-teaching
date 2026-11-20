// 寻找马鞍点：只需在每行的最小值中检查所在列的最大值。
#include <stdio.h>  // 引入 scanf()、printf()、puts() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int rows, columns;  // rows 和 columns 分别保存矩阵的行数和列数。
    if (scanf("%d%d", &rows, &columns) != 2 ||  // 尝试读取两个尺寸，读取失败时进入错误分支。
        // 同时确认两个尺寸都处在 1 至 99 的允许范围内。
        rows < 1 || rows > 99 || columns < 1 || columns > 99) {
        return 1;  // 当前条件无法继续处理，返回非零退出状态。
    }  // 结束当前条件分支。

    // 分别记录每行的最小值及其列下标，以及每列的最大值。
    int row_minimum[99], minimum_column[99], column_maximum[99];
    for (int row = 0; row < rows; ++row) {  // 按输入次序逐行读矩阵。
        for (int column = 0; column < columns; ++column) {  // 依次处理当前行的每一列。
            int value;  // value 保存当前读到的矩阵元素。
            if (scanf("%d", &value) != 1) {  // 读入当前位置的整数。
                return 1;  // 输入读取或检查失败，返回非零退出状态。
            }  // 结束当前条件分支。
            if (column == 0 || value < row_minimum[row]) {  // 每行的首项初始化行最小值，遇到更小的数时更新。
                row_minimum[row] = value;  // 记下目前找到的这一行最小值。
                minimum_column[row] = column;  // 同时记下这个最小值所在的列下标。
            }  // 结束当前条件分支。
            // 每列的首项初始化列最大值，遇到更大的数时更新。
            if (row == 0 || value > column_maximum[column]) {
                column_maximum[column] = value;  // 记录这一列新的最大值。
            }  // 结束当前条件分支。
        }  // 结束本层 for 循环。
    }  // 结束本层 for 循环。

    for (int row = 0; row < rows; ++row) {  // 每行只需检查该行的最小元素。
        int column = minimum_column[row];  // 取出当前行最小元素所在的列下标。
        if (row_minimum[row] == column_maximum[column]) {  // 行最小元素也是所在列的最大值时，它就是马鞍点。
            printf("%d %d %d\n", row, column, row_minimum[row]);  // 输出从 0 开始的行号、列号和元素值。
            return 0;  // 找到马鞍点并完成输出后正常结束。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    puts("no");  // 检查完所有行仍没找到时，输出 no。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
