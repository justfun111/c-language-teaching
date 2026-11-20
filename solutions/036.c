// 矩阵元素求和并排序：读入时一次累加行、列和符合条件的对角线。
#include <stdio.h>
#include <stdlib.h>

static int compare_descending(const void *left, const void *right)
{
    long long a = *(const long long *)left;
    long long b = *(const long long *)right;
    return (a < b) - (a > b);
}

int main(void)
{
    int size;
    if (scanf("%d", &size) != 1 || size < 3 || size > 19) {
        return 1;
    }

    long long sums[40] = {0};
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            int value;
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            sums[row] += value;
            sums[size + column] += value;
            if (row == column) {
                sums[2 * size] += value;
            }
            if (row + column == size - 1) {
                sums[2 * size + 1] += value;
            }
        }
    }

    int count = 2 * size + 2;
    qsort(sums, (size_t)count, sizeof sums[0], compare_descending);
    for (int i = 0; i < count; ++i) {
        printf("%lld ", sums[i]);
    }
    putchar('\n');
    return 0;
}
