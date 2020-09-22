#include <bits/stdc++.h>

using namespace std;

/**
 * 题目377：组合总数
 */

class Solution {
   public:
    /**
     * 完全背包问题，但因为是有序的所以需要将物品(数字)放在内循环，需要注意的是越界的情况
     * 时间复杂度：O(n*target)
     * 空间复杂度：O(target)
     */
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (auto n : nums) {
                if (i >= n) dp[i] = (dp[i] > INT_MAX - dp[i - n]) ? INT_MAX : dp[i] + dp[i - n];
            }
        }
        return dp[target];
    }
};