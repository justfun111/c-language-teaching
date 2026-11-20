// 猜数字游戏：目标由输入给出，按猜中时的次数确定提示语。
#include <stdio.h>  // 引入 scanf()、puts() 的声明。

int main(void)  // 定义程序入口，void 表示该函数不接收参数。
{  // 开始主函数的函数体。
    int target, limit;  // target 保存目标数字，limit 保存允许猜测的次数。
    if (scanf("%d%d", &target, &limit) != 2) {  // 在读取每次猜测前，先读取目标数字和次数上限。
        return 1;  // 输入读取或检查失败，返回非零退出状态。
    }  // 结束当前条件分支。

    int guess;  // guess 保存当前这一次猜测。
    // 从第 1 次开始计数，只要能读到整数就继续处理。
    for (int attempt = 1; scanf("%d", &guess) == 1; ++attempt) {
        if (guess < 0 || attempt > limit) {  // 负数是退出信号，超过次数上限也立即结束游戏。
            puts("Game Over");  // 按题目要求输出游戏结束提示。
            return 0;  // 游戏按规则结束，返回 0。
        }  // 结束当前条件分支。
        if (guess == target) {  // 当前猜测和目标相等时，根据猜中的次数选择提示。
            if (attempt == 1) {  // 检查是否第一次就猜中了目标。
                puts("Bingo!");  // 首次猜中时输出 Bingo!。
            } else if (attempt <= 3) {  // 已排除第一次，这里判断是否在第 2 或第 3 次猜中。
                puts("Lucky You!");  // 在第 2 或第 3 次猜中时输出 Lucky You!。
            } else {  // 其余在次数上限内猜中的情况发生在第 4 次或以后。
                puts("Good Guess!");  // 输出对应的 Good Guess! 提示。
            }  // 结束当前条件分支。
            return 0;  // 猜中后直接完成游戏。
        }  // 结束当前条件分支。
        puts(guess > target ? "Too big" : "Too small");  // 继续游戏时，提示当前猜的数字偏大还是偏小。
    }  // 结束本层 for 循环。

    puts("Game Over");  // 输入耗尽而没有猜中时，也输出结束提示。
    return 0;  // 返回 0，表示程序正常结束。
}  // 主函数的函数体结束。
