// 自然数分解：这 n 个奇数的平均值为 n²，首项为 n² - (n - 1)。
#include <stdio.h>  // 引入 scanf()、printf()、putchar() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int number;  // number 保存题目给出的正整数 n。
    if (scanf("%d", &number) != 1) {  // 从标准输入读取 n。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int first = number * (number - 1) + 1;  // 连续奇数的平均值是 n²，第一项比平均值小 n - 1。
    for (int i = 0; i < number; ++i) {  // 用下标 i 依次表示这组中的 n 个奇数。
        printf("%s%d", i == 0 ? "" : " ", first + 2 * i);  // 每前进一项就加 2，第一项前不用加空格。
    }  // 结束本层 for 循环。
    putchar('\n');  // 输出所有奇数后换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
