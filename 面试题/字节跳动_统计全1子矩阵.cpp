#include <bits/stdc++.h>

using namespace std;

/**
 * 时间复杂度：O(nm^2)
 * 空间复杂度：O(mn)
 */
int numSubmat(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> row(m, vector<int>(n));
    // 构建row矩阵
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!j) row[i][j] = mat[i][j];
            else if (mat[i][j]) row[i][j] = row[i][j - 1] + 1;
            else row[i][j] = 0;
        }
    }
    int res = 0;
    // 依次统计以i，j为结尾的子矩阵个数
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int col = row[i][j];
            for (int k = i; k >= 0 && col; k--) {
                col = min(col, row[k][j]);
                res += col;
            }
        }
    }
    return res;
}