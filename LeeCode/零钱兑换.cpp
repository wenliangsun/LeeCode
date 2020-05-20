#include <bits/stdc++.h>

using namespace std;

/**
 * 题目322：零钱兑换
 */

class Solution {
    int res = INT_MAX;

   public:
    /**
     * 动态规划 
     * 有点类似完全背包问题
     * 时间复杂度：O(sN) S是总金额，n是面额数
     * 空间复杂度：O(S)
     */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

    /**
     * 回溯法
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(n)？
     */
    int coinChange(vector<int>& coins, int amount) {
        //对硬币进行排序
        sort(coins.begin(), coins.end()), reverse(coins.begin(), coins.end());
        dfs(coins, amount, 0, 0);
        return res == INT_MAX ? -1 : res;
    }

    // 回溯法
    void dfs(vector<int>& coins, int a, int b, int cnt) {
        if (a == 0) {  // amount 为 0 时说明可以兑换，更新答案
            res = min(res, cnt);
            return;
        }
        if (b == coins.size()) return;  // 不同面值的硬币都用完了，就返回
        // 首先用用面值大的硬币，然后慢慢回溯
        for (int k = a / coins[b]; k >= 0 && k + cnt < res; k--) {
            dfs(coins, a - k * coins[b], b + 1, cnt + k);
        }
    }
};