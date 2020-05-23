//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER11_H
#define C__ALGORITHM_NEWCODER11_H

#endif //C__ALGORITHM_NEWCODER11_H

/**
 * 题目11：二进制中1的个数。
 * 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * 相关题目：
 * 1）用一条语句判断一个整数是否是2的整数次方。思路：一个整数如果是2的整数次方，那么它的二进制表示中有且仅有一位是1，统计1的个数即可。
 * 2）输入两个整数m和n，计算需要改变m的多少位才能得到n，即1010 --> 1101 需要改变3位。思路，先求两个数的异或，再统计异或结果中1的数量。
 *
 * 把一个整数减去1之后再与原来的整数做位与运算，得到的结果相当于是把整数的二进制表示中的最右边一个1变成0.
 *
 */
class NewCoder11 {
public:
    int numberOf1(int n) {
        int count = 0;
        while (n) {
            count++;
            n = (n - 1) & n;
        }
        return count;
    }

    /**
     * 判断一个整数是否是2的整数次方
     * @param n
     * @return
     */
    bool powerOf2(int n) {
        return ~((n - 1) & n);
    }
    /**
     * 输入两个整数m和n，计算需要改变m的多少位才能得到n
     * @param m
     * @param n
     * @return
     */
    int numOfChange(int m, int n) {
        int count = 0;
        int temp = m ^n;
        while (temp) {
            count++;
            temp = (temp - 1) & temp;
        }
        return count;
    }
};