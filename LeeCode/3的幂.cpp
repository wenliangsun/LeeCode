#include <bits/stdc++.h>

using namespace std;

/**
 * 题目326：3的幂
 */

class Solution {
   public:
    /**
     * 使用循环
     */
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }

    /**
     * 数学法 换底公式
     * log10(n)/log10(3) 是不是一个整数
     */
    bool isPowerOfThree(int n) {
        double res = log10(n) / log10(3);
        return res - (int)res > 0 ? false : true;
    }
};