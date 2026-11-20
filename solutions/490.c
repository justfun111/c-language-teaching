// 猜数字游戏：目标由输入给出，按猜中时的次数确定提示语。
#include <stdio.h>

int main(void)
{
    int target, limit;
    if (scanf("%d%d", &target, &limit) != 2) {
        return 1;
    }

    int guess;
    for (int attempt = 1; scanf("%d", &guess) == 1; ++attempt) {
        if (guess < 0 || attempt > limit) {
            puts("Game Over");
            return 0;
        }
        if (guess == target) {
            if (attempt == 1) {
                puts("Bingo!");
            } else if (attempt <= 3) {
                puts("Lucky You!");
            } else {
                puts("Good Guess!");
            }
            return 0;
        }
        puts(guess > target ? "Too big" : "Too small");
    }

    puts("Game Over");
    return 0;
}
