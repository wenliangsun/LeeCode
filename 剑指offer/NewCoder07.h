//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER07_H
#define C__ALGORITHM_NEWCODER07_H

#endif //C__ALGORITHM_NEWCODER07_H

/**
 * 题目7：斐波拉契数列
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 */
class NewCoder07 {
public:
    /**
     * 通常的递归解法
     * 问题：存在大量的重复计算导致效率低。
     * @param n
     * @return
     */
    int Fibonacci01(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return Fibonacci01(n - 1) + Fibonacci01(n - 2);
    }
    /**
     * 为了减少中间的重复计算，我们从f0,f1开始计算，并保存中间结果，介绍计算量
     * @param n
     * @return
     */
    int Fibonacci02(int n) {
        if (n == 0) {
            return  0;
        } else if (n == 1) {
            return  1;
        } else { // 从f0和f1开始计算
            int fb=0;
            int fb1 = 0;
            int fb2 = 1;
            for (int i = 2; i <= n; ++i) {
                fb = fb1 + fb2;
                fb1 = fb2; // 保存中间结果
                fb2 = fb; // 保存中间结果
            }
            return fb;
        }
    }
};