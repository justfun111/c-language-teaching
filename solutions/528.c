// 最接近的三数之和：排序后固定一个数，其余两个数用双指针寻找。
#include <stdio.h>  // 引入 scanf()、printf() 的声明。
#include <stdlib.h>  // 引入 qsort()、abs() 的声明。

// 定义比较函数，供 qsort 按从小到大的顺序排列整数。
static int compare_int(const void *left, const void *right)
{  // 开始辅助函数的函数体。
    int a = *(const int *)left;  // 将第一个元素地址转换为整数指针并取值。
    int b = *(const int *)right;  // 将第二个元素地址转换为整数指针并取值。
    return (a > b) - (a < b);  // 用关系比较生成排序所需的负数、零或正数。
}  // 辅助函数的函数体结束。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int count, values[1000], target;  // count 是数组长度，values 存输入值，target 保存目标和。
    // 读取长度，至少要有三项用来选数，并检查数组容量。
    if (scanf("%d", &count) != 1 || count < 3 || count > 1000) {
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    for (int i = 0; i < count; ++i) {  // 依次访问需要填充的数组位置。
        if (scanf("%d", &values[i]) != 1) {  // 直接将一个整数读入数组下标 i。
            return 1;  // 输入读取或检查失败，返回非零退出状态。
        }  // 结束当前条件分支。
    }  // 结束本层 for 循环。
    if (scanf("%d", &target) != 1) {  // 读完数组后，再读取最后给出的目标值。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。
    // 对数组升序排序，这样移动下标时可以控制三数和的增减。
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    int best = values[0] + values[1] + values[2];  // 取前三个数的和作为最初的候选答案。
    for (int first = 0; first < count - 2; ++first) {  // 枚举三元组中下标最小的元素，给另外两个元素留出位置。
        int left = first + 1, right = count - 1;  // 让左右下标分别指向剩余区间的两端。
        while (left < right) {  // 左下标小于右下标时，两个位置仍各自对应一个元素。
            int sum = values[first] + values[left] + values[right];  // 将固定元素和左右下标处的数相加。
            if (abs(sum - target) < abs(best - target)) {  // 比较候选和与目标值之间的绝对差。
                best = sum;  // 新候选更接近目标时，记下它的三数和。
            }  // 结束当前条件分支。
            if (sum == target) {  // 三数和等于目标时，差为 0，已经达到最优。
                printf("%d\n", sum);  // 输出这个恰好等于目标的三数和。
                return 0;  // 已经得到最佳答案，直接正常退出。
            }  // 结束当前条件分支。
            if (sum < target) {  // 当前和小于目标时，需要尝试增大它。
                ++left;  // 左下标右移，选择一个较大或相同的数。
            } else {  // 已排除相等和偏小，当前和比目标大。
                --right;  // 右下标左移，选择一个较小或相同的数。
            }  // 结束当前条件分支。
        }  // 结束本层 while 循环。
    }  // 结束本层 for 循环。

    printf("%d\n", best);  // 没有恰好命中目标时，输出遍历中找到的最接近的和。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
