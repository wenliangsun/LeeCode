#include <bits/stdc++.h>

using namespace std;

/**
 * 题目494：目标和
 */

class Solution {
   public:
    int res = 0;
    /**
     * 暴力 深搜
     */
    int findTargetSumWays(vector<int>& nums, int s) {
        int cur = 0;
        dfs(nums, 0, s, cur);
        return res;
    }

    void dfs(vector<int>& nums, int idx, int s, int cur) {
        if (idx == nums.size()) {
            if (cur == s) res++;
            return;
        }
        dfs(nums, idx + 1, s, cur + nums[idx]);
        dfs(nums, idx + 1, s, cur - nums[idx]);
    }

    /**
     * 动态规划 转换成0-1背包问题
     * 设正数的子集为P，负数的子集为N，所以要使sum(p)-sum(N)=S，两边同时加上sum(P)+sum(N)==>2sum(p)=S+sum(nums)
     * 所以sum(P) = (S+sum(nums))/2; 问题转换为寻找和为P的方案数
     */
    int findTargetSumWays(vector<int>& nums, int s) {
        if (!nums.size()) return 0;
        int w = 0;
        for (auto n : nums) w += n;
        if (w < s || (s + w) % 2) return 0;
        int p = (s + w) / 2;
        vector<int> dp(p + 1);
        dp[0] = 1;
        for (auto n : nums)
            for (int j = p; j >= n; j--) dp[j] += dp[j - n];
        return dp[p];
    }
};