#include <bits/stdc++.h>

using namespace std;

/**
 * 不同路径
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i][j] 表示到达位置i，j的方案集合，值为数量
     * 状态计算：dp[i][j] = d[i][j-1]+dp[i-1][j]
     */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};