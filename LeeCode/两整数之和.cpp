#include <bits/stdc++.h>

using namespace std;

/**
 * 题目371：量整数之和
 */

class Solution {
   public:
    /**
     * 思路：考虑采用位运算来做加法，通过实验发现，位运算做加法和正常加法一样，
     * 都是先不考虑进位做加法，再把进位的结果加上去。
     * 发现位运算的不进位加法等价于两个数异或的结果，
     * 位运算的进位只有两个数对应位全是1时才进位，可以通过两个数的与操作然后左移一位得到。
     * (1) 两数字做异或运算得到不进位的和；
     * (2) 两个数字做与运算然后左移一位得到进位的结果。
     * (3) 将上面两个结果相加，直到没有进位停止。
     */
    int getSum(int a, int b) {
        int res = 0, carry = 0;
        res = a ^ b;
        carry = (unsigned int)(a & b) << 1;
        int n1 = res, n2 = carry;
        while (n2) {
            res = n1 ^ n2;
            carry = (unsigned int)(n1 & n2) << 1;
            n1 = res, n2 = carry;
        }
        return res;
    }
};