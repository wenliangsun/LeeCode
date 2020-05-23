//
// Created by wenliangsun on 2020/2/7.
//

#ifndef C__ALGORITHM_NEWCODER12_H
#define C__ALGORITHM_NEWCODER12_H

#endif //C__ALGORITHM_NEWCODER12_H

/**
 * 题目12：数值的整数次方
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 保证base和exponent不同时为0
 */
class NewCoder12 {
public:
    /**
     * 思路： a^n = {a^(n/2)*a^(n/2) n为偶数；a^(n-1/2)*a^(n-1/2)*a n为奇数
     * 考虑边界，异常等！！！
     * @param base
     * @param exponent
     * @return
     */
    double power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;
        int absexponent;
        if (exponent < 0) {
            absexponent = -exponent;
        } else {
            absexponent = exponent;
        }
        double result = power(base, absexponent >> 1);
        result *= result;
        if (absexponent & 1 == 1)
            result *= base;
        return exponent < 0 ? 1 / result : result;
    }
};