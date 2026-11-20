// 判断同构数：用竖式乘法逐列检查平方的末尾数字。
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static int is_automorphic(const char digits[], size_t length)
{
    size_t carry = 0;
    for (size_t column = 0; column < length; ++column) {
        size_t sum = carry;
        for (size_t i = 0; i <= column; ++i) {
            int first = digits[length - 1 - i] - '0';
            int second = digits[length - 1 - (column - i)] - '0';
            sum += (size_t)(first * second);
        }
        if (sum % 10 != (size_t)(digits[length - 1 - column] - '0')) {
            return 0;
        }
        carry = sum / 10;
    }
    return 1;
}

int main(void)
{
    char first;
    if (scanf(" %c", &first) != 1 || !isdigit((unsigned char)first)) {
        return 1;
    }

    size_t capacity = 32, length = 1;
    char *digits = malloc(capacity);
    if (digits == NULL) {
        return 1;
    }
    digits[0] = first;

    int digit;
    while ((digit = getchar()) != EOF && isdigit(digit)) {
        if (length == capacity) {
            if (capacity > SIZE_MAX / 2) {
                free(digits);
                return 1;
            }
            char *larger = realloc(digits, capacity * 2);
            if (larger == NULL) {
                free(digits);
                return 1;
            }
            digits = larger;
            capacity *= 2;
        }
        digits[length++] = (char)digit;
    }

    size_t start = 0;
    while (start + 1 < length && digits[start] == '0') {
        ++start;
    }
    size_t count = length - start;
    fwrite(digits + start, 1, count, stdout);
    printf(" %d\n", is_automorphic(digits + start, count));
    free(digits);
    return 0;
}
