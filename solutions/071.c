// 相邻区域：每条共边只需向右、向下各检查一次，用数组去重。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

// 定义辅助函数，用两个共边格子的编号标记目标区域的邻居。
static void mark_neighbor(int first, int second, int target, int adjacent[])
{  // 开始辅助函数的函数体。
    if (first == target && second != target) {  // 左侧或上方格子属于目标区域，且另一格属于不同区域。
        adjacent[second] = 1;  // 用另一个格子的区域编号作下标，把其邻接状态设为 1。
    } else if (second == target && first != target) {  // 如果目标区域在第二个格子，就反过来检查第一个格子。
        adjacent[first] = 1;  // 把第一个格子的区域标记为相邻，重复标记仍是 1。
    }  // 结束当前条件分支。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int rows, columns, regions, target;  // 保存矩阵行列数、区域总数和要查找的区域编号。
    if (scanf("%d%d%d%d", &rows, &columns, &regions, &target) != 4 ||  // 读取需要的四个整数，判断是否读全。
        rows < 1 || rows > 19 || columns < 1 || columns > 19 ||  // 检查行数和列数是否都在 1 至 19。
        regions < 1 || regions > 49) {  // 检查区域个数是否在 1 至 49。
        return 1;  // 当前条件无法继续处理，返回非零退出状态。
    }  // 结束当前条件分支。

    int grid[19][19], adjacent[50] = {0};  // grid 存每格的区域编号，adjacent 按编号保存是否相邻。
    for (int row = 0; row < rows; ++row) {  // 依次读入各行的区域编号。
        for (int column = 0; column < columns; ++column) {  // 按列处理当前行中的各个格子。
            if (scanf("%d", &grid[row][column]) != 1 ||  // 把读到的区域编号写入当前格子。
                // 区域编号必须在 1 到区域总数之间，才能安全作下标。
                grid[row][column] < 1 || grid[row][column] > regions) {
                return 1;  // 当前条件无法继续处理，返回非零退出状态。
            }  // 结束当前条件分支。
        }  // 结束本层 for 循环。
    }  // 结束本层 for 循环。

    for (int row = 0; row < rows; ++row) {  // 矩阵全部读入后，再逐行检查每条共边。
        for (int column = 0; column < columns; ++column) {  // 依次访问当前行的每个格子。
            int current = grid[row][column];  // 取出当前格子所属的区域编号。
            if (column + 1 < columns) {  // 当前格子右边还有一列时，才能访问右邻格。
                // 比较当前格子与右邻格，标记可能的相邻区域。
                mark_neighbor(current, grid[row][column + 1], target, adjacent);
            }  // 结束当前条件分支。
            if (row + 1 < rows) {  // 当前格子下面还有一行时，才能访问下邻格。
                // 比较当前格子与下邻格，每条纵向相邻关系只检查一次。
                mark_neighbor(current, grid[row + 1][column], target, adjacent);
            }  // 结束当前条件分支。
        }  // 结束本层 for 循环。
    }  // 结束本层 for 循环。

    int count = 0;  // 不重复的邻接区域数从 0 开始。
    for (int region = 1; region <= regions; ++region) {  // 区域编号从 1 开始，因此跳过 adjacent 的下标 0。
        count += adjacent[region];  // 标记为 1 则累加一次，每个区域最多计入一次。
    }  // 结束本层 for 循环。
    printf("%d\n", count);  // 输出与目标区域相邻的不同区域数。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
