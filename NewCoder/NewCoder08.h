//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER08_H
#define C__ALGORITHM_NEWCODER08_H

#endif //C__ALGORITHM_NEWCODER08_H

/**
 * 题目8：跳台阶
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 */
class NewCoder08 {
public:
    /**
     * 递归的思路：
     * 第一次跳一阶 剩余f(n-1) 和第一次跳两阶剩余f(n-2).
     * 所以 f(n) = f(n-1) + f(n-2)
     * f(1) = 1, f(2) = 2
     * @param number
     * @return
     */
    int jumpFloor(int number) {
        if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else {
            int jp = 0;
            int jp1 = 1;
            int jp2 = 2;
            for (int i = 3; i <= number; ++i) {
                jp = jp1 + jp2;
                jp1 = jp2;
                jp2 = jp;
            }
            return jp;
        }
    }
};