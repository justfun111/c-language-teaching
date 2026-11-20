// 寻找最长的行：fgets 保留行内空格，等长时保留先读到的一行。
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[103], longest[103] = "";
    size_t maximum = 0;

    while (fgets(line, sizeof line, stdin) != NULL) {
        size_t length = strcspn(line, "\r\n");
        line[length] = '\0';
        if (strcmp(line, "***end***") == 0) {
            break;
        }
        if (length > maximum) {
            maximum = length;
            strcpy(longest, line);
        }
    }

    printf("%zu\n%s\n", maximum, longest);
    return 0;
}
