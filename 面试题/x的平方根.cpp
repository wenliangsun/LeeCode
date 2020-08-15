#include <bits/stdc++.h>

using namespace std;

/**
 * x的平方根
 */

class Solution {
   public:
    /**
     * 思路1：二分法
     */
    int mySqrt(int x) {
        long l = 0, r = x;
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            if (mid * mid <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    /**
     * 牛顿法
     */
    int mySqrt(int x) {
        long t = x;
        while (t * t > x) {
            t = (t + x / t) / 2;
        }
        return t;
    }
};