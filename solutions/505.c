// 计算长方形个数：从 m+1 条横线、n+1 条竖线中各选两条。
#include <limits.h>  // 引入 CHAR_BIT 的定义。
#include <stdio.h>  // 引入 scanf()、putchar() 的声明。
#include <string.h>  // 引入 memcpy() 的声明。

// 四个因子的十进制总位数不会超过它们的二进制总位数。
// 根据四个输入因子的二进制总位数，为十进制结果预留足够空间。
enum { MAX_DIGITS = 4 * sizeof(unsigned long long) * CHAR_BIT };

// 定义十进制逐位乘法，原地更新数字数组及其有效长度。
static void multiply(int result[], int *length, unsigned long long factor)
{  // 开始辅助函数的函数体。
    int product[MAX_DIGITS] = {0};  // 临时数组先存各列的乘积之和，低位在前。
    int offset = 0;  // offset 表示当前乘数数字在十进制中的位置。
    do {  // 从乘数个位开始，至少处理一次以覆盖因子为 0 的情况。
        int digit = (int)(factor % 10);  // 通过对 10 取余得到乘数的当前最低位。
        for (int i = 0; i < *length; ++i) {  // 用这一位分别乘被乘数的所有有效数字。
            product[i + offset] += result[i] * digit;  // 将部分乘积加到两位下标之和对应的列。
        }  // 结束本层 for 循环。
        factor /= 10;  // 移去乘数已经处理的最低位。
        ++offset;  // 下一个乘数数字应向更高位对齐。
    } while (factor != 0);  // 只要还有乘数数字没处理完就继续。

    int size = *length + offset;  // 两个因子的位数之和是乘积位数的上界。
    for (int i = 0; i + 1 < size; ++i) {  // 从最低位逐列整理进位，最高列无需再向外进位。
        product[i + 1] += product[i] / 10;  // 将当前列的十位及以上部分进到高一位。
        product[i] %= 10;  // 当前列只留下 0 到 9 的个位数字。
    }  // 结束本层 for 循环。
    while (size > 1 && product[size - 1] == 0) {  // 去掉高位上的 0，同时为数字 0 保留一位。
        --size;  // 跳过一位多余的前导零。
    }  // 结束本层 while 循环。
    memcpy(result, product, (size_t)size * sizeof result[0]);  // 把处理过进位的有效数字复制回结果数组。
    *length = size;  // 同步更新结果数组的有效长度。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    unsigned long long rows, columns;  // 用无符号整数保存非负的行数和列数。
    if (scanf("%llu%llu", &rows, &columns) != 2) {  // 用 %llu 分别读取两项 unsigned long long 数据。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    // 每组 m*(m+1)/2 先将偶数因子减半，再进行乘法。
    const unsigned long long factors[] = {  // 组合数拆成四个因子，逐个相乘以避免中间结果溢出。
        // 这两个因子的乘积是从 rows + 1 条横线中任选两条的方式数。
        rows / 2 + rows % 2, rows + (rows % 2 == 0),
        // 这两个因子的乘积是从 columns + 1 条竖线中任选两条的方式数。
        columns / 2 + columns % 2, columns + (columns % 2 == 0)
    };  // 四个因子全部列出，结束数组初始化。
    int result[MAX_DIGITS] = {1};  // 把十进制数组初始化为 1，作为连乘的起点。
    int length = 1;  // 当前结果 1 只有一位有效数字。
    // 用数组总字节数除以单个元素大小得到因子个数。
    for (size_t i = 0; i < sizeof factors / sizeof factors[0]; ++i) {
        multiply(result, &length, factors[i]);  // 逐个把因子乘到当前结果上。
    }  // 结束本层 for 循环。

    for (int i = length - 1; i >= 0; --i) {  // 数组中低位在前，输出时从最高有效位往回读。
        putchar('0' + result[i]);  // 给数字加上字符 0 的编码，将它转换成可打印的字符。
    }  // 结束本层 for 循环。
    putchar('\n');  // 完整数字输出后换行。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
