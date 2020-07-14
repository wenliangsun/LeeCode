#include <bits/stdc++.h>

using namespace std;

/**
 * 题目：连续子数组最大和
 */

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        // 状态表示：dp[i] 表示以i为结尾的子数组的集合，其中的值表示子数组的最大和
        // 状态计算：dp[i] = max(dp[i-1], 0) + nums[i]
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) dp[i] = max(dp[i - 1], 0) + nums[i];
        int res = INT_MIN;
        for (int i = 1; i <= n; i++) res = max(res, dp[i]);
        return res;
    }
    /**
     * 优化版本，因为状态转移方程只与上一状态有关
     */
    int maxSubArray(vector<int>& nums) {
        int last = 0, res = INT_MIN;
        for (auto n : nums) {
            int t = max(last, 0) + n;
            res = max(res, t);
            last = t;
        }
        return res;
    }
};