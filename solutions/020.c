// 四则运算
#include <stdio.h>

int main(void)
{
    int left, right, result;
    char operation;
    if (scanf("%d %c%d", &left, &operation, &right) != 3) {
        return 1;
    }
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

    printf("%d%c%d=%d\n", left, operation, right, result);
    return 0;
}
