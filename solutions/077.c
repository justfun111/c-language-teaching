// 表达式求值：运算符的位置不影响两个操作数的读取顺序。
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long long operands[2], result;
    int numbers_read = 0;
    char operation = '\0';

    for (int i = 0; i < 3; ++i) {
        char first;
        if (scanf(" %c", &first) != 1) {
            return 1;
        }
        if (isdigit((unsigned char)first)) {
            if (numbers_read == 2) {
                return 1;
            }
            ungetc(first, stdin);
            if (scanf("%lld", &operands[numbers_read]) != 1) {
                return 1;
            }
            ++numbers_read;
        } else if (operation == '\0' && first != '\0' &&
                   strchr("+-*/%", first) != NULL) {
            operation = first;
        } else {
            return 1;
        }
    }

    long long left = operands[0], right = operands[1];
    if ((operation == '/' || operation == '%') && right == 0) {
        return 1;
    }

    switch (operation) {
    case '+': result = left + right; break;
    case '-': result = left - right; break;
    case '*': result = left * right; break;
    case '/': result = left / right; break;
    case '%': result = left % right; break;
    default: return 1;
    }

    printf("%lld\n", result);
    return 0;
}
