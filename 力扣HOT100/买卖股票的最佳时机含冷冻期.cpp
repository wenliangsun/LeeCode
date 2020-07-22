#include <bits/stdc++.h>

using namespace std;

/**
 * 买卖股票的最佳时机含冷冻期
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN, dp_pre_0 = 0;
        for (auto p : prices) {
            int t = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + p);
            dp_i_1 = max(dp_i_1, dp_pre_0 - p); 
            dp_pre_0 = t; 
        }
        return dp_i_0;
    }
};