#include <bits/stdc++.h>

using namespace std;

/**
 * 题目714：买卖股票的最佳时机含手续费
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        if (!prices.size()) return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (auto p : prices) {
            int t = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + p);
            dp_i_1 = max(dp_i_1, t - p - fee);
        }
        return dp_i_0;
    }
};