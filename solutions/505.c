// 计算长方形个数：从 m+1 条横线、n+1 条竖线中各选两条。
#include <limits.h>
#include <stdio.h>
#include <string.h>

// 四个因子的十进制总位数不会超过它们的二进制总位数。
enum { MAX_DIGITS = 4 * sizeof(unsigned long long) * CHAR_BIT };

static void multiply(int result[], int *length, unsigned long long factor)
{
    int product[MAX_DIGITS] = {0};
    int offset = 0;
    do {
        int digit = (int)(factor % 10);
        for (int i = 0; i < *length; ++i) {
            product[i + offset] += result[i] * digit;
        }
        factor /= 10;
        ++offset;
    } while (factor != 0);

    int size = *length + offset;
    for (int i = 0; i + 1 < size; ++i) {
        product[i + 1] += product[i] / 10;
        product[i] %= 10;
    }
    while (size > 1 && product[size - 1] == 0) {
        --size;
    }
    memcpy(result, product, (size_t)size * sizeof result[0]);
    *length = size;
}

int main(void)
{
    unsigned long long rows, columns;
    if (scanf("%llu%llu", &rows, &columns) != 2) {
        return 1;
    }

    // 每组 m*(m+1)/2 先将偶数因子减半，再进行乘法。
    const unsigned long long factors[] = {
        rows / 2 + rows % 2, rows + (rows % 2 == 0),
        columns / 2 + columns % 2, columns + (columns % 2 == 0)
    };
    int result[MAX_DIGITS] = {1};
    int length = 1;
    for (size_t i = 0; i < sizeof factors / sizeof factors[0]; ++i) {
        multiply(result, &length, factors[i]);
    }

    for (int i = length - 1; i >= 0; --i) {
        putchar('0' + result[i]);
    }
    putchar('\n');
    return 0;
}
