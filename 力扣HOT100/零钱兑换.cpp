#include <bits/stdc++.h>

using namespace std;

/**
 * 零钱兑换
 */

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i]表示凑金额为i时花费的最小金币个数
     * 状态计算：以最后一个金币用的哪一个来转移，dp[i] = min(dp[i], dp[i - c] + 1).
     * 时间复杂度：O(sn)
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};