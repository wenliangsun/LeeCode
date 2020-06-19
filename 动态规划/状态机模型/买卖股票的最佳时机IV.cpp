#include <bits/stdc++.h>

using namespace std;

/**
 * 题目188：买卖股票的最佳时机IV
 */

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (!prices.size()) return 0;
        if (k > prices.size() / 2) return maxProfitKInf(prices);
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
            for (int j = k; j > 0; j--) {
                if (!i) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                } else {
                    dp[i][j][0] =
                        max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                    dp[i][j][1] =
                        max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                }
            }
        }
        return dp[n - 1][k][0];
    }

    int maxProfitKInf(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (auto p : prices) {
            int t = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + p);
            dp_i_1 = max(dp_i_1, t - p);
        }
        return dp_i_0;
    }
};