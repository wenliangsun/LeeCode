#include <bits/stdc++.h>

using namespace std;

/**
 * 题目312：戳气球
 */

class Solution {
   public:
    /**
     * 动态规划
     * 如何设计使得子问题之间没有相关性
     * 状态表示：dp[i][j]：表示戳破开区间i到j之间的所有气球获得的最大金币，最后要求的就是dp[0][n+1](我们在开头和结尾分别添加一个虚拟气球)
     * 状态计算：假设开区间走后一个戳破的气球为k，则在戳破第k个气球之前，需要将开区间(i,k)即dp[i][k]和开区间(k,j)即dp[k][j]中的所有气球戳破,
     * 最后戳破第k个气球point[i]* point[k]* point[j],所以状态转移方程是，dp[i][j] = max(dp[i][k]+dp[k][j]+point[i]*point[k] * point[j])i<k<j
     */
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> point(n + 2, 1); // 为数组前后添加虚拟气球
        for (int i = 0; i < n; i++) point[i + 1] = nums[i];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        // 枚举区间起点
        for (int i = n + 1; i >= 0; i--)
            // 枚举区间终点
            for (int j = i + 1; j < n + 2; j++)
                // 枚举区间中的点
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + point[i] * point[k] * point[j]);
        return dp[0][n + 1];
    }
};