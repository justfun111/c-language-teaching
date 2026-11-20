// 0-1 矩阵：遇到 0 时清空当前连续长度。
#include <stdio.h>

int main(void)
{
    int rows, columns;
    if (scanf("%d%d", &rows, &columns) != 2) {
        return 1;
    }

    for (int row = 0; row < rows; ++row) {
        int length = 0, best_length = 0, best_end = -1;
        for (int column = 0; column < columns; ++column) {
            int value;
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            length = value == 1 ? length + 1 : 0;
            if (length > best_length) {
                best_length = length;
                best_end = column;
            }
        }

        int best_start = best_length == 0 ? -1 : best_end - best_length + 1;
        printf("%d %d\n", best_start, best_end);
    }
    return 0;
}
