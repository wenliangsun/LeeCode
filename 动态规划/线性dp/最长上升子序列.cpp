#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i] 表示以i为终点的上升子序列的集合  其中的值表示长度的最大值
     * 状态计算：dp[i] = dp[j]+1 当nums[j]<nums[i]的时候
     *
     * 时间复杂度：O(n^2)
     */
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) res = max(res, dp[i]);
        return res;
    }
};