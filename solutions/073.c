// 字符串压缩：字母后面紧跟的所有数字共同构成重复次数。
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[51];
    if (scanf("%50s", input) != 1) {
        return 1;
    }

    size_t length = 0;
    for (char *cursor = input; *cursor != '\0';) {
        unsigned char letter = (unsigned char)*cursor++;
        if (!isalpha(letter)) {
            return 1;
        }

        long repeat = 1;
        if (isdigit((unsigned char)*cursor)) {
            repeat = strtol(cursor, &cursor, 10);
        }
        if (repeat < 1 || (unsigned long)repeat > 100 - length) {
            return 1;
        }
        for (long i = 0; i < repeat; ++i) {
            putchar(letter);
        }
        length += (size_t)repeat;
    }

    putchar('\n');
    return 0;
}
