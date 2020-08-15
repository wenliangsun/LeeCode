#include <bits/stdc++.h>

using namespace std;

/**
 * 零钱兑换I和II
 */

class Solution {
   public:
    /**
     * 零钱兑换I：可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
     * 动态规划
     * 状态表示：dp[i]表示凑金额为i时花费的最小金币个数
     * 状态计算：以最后一个金币用的哪一个来转移，dp[i] = min(dp[i], dp[i - c] + 1).
     * 时间复杂度：O(sn)
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if (i >= c) dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }

    /**
     * 零钱兑换II：计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
     * 完全背包求方案数
     * 时间复杂度：O(sn)
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
