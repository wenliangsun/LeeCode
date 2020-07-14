#include <bits/stdc++.h>

using namespace std;

/**
 * 最小路径和
 */

class Solution {
   public:
    // 状态表示：dp[i][j]表示到达位置i，j的最小路径和
    // 状态计算：dp[i][j] = min(dp[i-1][j], dp[i][j - 1]) + grid[i][j]
    int minPathSum(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0]; // 注意这儿的base case
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};