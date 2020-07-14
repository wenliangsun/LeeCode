#include <bits/stdc++.h>

using namespace std;

/**
 * 题目279：完全平方数
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i]表示组成数i需要的最少完全平方数的数量
     * 状态计算：dp[i] = min(dp[i], dp[i-j*j]+1) 1<j*j<i
     */
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;  // 用1凑是最长的
            for (int j = 1; j * j <= i; j++) { // 枚举尝试更换平方数
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};