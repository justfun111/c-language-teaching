// Fibonacci 数列：第 100 项超出 64 位整数范围，用十进制数组逐位相加。
#include <stdio.h>

enum { DIGITS = 24 };

static void add_digits(int result[], const int addend[])
{
    int carry = 0;
    for (int i = 0; i < DIGITS; ++i) {
        int sum = result[i] + addend[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

int main(void)
{
    int index;
    if (scanf("%d", &index) != 1 || index < 0 || index > 100) {
        return 1;
    }

    int first[DIGITS] = {7};
    int second[DIGITS] = {1, 1};
    int *current = first;
    int *next = second;
    for (int i = 0; i < index; ++i) {
        add_digits(current, next);
        int *temporary = current;
        current = next;
        next = temporary;
    }

    int highest = DIGITS - 1;
    while (highest > 0 && current[highest] == 0) {
        --highest;
    }
    printf("%d ", index);
    for (int i = highest; i >= 0; --i) {
        putchar('0' + current[i]);
    }
    putchar('\n');
    return 0;
}
