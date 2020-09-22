#include <bits/stdc++.h>

using namespace std;

/**
 * 最大正方形
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i][j] 表示以i，j结尾的矩形的最大边长
     * 状态计算：dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1
     */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int len = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (!i || !j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                len = max(len, dp[i][j]);
            }
        }
        return len * len;
    }
};