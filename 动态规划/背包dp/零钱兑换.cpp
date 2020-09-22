#include <bits/stdc++.h>

using namespace std;

/**
 * 题目322：零钱兑换
 */

class Solution {
   public:
    /**
     * 完全背包问题
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};