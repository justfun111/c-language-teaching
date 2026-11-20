// 目录操作：在内存中更新路径字符串，模拟 cd 和 pwd。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char argument[202], command[4];
    if (scanf("%201s", argument) != 1 || argument[0] != '/') {
        return 1;
    }

    size_t capacity = sizeof argument;
    char *path = malloc(capacity);
    if (path == NULL) {
        return 1;
    }
    strcpy(path, argument);

    while (scanf("%3s", command) == 1) {
        if (strcmp(command, "pwd") == 0) {
            puts(path);
            free(path);
            return 0;
        }
        if (strcmp(command, "cd") != 0 || scanf("%201s", argument) != 1) {
            break;
        }

        if (argument[0] == '/') {
            strcpy(path, argument);
        } else if (strcmp(argument, "..") == 0) {
            char *separator = strrchr(path, '/');
            if (separator == path) {
                path[1] = '\0';
            } else {
                *separator = '\0';
            }
        } else {
            size_t path_length = strlen(path);
            size_t needed = path_length + 1 + strlen(argument) + 1;
            if (needed > capacity) {
                char *larger = realloc(path, needed * 2);
                if (larger == NULL) {
                    break;
                }
                path = larger;
                capacity = needed * 2;
            }
            if (path_length > 1) {
                path[path_length++] = '/';
            }
            strcpy(path + path_length, argument);
        }
    }

    free(path);
    return 1;
}
