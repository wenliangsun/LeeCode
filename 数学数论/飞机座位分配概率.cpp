#include <bits/stdc++.h>

using namespace std;

/**
 * 飞机座位分配概率
 *
 * https://leetcode-cn.com/problems/airplane-seat-assignment-probability/solution/ju-ti-fen-xi-lai-yi-bo-by-jobhunter-4/
 * https://leetcode-cn.com/problems/airplane-seat-assignment-probability/solution/zui-xiang-xi-zheng-ming-yi-bu-bu-tui-dao-gao-su-ni/
 */

class Solution {
   public:
    // 直接数学推导
    double nthPersonGetsNthSeat(int n) { return n == 1 ? 1.0 : 0.5; }

    // dp[i]表示i个人时，第i个人坐在自己座位上的概率，(超时)
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1.0;
        vector<double> dp(n + 1);
        dp[1] = 1.0;
        dp[2] = 0.5;
        for (int i = 3; i <= n; i++) {
            double t = 1.0 / i;
            for (int j = 2; j < i; j++) {
                t += dp[i - j + 1] / i;
            }
            dp[i] = t;
        }
        return dp[n];
    }
};