#include <bits/stdc++.h>

using namespace std;

/**
 * 下降路径最小和
 */

class Solution {
   public:
    /**
     * 思路：和三角形最小路径和类似，这个可称为正方形最小路径和
     * 状态表示：dp[i][j]到达表示第i层第j列的路径最小和
     * 状态计算：dp[i][j] = min(dp[i - 1][j - 1], dp[i-1][j], dp[i-1][j+1]) + A[i][j]
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int INF = 10000; 
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) dp[0][i] = A[0][i];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[i][j]);
                if (j < n - 1) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + A[i][j]);
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) res = min(res, dp[n - 1][i]);
        return res;
    }
};