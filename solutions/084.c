// 目录操作：在内存中更新路径字符串，模拟 cd 和 pwd。
#include <stdio.h>  // 引入 scanf()、puts() 的声明。
#include <stdlib.h>  // 引入 malloc()、realloc()、free() 的声明。
#include <string.h>  // 引入 strcmp()、strcpy()、strrchr()、strlen() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    char argument[202], command[4];  // 为路径参数和短命令准备独立缓冲区，两者都预留字符串结束符。
    // 读取初始路径，并检查它是以斜杠开头的绝对路径。
    if (scanf("%201s", argument) != 1 || argument[0] != '/') {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    size_t capacity = sizeof argument;  // 将动态路径缓冲区的初始容量设为参数缓冲区的大小。
    char *path = malloc(capacity);  // 在堆上分配可扩展的路径缓冲区。
    if (path == NULL) {  // malloc 返回空指针时，表示分配失败。
        return 1;  // 内存分配失败，返回非零退出状态。
    }  // 结束当前条件分支。
    strcpy(path, argument);  // 把初始路径复制到用于记录当前目录的缓冲区。

    while (scanf("%3s", command) == 1) {  // 每次读取一个命令，最多读取三个字符。
        if (strcmp(command, "pwd") == 0) {  // 读到 pwd 时，按要求直接输出当前目录。
            puts(path);  // 把当前的完整路径输出为一行。
            free(path);  // 输出后释放用来存放路径的堆内存。
            return 0;  // 已执行 pwd，程序正常结束。
        }  // 结束当前条件分支。
        // 其余合法命令必须是带路径参数的 cd。
        if (strcmp(command, "cd") != 0 || scanf("%201s", argument) != 1) {
            break;  // 输入无法解析为合法命令时，退出读取循环。
        }  // 结束当前条件分支。

        if (argument[0] == '/') {  // 斜杠开头的参数表示要切换到绝对路径。
            strcpy(path, argument);  // 直接用新的绝对路径替换当前路径。
        } else if (strcmp(argument, "..") == 0) {  // 参数为两点时，表示切换到当前目录的父目录。
            char *separator = strrchr(path, '/');  // 末尾斜杠把当前目录名与父路径分开。
            if (separator == path) {  // 唯一的斜杠在路径开头时，父目录就是根目录。
                path[1] = '\0';  // 保留开头的斜杠，把路径截断成根目录。
            } else {  // 如果末尾斜杠在路径内部，前面还有上级路径。
                *separator = '\0';  // 把末尾斜杠改成结束符，只留下上级路径。
            }  // 结束当前条件分支。
        } else {  // 参数是普通相对路径时，把它追加在当前目录后面。
            size_t path_length = strlen(path);  // 获取当前路径的长度，不包含字符串结束符。
            // 计算拼接所需的字节数，为分隔斜杠和结束符各预留一个字节。
            size_t needed = path_length + 1 + strlen(argument) + 1;
            if (needed > capacity) {  // 拼接长度超出当前容量时，需要扩容。
                char *larger = realloc(path, needed * 2);  // 扩容到所需长度的两倍，先用临时指针接收结果。
                if (larger == NULL) {  // 如果扩容失败，旧缓冲区仍能通过 path 释放。
                    break;  // 退出命令循环，统一释放内存并报告失败。
                }  // 结束当前条件分支。
                path = larger;  // 扩容成功后，用新地址替换旧地址。
                capacity = needed * 2;  // 更新记下的容量，供后续命令检查。
            }  // 结束当前条件分支。
            if (path_length > 1) {  // 根目录已经以斜杠结尾，其他目录才需要加分隔斜杠。
                path[path_length++] = '/';  // 在拼接位置写入斜杠，再把写入位置后移一位。
            }  // 结束当前条件分支。
            strcpy(path + path_length, argument);  // 从拼接位置复制相对路径，连同结束符一起写入。
        }  // 结束当前条件分支。
    }  // 结束本层 while 循环。

    free(path);  // 循环提前结束时，释放路径占用的内存。
    return 1;  // 未顺利执行到 pwd，用返回值 1 表示失败。
}  // 主函数的函数体结束。
