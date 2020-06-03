#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i][j] 表示到(i,j)位置的所有方案，其值是最大价值。
     * 状态计算：dp[i][j] = max(dp[i-1][j], dp[i][j-1]) +
     * grid[i][j]//从左侧来的和从上面来的
     */
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};