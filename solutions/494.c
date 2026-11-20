// 回文数整除问题：选出前三位 a、b、c，再构造 abcba。
#include <stdio.h>

int main(void)
{
    int divisor;
    if (scanf("%d", &divisor) != 1 || divisor < 2) {
        return 1;
    }

    int count = 0;
    for (int prefix = 100; prefix <= 999; ++prefix) {
        int first = prefix / 100;
        int second = prefix / 10 % 10;
        int palindrome = prefix * 100 + second * 10 + first;
        if (palindrome % divisor == 0) {
            ++count;
        }
    }
    printf("%d %d\n", divisor, count);
    return 0;
}
