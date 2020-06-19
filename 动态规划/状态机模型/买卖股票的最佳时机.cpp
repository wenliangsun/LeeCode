#include <bits/stdc++.h>

using namespace std;

/**
 * 题目121：买卖股票的最佳时机
 */

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (!n) return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (auto p : prices) {
            dp_i_0 = max(dp_i_0, dp_i_1 + p);
            dp_i_1 = max(dp_i_1, -p);
        }
        return dp_i_0;
    }
};