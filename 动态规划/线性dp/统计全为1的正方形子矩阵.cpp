#include <bits/stdc++.h>

using namespace std;

/**
 * 统计全为1的正方形子矩阵
 */

class Solution {
   public:
    // 状态表示：dp[i][j]以i，j结尾的正方形的数量
    // 状态计算：dp[i][j] = min(dp[i-1][j-1], min(dp[i - 1][j], dp[i][j-1])) + 1
    int countSquares(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0; // 记录总的正方形数量
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    if (!i || !j)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1])) +
                                   1;
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};