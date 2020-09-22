#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 要么抢要么不抢
     * dp[i] 表示到位置i时获得的最大收益
     */
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 2);
        // 注意这儿需要反着遍历
        for (int i = nums.size() - 1; i >= 0; i--) {
            // 当前不抢去下一家和当前抢去下下家
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
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