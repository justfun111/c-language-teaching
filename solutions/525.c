// 和最大子序列：用 Kadane 算法维护以当前元素结尾的最大和。
#include <stdio.h>

int main(void)
{
    int count;
    long long ending, best;
    if (scanf("%d%lld", &count, &ending) != 2 || count < 1) {
        return 1;
    }
    best = ending;

    for (int i = 1; i < count; ++i) {
        long long value;
        if (scanf("%lld", &value) != 1) {
            return 1;
        }
        // 前一段的和为负时，直接从当前元素开始。
        ending = ending > 0 ? ending + value : value;
        if (ending > best) {
            best = ending;
        }
    }

    printf("%lld\n", best);
    return 0;
}
