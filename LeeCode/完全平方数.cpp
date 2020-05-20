#include <bits/stdc++.h>

using namespace std;

/**
 *  题目279：完全平方数
 */

class Solution {
   public:
    /**
     * 动态规划
     * 时间复杂度：O(nsqrt(n))
     * 空间复杂度：O(n)
     */
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) dp[i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = sqrt(i); j >= 1; j--) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }

    // 贪心 + 广搜
    int numSquares(int n) {}
};