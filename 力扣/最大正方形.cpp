#include <bits/stdc++.h>

using namespace std;

/**
 * 题目221：最大正方形
 */

class Solution {
   public:
    /**
     * 动态规划：
     * 状态表示：dp[i][j] 表示以i，j为右下角的只包含1的正方形，其值是最大边长。
     * 状态计算：dp[i][j]
     * 来自左侧，右侧，左上的最小值+1(如果当前位置是1的话)，如果当前位置是0，则dp[i][j]=0
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int len = 0;  // 记录最大正方形的边长
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (!i || !j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j],
                                       min(dp[i - 1][j - 1], dp[i][j - 1])) +
                                   1;
                }
                len = max(len, dp[i][j]); // 更新最大边长
            }
        }
        return len * len;
    }
};