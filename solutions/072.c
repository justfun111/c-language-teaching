// 寻找最长的行：fgets 保留行内空格，等长时保留先读到的一行。
#include <stdio.h>  // 引入 printf()、fgets() 的声明。
#include <string.h>  // 引入 strcspn()、strcmp()、strcpy() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    char line[103], longest[103] = "";  // line 存当前输入行，longest 存目前最长的行，缓冲区预留行尾和结束符。
    size_t maximum = 0;  // 尚未处理任何一行，最长长度初始化为 0。

    // 用 fgets 读取整行，保留行内空格，读到文件末尾时结束。
    while (fgets(line, sizeof line, stdin) != NULL) {
        size_t length = strcspn(line, "\r\n");  // 找到第一个回车或换行的位置，得到正文的字节数。
        line[length] = '\0';  // 在行尾写入字符串结束符，去掉回车和换行。
        if (strcmp(line, "***end***") == 0) {  // 识别题目给出的结束标记，这一行不参加比较。
            break;  // 跳出读行循环，转去输出结果。
        }  // 结束当前条件分支。
        if (length > maximum) {  // 只有新行更长时才替换，等长时保留先出现的行。
            maximum = length;  // 记录新的最长长度。
            strcpy(longest, line);  // 把当前行的文本复制到最长行缓冲区。
        }  // 结束当前条件分支。
    }  // 结束本层 while 循环。

    printf("%zu\n%s\n", maximum, longest);  // 用 %zu 输出 size_t 类型的长度，再单独输出最长行的内容。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
