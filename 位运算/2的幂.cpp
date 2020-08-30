#include <bits/stdc++.h>

using namespace std;

/**
 * 题目231:2的幂
 */

class Solution {
   public:
    /**
     * 直接算
     * 时间复杂度：O(logn)
     */
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }

    /**
     * 位运算 x & (-x)保留了最右边的1， 然后判断和x是否相等，即其他位为0
     * 时间复杂度：O(1)
     * 空间复杂度：O(1)
     */
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        long x = n;
        return (x & (-x)) == x;
    }
};