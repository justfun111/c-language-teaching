// 字符串压缩：字母后面紧跟的所有数字共同构成重复次数。
#include <ctype.h>  // 引入 isdigit()、isalpha() 的声明。
#include <stdio.h>  // 引入 scanf()、putchar() 的声明。
#include <stdlib.h>  // 引入 strtol() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    char input[51];  // 为最多 50 个输入字符和字符串结束符分配数组。
    if (scanf("%50s", input) != 1) {  // 读取一个压缩后的字符串，限制读入宽度避免写出数组。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    size_t length = 0;  // length 记录已经解压输出的字符数。
    for (char *cursor = input; *cursor != '\0';) {  // 用指针从字符串开头向后扫描，每轮处理一个字母及其次数。
        unsigned char letter = (unsigned char)*cursor++;  // 先取出当前字节作为字母，再把指针移到下一个字符。
        if (!isalpha(letter)) {  // 每个压缩片段都必须从字母开始。
            return 1;  // 当前条件无法继续处理，返回非零退出状态。
        }  // 结束当前条件分支。

        long repeat = 1;  // 字母后没有数字时，只输出这个字母一次。
        if (isdigit((unsigned char)*cursor)) {  // 检查字母后面是否紧跟一个数字字符。
            repeat = strtol(cursor, &cursor, 10);  // 用十进制读取整个次数，并让 cursor 指向数字串之后。
        }  // 结束当前条件分支。
        // 检查次数为正，且加上本段后不会超过题目的 100 字符上限。
        if (repeat < 1 || (unsigned long)repeat > 100 - length) {
            return 1;  // 当前条件无法继续处理，返回非零退出状态。
        }  // 结束当前条件分支。
        for (long i = 0; i < repeat; ++i) {  // 重复指定的次数，逐个输出相同的字母。
            putchar(letter);  // 每次调用 putchar 输出一个字母。
        }  // 结束本层 for 循环。
        length += (size_t)repeat;  // 将本轮输出的字符数计入总长度。
    }  // 结束本层 for 循环。

    putchar('\n');  // 解压内容输出完毕后换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
