//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER09_H
#define C__ALGORITHM_NEWCODER09_H

#endif //C__ALGORITHM_NEWCODER09_H

/**
 * 题目9：变态跳台阶
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */
class NewCoder09 {
public:
    /**
     * 思路：沿用跳台阶的思路
     * 这次可以一次可以跳1,2,3,...,n阶，所以：
     * f(n) = f(n-1)(跳了一阶) + f(n-2)+ ...+ f(0)    (1)
     * f(n-1) = f(n-2)(跳了两阶) + f(n-3)+ ...+ f(0)  (2)
     * 由(1)-(2)得：
     * f(n) = 2f(n-1);
     * 其中：f(1) = 1
     * @param number
     * @return
     */
    int jumpFloorII(int number) {
        if (number == 1) {
            return 1;
        } else {
            return jumpFloorII(number - 1) << 1;
        }
    }
};