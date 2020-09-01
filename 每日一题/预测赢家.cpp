#include <bits/stdc++.h>

using namespace std;

/**
 * 题目486：预测赢家
 */

class Solution {
public:
    /**
     * 动态规划
     */
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n)); // dp[i][j]表示玩家面对[i,j]区间时获得的最大相对分数
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        // 斜着遍历数组
        for (int l = 2; l <= n; l++) { // 控制斜着遍历的次数
            for (int i = 0; i < n - l + 1; i++) { // 遍历斜着的每一列
                int j = i + l - 1;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }

    /**
     * 备忘录
     */
    vector<vector<int>> memo;
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n, vector<int>(n));
        return score(nums, 0, n - 1) >= 0;
    }

    int score(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        if (memo[l][r]) return memo[l][r];
        int t = max(nums[l] - score(nums, l + 1, r), nums[r] - score(nums, l, r - 1));
        memo[l][r] = t;
        return t;
    }

    /**
     * 暴力递归
     * 计算当前玩家面对区间[l,r]时可以获得的最大相对分数
     * 时间复杂度：O(2^n)
     * 空间复杂度：递归的栈空间 O(n)
     */
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return score(nums, 0, n - 1) >= 0;
    }

    int score(vector<int>& nums, int l, int r) {
        if (l == r) return nums[l];
        int t = max(nums[l] - score(nums, l + 1, r), nums[r] - score(nums, l, r - 1));
        return t;
    }
};