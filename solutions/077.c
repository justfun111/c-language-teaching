// 表达式求值：运算符的位置不影响两个操作数的读取顺序。
#include <ctype.h>  // 引入 isdigit() 的声明。
#include <stdio.h>  // 引入 scanf()、printf()、ungetc() 的声明。
#include <string.h>  // 引入 strchr() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    long long operands[2], result;  // 保存两个操作数及结果，用 long long 容纳较大的乘积。
    int numbers_read = 0;  // 还未读取任何操作数，计数从 0 开始。
    char operation = '\0';  // 用空字符表示还没有读到运算符。

    for (int i = 0; i < 3; ++i) {  // 表达式由三个记号构成，每轮处理一个。
        char first;  // first 用于判断当前记号以哪个字符开始。
        if (scanf(" %c", &first) != 1) {  // 格式串中的空格跳过空白，然后读取下一个字符。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        if (isdigit((unsigned char)first)) {  // 如果首字符是数字，当前记号是一个非负整数。
            if (numbers_read == 2) {  // 读满两个操作数后出现第三个数，说明表达式格式错误。
                return 1;  // 当前条件无法继续处理，返回非零退出状态。
            }  // 结束当前条件分支。
            ungetc(first, stdin);  // 把刚读取的首位字符放回输入流，便于读取完整整数。
            if (scanf("%lld", &operands[numbers_read]) != 1) {  // 读取完整操作数，按出现顺序存入数组。
                return 1;  // 输入读取或检查失败，返回非零退出状态。
            }  // 结束当前条件分支。
            ++numbers_read;  // 成功读取后，记录已读操作数的数量。
        // 如果当前字符不是数字，先检查运算符位置尚未被占用。
        } else if (operation == '\0' && first != '\0' &&
                   strchr("+-*/%", first) != NULL) {  // 用 strchr 确认字符属于五个合法的运算符。
            operation = first;  // 记录唯一的运算符，稍后统一求值。
        } else {  // 既不是合法数字也不是合法运算符时，进入错误分支。
            return 1;  // 当前条件无法继续处理，返回非零退出状态。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    long long left = operands[0], right = operands[1];  // 操作数的左右顺序取决于读取顺序，与运算符位置无关。
    if ((operation == '/' || operation == '%') && right == 0) {  // 做除法或取余之前确认右操作数不是 0。
        return 1;  // 除数为 0，返回非零退出状态。
    }  // 结束当前条件分支。

    switch (operation) {  // 按运算符选择计算方式。
    case '+': result = left + right; break;  // 计算两个操作数的和并退出 switch。
    case '-': result = left - right; break;  // 用左操作数减右操作数，然后退出 switch。
    case '*': result = left * right; break;  // 计算两个操作数的乘积并退出 switch。
    case '/': result = left / right; break;  // 做整数除法并退出 switch。
    case '%': result = left % right; break;  // 求出整数除法的余数并退出 switch。
    default: return 1;  // 无匹配运算符时，用返回值 1 表示错误。
    }  // 结束switch 分支选择。

    printf("%lld\n", result);  // 用 %lld 输出 long long 类型的结果。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
