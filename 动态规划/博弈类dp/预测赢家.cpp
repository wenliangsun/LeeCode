#include <bits/stdc++.h>

using namespace std;

/**
 * 预测赢家
 */

class Solution {
   public:
    /**
     * 石子游戏的普通版
     * MiN-Max法
     * 时间复杂度2^n
     */
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return score(nums, 0, n - 1) >= 0;
    }
    // 暴力递归
    int score(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        return max(nums[l] - score(nums, l + 1, r),
                   nums[r] - score(nums, l, r - 1));
    }

    // 记忆化搜索 时间复杂度O(n^2)
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n));
        return score(nums, 0, n - 1, memo) >= 0;
    }

    int score(vector<int>& nums, int l, int r, vector<vector<int>>& memo) {
        if (l == r) return nums[l];
        if (memo[l][r]) return memo[l][r];
        int res = max(nums[l] - score(nums, l + 1, r, memo),
                      nums[r] - score(nums, l, r - 1, memo));
        memo[l][r] = res;
        return res;
    }
    /**
     * 动态规划
     * 状态表示：dp[i][j]表示i，j区间我可以获得的最大相对分数
     * 状态计算：需要斜着遍历数组
     */
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};