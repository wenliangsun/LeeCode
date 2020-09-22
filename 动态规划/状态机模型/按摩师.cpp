#include <bits/stdc++.h>

using namespace std;

/**
 * 题目：按摩师
 */

class Solution {
   public:
    /**
     * 和打家劫舍I一样
     */
    int massage(vector<int>& nums) {
        vector<int> dp(nums.size() + 2);
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }

    /**
     * 空间优化
     */
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int dp_i_1 = 0, dp_i_2 = 0, dp_i = 0;
        for (auto n : nums) {
            dp_i = max(dp_i_1, dp_i_2 + n);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};