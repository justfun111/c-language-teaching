// 最接近的三数之和：排序后固定一个数，其余两个数用双指针寻找。
#include <stdio.h>
#include <stdlib.h>

static int compare_int(const void *left, const void *right)
{
    int a = *(const int *)left;
    int b = *(const int *)right;
    return (a > b) - (a < b);
}

int main(void)
{
    int count, values[1000], target;
    if (scanf("%d", &count) != 1 || count < 3 || count > 1000) {
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[i]) != 1) {
            return 1;
        }
    }
    if (scanf("%d", &target) != 1) {
        return 1;
    }
    qsort(values, (size_t)count, sizeof values[0], compare_int);

    int best = values[0] + values[1] + values[2];
    for (int first = 0; first < count - 2; ++first) {
        int left = first + 1, right = count - 1;
        while (left < right) {
            int sum = values[first] + values[left] + values[right];
            if (abs(sum - target) < abs(best - target)) {
                best = sum;
            }
            if (sum == target) {
                printf("%d\n", sum);
                return 0;
            }
            if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }

    printf("%d\n", best);
    return 0;
}
