#include <bits/stdc++.h>

using namespace std;

/**
 * 题目485：最大连续1的个数
 */

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i]表示以i结尾的连续1的数量
     */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> dp(nums.size() + 1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (!i)
                    dp[i] = 1;
                else
                    dp[i] = dp[i - 1] + 1;
            } else
                dp[i] = 0;
            res = max(res, dp[i]);
        }
        return res;
    }
};