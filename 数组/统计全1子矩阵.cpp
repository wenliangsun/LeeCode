#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1504：统计全1子矩阵
 */

class Solution {
public:
    /**
     * 枚举矩阵中的每个位置，统计以其作为右下角时，有多少个元素全部都是1的子矩阵，
     * 首先预处理得到一个row数组，row[i][j]代表矩阵中i,j向左延伸连续1的个数；
     * 然后统计以i，j为右下角的子矩阵。
     * 
     * 时间复杂度：O(m^2n)
     * 空间复杂度：O(mn)
     */
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> row(m, vector<int>(n));
        // 生成row矩阵
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!j) row[i][j] = mat[i][j];
                else if (mat[i][j]) row[i][j] = row[i][j - 1] + 1;
                else row[i][j] = 0;
            }
        }
        int res = 0;
        // 统计以i,j为右下角的子矩阵个数
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
};