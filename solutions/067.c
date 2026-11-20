// 查找：边读边输出匹配的位置，下标从 0 开始。
#include <stdio.h>  // 引入 scanf()、printf()、putchar() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, target;  // count 是数列长度，target 是要查找的值。
    if (scanf("%d%d", &count, &target) != 2) {  // 先读取数组长度和目标数。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int found = 0;  // 用 0 表示目前还没遇到任何匹配。
    for (int i = 0; i < count; ++i) {  // 从下标 0 开始，按输入顺序扫描数列。
        int value;  // value 保存当前下标对应的值。
        if (scanf("%d", &value) != 1) {  // 从输入中读取当前元素。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
        if (value == target) {  // 当前值等于目标值时，说明当前位置要输出。
            printf("%s%d", found ? " " : "", i);  // 已有匹配时先输出分隔空格，随后输出当前下标。
            found = 1;  // 记下已经找到过匹配，后续输出时会补空格。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。

    if (!found) {  // 遍历后 found 仍为 0，表示目标值没有出现。
        printf("-1");  // 用 -1 表示找不到目标值。
    }  // 结束当前条件分支。
    putchar('\n');  // 为输出结果补上行尾换行符。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
