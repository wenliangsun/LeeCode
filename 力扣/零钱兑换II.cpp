#include <bits/stdc++.h>

using namespace std;

/**
 * 题目518：零钱兑换II
 */

class Solution {
   public:
    /**
     * 完全背包问题的思想
     */
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (auto c : coins) {
            for (int j = c; j <= amount; j++) {
                dp[j] += dp[j - c];
            }
        }
        return dp[amount];
    }
};