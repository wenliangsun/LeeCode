//
// Created by wenliangsun on 2020/2/12.
//

#ifndef C__ALGORITHM_NEWCODER31_H
#define C__ALGORITHM_NEWCODER31_H

#endif //C__ALGORITHM_NEWCODER31_H

/**
 * 题目31：整数中1出现的次数(从1到n整数中1出现的次数)
 */
class NewCoder31 {
public:
    /**
     * 统计每个数字中1的个数
     * @param n
     * @return
     */
    int NumberOf1Between1AndN_Solution01(int n) {
        if (n == 0)
            return 0;
        int num = 0;
        for (int i = 1; i <= n; ++i) {
            num += numberOf1(i);
        }
        return num;
    }

    /**
     * 思路2：
     * @param n
     * @return
     */
    int NumberOf1Between1AndN_Solution02(int n) {
        return 0;
    }

private:
    /**
     * 统计一个数字中1的个数
     * @param n
     * @return
     */
    int numberOf1(int n) {
        if (n == 0)
            return 0;
        int num = 0;
        while (n != 0) {
            if (n % 10 == 1)
                num++;
            n /= 10;
        }
        return num;
    }
};