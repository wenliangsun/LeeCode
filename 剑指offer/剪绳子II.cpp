#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 数据量变大了，卡时间复杂度
     *
     * 数论：数学推导 题解
     * https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/solution/mian-shi-ti-14-ii-jian-sheng-zi-iitan-xin-er-fen-f/
     */
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3, p = 1e9 + 7;
        long long res = qmi(3, a - 1, p);
        if (b == 0) return res * 3 % p;
        if (b == 1) return res * 4 % p;
        return res * 6 % p;
    }

    /**
     * 贪心的思路
     */
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int p = 1e9 + 7;
        long long res = 1;
        while (n > 4) {
            res *= 3;
            res %= p;
            n -= 3;
        }
        return res * n % p;
    }

    /**
     * 快速幂模板  求 m^k % p
     */
    long long qmi(int m, int k, int p) {
        long long res = 1 % p, t = m;
        while (k) {
            if (k & 1) res = res * t % p;
            t = t * t % p;
            k >>= 1;
        }
        return res;
    }
};