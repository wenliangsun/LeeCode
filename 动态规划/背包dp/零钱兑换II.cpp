#include <bits/stdc++.h>

using namespace std;

/**
 * 题目518：零钱兑换II
 */

class Solution {
   public:
    /**
     * 完全背包求方案数
     */
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};