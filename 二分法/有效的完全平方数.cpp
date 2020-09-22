#include <bits/stdc++.h>

using namespace std;

/**
 * 题目367：有效的完全平方数
 */

class Solution {
   public:
    // 判断一个数是否是完全平方数，二分法
    bool isPerfectSquare(int num) {
        if (!num) return false;
        long long  l = 0, r = num;
        while (l < r) {
            long long mid = l + (r - l + 1) / 2;
            if (mid * mid <= num) l = mid;
            else r = mid - 1;
        }
        return l * l == num;
    }
    // 牛顿法
    bool isPerfectSquare(int num) {
        if (!num) return false;
        long long t = num;
        while (t * t > num) {
            t = (t + num / t) / 2;
        }
        return t * t == num;
    }
};