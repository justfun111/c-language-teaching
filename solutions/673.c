// 判断同构数：用竖式乘法逐列检查平方的末尾数字。
#include <ctype.h>  // 引入 isdigit() 的声明。
#include <stdint.h>  // 引入 SIZE_MAX 的定义。
#include <stdio.h>  // 引入 scanf()、printf()、getchar()、fwrite() 的声明。
#include <stdlib.h>  // 引入 malloc()、realloc()、free() 的声明。

// 定义同构数判断函数，接收十进制字符数组和有效位数。
static int is_automorphic(const char digits[], size_t length)
{  // 开始辅助函数的函数体。
    size_t carry = 0;  // 平方的个位没有来自低位的进位，初始进位为 0。
    for (size_t column = 0; column < length; ++column) {  // 从个位开始计算平方，只需检查与原数同样多的低位。
        size_t sum = carry;  // 这一列先计入上一列传来的进位。
        for (size_t i = 0; i <= column; ++i) {  // 枚举一对位下标，其和正好等于当前乘法列的下标。
            int first = digits[length - 1 - i] - '0';  // 从字符串尾部向前取第一位，并把字符转成数值。
            // 第一位的下标确定后，从另一因子取出补足列下标的对应位。
            int second = digits[length - 1 - (column - i)] - '0';
            sum += (size_t)(first * second);  // 两位数字相乘，把部分积加入当前列。
        }  // 结束本层 for 循环。
        // 取当前列的个位，和原数在相同位置的数字比较。
        if (sum % 10 != (size_t)(digits[length - 1 - column] - '0')) {
            return 0;  // 任何一位不匹配时返回 0，表示不是同构数。
        }  // 结束当前条件分支。
        carry = sum / 10;  // 把当前列剩余的十位及以上作为传给下一列的进位。
    }  // 结束本层 for 循环。
    return 1;  // 所有低位都匹配，返回 1 表示是同构数。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    char first;  // first 用来接收跳过前导空白后的第一个字符。
    // 读入第一个字符，并确认它是十进制数字。
    if (scanf(" %c", &first) != 1 || !isdigit((unsigned char)first)) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    size_t capacity = 32, length = 1;  // 缓冲区先预留 32 个字符，已有一位数字等着写入。
    char *digits = malloc(capacity);  // 在堆上分配动态数组，存放输入数字。
    if (digits == NULL) {  // 检查内存分配是否成功。
        return 1;  // 内存分配失败，返回非零退出状态。
    }  // 结束当前条件分支。
    digits[0] = first;  // 把先读到的第一个数字放到数组开头。

    int digit;  // 用 int 接收 getchar 的结果，以区分普通字符与 EOF。
    while ((digit = getchar()) != EOF && isdigit(digit)) {  // 逐个读取后续字符，遇到文件结束或非数字时停止。
        if (length == capacity) {  // 已读位数达到当前容量时，需要扩容。
            if (capacity > SIZE_MAX / 2) {  // 预计容量加倍会超过 size_t 上限时，不能继续扩容。
                free(digits);  // 提前退出前先释放已有数字缓冲区。
                return 1;  // 返回错误状态，表示数组已无法继续增长。
            }  // 结束当前条件分支。
            char *larger = realloc(digits, capacity * 2);  // 尝试将容量翻倍，用临时指针接收分配结果。
            if (larger == NULL) {  // 新指针为空表示扩容失败，旧数组仍然有效。
                free(digits);  // 扩容失败时释放旧数组，避免内存泄漏。
                return 1;  // 因内存空间不足而退出程序。
            }  // 结束当前条件分支。
            digits = larger;  // 扩容成功后，使用新的缓冲区地址。
            capacity *= 2;  // 同步把记录的容量翻倍。
        }  // 结束当前条件分支。
        digits[length++] = (char)digit;  // 将这一位写到末尾，再增加已读位数。
    }  // 结束本层 while 循环。

    size_t start = 0;  // start 记录第一个有效数字的下标。
    while (start + 1 < length && digits[start] == '0') {  // 跳过前导零，但始终至少留下一位数字。
        ++start;  // 将有效数字的起点后移一位。
    }  // 结束本层 while 循环。
    size_t count = length - start;  // 用总位数减去被跳过的位数，得到有效长度。
    fwrite(digits + start, 1, count, stdout);  // 按长度直接输出有效数字，不需要字符串结束符。
    printf(" %d\n", is_automorphic(digits + start, count));  // 判断平方末尾是否匹配原数，输出 1 或 0。
    free(digits);  // 所有输出结束后，释放动态数字缓冲区。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
