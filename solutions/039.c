// 寻找马鞍点：只需在每行的最小值中检查所在列的最大值。
#include <stdio.h>

int main(void)
{
    int rows, columns;
    if (scanf("%d%d", &rows, &columns) != 2 ||
        rows < 1 || rows > 99 || columns < 1 || columns > 99) {
        return 1;
    }

    int row_minimum[99], minimum_column[99], column_maximum[99];
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            int value;
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            if (column == 0 || value < row_minimum[row]) {
                row_minimum[row] = value;
                minimum_column[row] = column;
            }
            if (row == 0 || value > column_maximum[column]) {
                column_maximum[column] = value;
            }
        }
    }

    for (int row = 0; row < rows; ++row) {
        int column = minimum_column[row];
        if (row_minimum[row] == column_maximum[column]) {
            printf("%d %d %d\n", row, column, row_minimum[row]);
            return 0;
        }
    }
    puts("no");
    return 0;
}
