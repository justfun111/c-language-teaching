// 车牌限行：中度雾霾时，同一天的两个限行尾号模 5 同余。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int weekday, index, plate;  // 保存星期几、雾霾指数和车牌号。
    if (scanf("%d%d%d", &weekday, &index, &plate) != 3) {  // 按题目给出的顺序读取这三个整数。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int last_digit = plate % 10;  // 车牌号除以 10 的余数就是最后一位。
    int restricted = 0;  // 默认不限行，0 表示否。
    if (weekday <= 5 && index >= 200) {  // 只有工作日且雾霾指数至少为 200 才需要判断尾号。
        if (index < 400) {  // 指数在 200 到 399 时，使用每天限行两个尾号的规则。
            restricted = last_digit % 5 == weekday % 5;  // 对 5 取余后，同一天限行的两个尾号对应同一个余数。
        } else {  // 指数达到 400 时，改用单双号限行。
            restricted = last_digit % 2 == weekday % 2;  // 星期数和尾号奇偶相同时，属于当天的限行尾号。
        }  // 结束当前条件分支。
    }  // 结束当前条件分支。

    printf("%d %s\n", last_digit, restricted ? "yes" : "no");  // 先输出车牌尾号，再按判断结果输出 yes 或 no。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
