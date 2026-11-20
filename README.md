# c语言教学

本仓库收录《上课课件》中的 47 道习题的 C17 参考实现。每道题对应一个独立的 `.c` 文件，文件名是课件题号补足三位后的结果。从标准输入读取数据，按题意输出结果。源文件开头说明了主要解题思路。

## 编译和运行

安装支持 C17 的编译器后，在仓库根目录运行以下命令。以第 2 题「数列分段」为例。

```sh
cc -std=c17 -Wall -Wextra -Wpedantic solutions/002.c -o segments
printf '8\n8 8 8 0 12 12 8 0\n' | ./segments
```

预期输出为 `5`。安装 GNU Make 后，也可以运行 `make` 编译全部习题。程序生成在 `bin/`，例如 `./bin/002`。

## 题目索引

| 题号 | 题目 | 课件文件 |
| --- | --- | --- |
| 2 | [数列分段](solutions/002.c) | `2.pdf` |
| 3 | [最小差值](solutions/003.c) | `3.pdf` |
| 7 | [车牌限行](solutions/007.c) | `7.pdf` |
| 20 | [四则运算](solutions/020.c) | `20.pdf` |
| 27 | [阶梯电价计费](solutions/027.c) | `27.pdf` |
| 28 | [计算某月天数](solutions/028.c) | `28.pdf` |
| 30 | [完数](solutions/030.c) | `30 (1).pdf` |
| 35 | [歌德巴赫猜想](solutions/035.c) | `35.pdf` |
| 36 | [矩阵元素求和并排序](solutions/036.c) | `36.pdf` |
| 37 | [按规则排序](solutions/037.c) | `37.pdf` |
| 39 | [寻找马鞍点](solutions/039.c) | `39.pdf` |
| 40 | [等差数列](solutions/040.c) | `40.pdf` |
| 41 | [PM2.5](solutions/041.c) | `41.pdf` |
| 42 | [整除判断](solutions/042.c) | `42.pdf` |
| 45 | [气温波动](solutions/045.c) | `45.pdf` |
| 46 | [折点计数](solutions/046.c) | `46.pdf` |
| 50 | [选号程序](solutions/050.c) | `50 (1).pdf` |
| 64 | [自然数分解](solutions/064.c) | `64.pdf` |
| 67 | [查找](solutions/067.c) | `67.pdf` |
| 69 | [0-1 矩阵](solutions/069.c) | `69.pdf` |
| 71 | [相邻区域](solutions/071.c) | `71.pdf` |
| 72 | [寻找最长的行](solutions/072.c) | `72.pdf` |
| 73 | [字符串压缩](solutions/073.c) | `73.pdf` |
| 76 | [统计正整数的个数](solutions/076.c) | `76.pdf` |
| 77 | [表达式求值](solutions/077.c) | `77 (2).pdf` |
| 84 | [目录操作](solutions/084.c) | `84 (2).pdf` |
| 87 | [跳一跳](solutions/087.c) | `87.pdf` |
| 147 | [奇数求和](solutions/147.c) | `147.pdf` |
| 185 | [迭代法求根（1）](solutions/185.c) | `185.pdf` |
| 302 | [质数求和](solutions/302.c) | `302.pdf` |
| 384 | [种苹果](solutions/384.c) | `384.pdf` |
| 431 | [区间整数平方和](solutions/431.c) | `431.pdf` |
| 432 | [整数位数计算](solutions/432.c) | `432.pdf` |
| 490 | [猜数字游戏](solutions/490.c) | `490.pdf` |
| 494 | [回文数整除问题](solutions/494.c) | `494.pdf` |
| 505 | [计算长方形个数](solutions/505.c) | `505.pdf` |
| 525 | [和最大子序列](solutions/525.c) | `525.pdf` |
| 526 | [序列分段求和](solutions/526.c) | `526.pdf` |
| 528 | [最接近的三数之和](solutions/528.c) | `528.pdf` |
| 544 | [整数拆分](solutions/544.c) | `544.pdf` |
| 588 | [阶乘运算](solutions/588.c) | `588.pdf` |
| 590 | [数字个数统计（区间整除）](solutions/590.c) | `590.pdf` |
| 595 | [Fibonacci 数列](solutions/595.c) | `595.pdf` |
| 598 | [数字个数统计（分类与平均值）](solutions/598.c) | `598.pdf` |
| 672 | [计算正弦函数](solutions/672.c) | `672.pdf` |
| 673 | [判断同构数](solutions/673.c) | `673.pdf` |
| 680 | [函数的最大值](solutions/680.c) | `680.pdf` |

## 课件中的格式和约定

- 题号 7、37、39、69 各有两个完全相同的 PDF，每题提供一份实现。
- 第 40 题以升序结果的公差为准，只有一个数时输出 `0`。
- 第 384 题的最大疏果量并列时，输出最先出现的轮次。
- 第 588 题按课件公式和样例计算组合数 `C(m, n)`。
- 第 595 题覆盖 `0 ≤ M ≤ 100`，用十进制逐位加法保留第 100 项的完整数值。
