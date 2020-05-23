#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 状态表示：dp[i][j] 表示到达(i,j)这个位置的所有路径集合，其值路径的数量
     * 状态转换：从上面来的和从左边来的 见代码
     */
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j]) continue;                // 障碍
                if (!i && !j) dp[i][j] = 1;           // 起点
                if (i > 0) dp[i][j] += dp[i - 1][j];  // 左边来的
                if (j > 0) dp[i][j] += dp[i][j - 1];  // 右边来的
            }
        }
        return dp[n - 1][m - 1];
    }
};