#include <bits/stdc++.h>

using namespace std;

/**
 * 完全平方数
 */

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i]表示组成数字i需要的最少平方数
     * 状态计算：dp[i] = min(dp[i], dp[i - j * j] + 1)
     */
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};