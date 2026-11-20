// 整除判断
#include <stdio.h>  // 引入 scanf()、printf()、puts() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int dividend, divisor;  // dividend 保存被除数，divisor 保存除数。
    if (scanf("%d%d", &dividend, &divisor) != 2 || divisor == 0) {  // 读取两个整数，并排除除数为 0 的情况。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int remainder = dividend % divisor;  // 用取余运算计算整除时剩下的部分。
    if (remainder == 0) {  // 余数为 0 表示被除数能被除数整除。
        puts("yes");  // 可以整除时输出 yes，puts 会自动换行。
    } else {  // 余数非零时走另一条输出分支。
        printf("%d %d\n", dividend / divisor, remainder);  // 先输出整数商，再输出余数，中间加空格。
    }  // 结束当前条件分支。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
