#include <bits/stdc++.h>

using namespace std;

/**
 * 矩阵区域和
 */

class Solution {
   public:
    // 二维前缀和
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1)); // 计算前缀和
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 计算满足条件矩形的左上和右下坐标
                int x0 = max(i - K - 1, 0);
                int x1 = min(i + K, m);
                int y0 = max(j - K - 1, 0);
                int y1 = min(j + K, n);
                res[i - 1][j - 1] = sum[x1][y1] - sum[x0][y1] - sum[x1][y0] + sum[x0][y0];
            }
        }
        return res;
    }
};