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
};