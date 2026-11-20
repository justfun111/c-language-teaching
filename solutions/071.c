// 相邻区域：每条共边只需向右、向下各检查一次，用数组去重。
#include <stdio.h>

static void mark_neighbor(int first, int second, int target, int adjacent[])
{
    if (first == target && second != target) {
        adjacent[second] = 1;
    } else if (second == target && first != target) {
        adjacent[first] = 1;
    }
}

int main(void)
{
    int rows, columns, regions, target;
    if (scanf("%d%d%d%d", &rows, &columns, &regions, &target) != 4 ||
        rows < 1 || rows > 19 || columns < 1 || columns > 19 ||
        regions < 1 || regions > 49) {
        return 1;
    }

    int grid[19][19], adjacent[50] = {0};
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (scanf("%d", &grid[row][column]) != 1 ||
                grid[row][column] < 1 || grid[row][column] > regions) {
                return 1;
            }
        }
    }

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            int current = grid[row][column];
            if (column + 1 < columns) {
                mark_neighbor(current, grid[row][column + 1], target, adjacent);
            }
            if (row + 1 < rows) {
                mark_neighbor(current, grid[row + 1][column], target, adjacent);
            }
        }
    }

    int count = 0;
    for (int region = 1; region <= regions; ++region) {
        count += adjacent[region];
    }
    printf("%d\n", count);
    return 0;
}
