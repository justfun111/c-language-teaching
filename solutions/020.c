// 四则运算
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int left, right, result;  // 保存左右操作数和计算结果。
    char operation;  // 运算符是单个字符，所以使用 char 类型。
    // 依次读取整数、运算符和整数，格式串里的空格可以匹配零个空白字符。
    if (scanf("%d %c%d", &left, &operation, &right) != 3) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    if ((operation == '/' || operation == '%') && right == 0) {  // 做除法或取余时，先排除除数为 0 的情况。
        return 1;  // 除数为 0，返回非零退出状态。
    }  // 结束当前条件分支。

    switch (operation) {  // 根据运算符选择对应的计算分支。
    case '+': result = left + right; break;  // 将两个数相加并结束当前 switch。
    case '-': result = left - right; break;  // 用左操作数减去右操作数并结束当前 switch。
    case '*': result = left * right; break;  // 将两个数相乘并结束当前 switch。
    case '/': result = left / right; break;  // 做整数除法，结果向零截断，随后结束当前 switch。
    case '%': result = left % right; break;  // 求整数除法的余数并结束当前 switch。
    default: return 1;  // 未识别的运算符用返回值 1 表示错误。
    }  // 结束switch 分支选择。

    printf("%d%c%d=%d\n", left, operation, right, result);  // 按题意输出原表达式、等号和运算结果。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
