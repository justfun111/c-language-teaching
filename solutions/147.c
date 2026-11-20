// 奇数求和：余数非零即可判断奇数，负奇数同样适用。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    long long value, sum = 0;  // value 保存当前整数，sum 保存奇数之和，两者都使用 long long。
    while (scanf("%lld", &value) == 1 && value != 0) {  // 逐个读取整数，遇到哨兵值 0 就停止读取。
        if (value % 2 != 0) {  // 余数非零表示奇数，这个判断同样覆盖负奇数。
            sum += value;  // 将当前奇数加入累加结果。
        }  // 结束当前条件分支。
    }  // 结束本层 while 循环。

    printf("%lld\n", sum);  // 输出 0 出现之前所有奇数的和。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
