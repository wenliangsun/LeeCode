#include <bits/stdc++.h>

using namespace std;

/**
 * 题目123：买卖股票的最佳时机III
 */
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int dp_i_1_0 = 0, dp_i_1_1 = INT_MIN;
        int dp_i_2_0 = 0, dp_i_2_1 = INT_MIN;
        for (auto p : prices) {
            dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + p);
            dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - p);
            dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + p);
            dp_i_1_1 = max(dp_i_1_1, -p);
        }
        return dp_i_2_0;
    }
};