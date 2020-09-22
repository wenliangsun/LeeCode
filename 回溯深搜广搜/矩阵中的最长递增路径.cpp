#include <bits/stdc++.h>

using namespace std;

/**
 * 题目329：矩阵中的最长递增路径的长度
 */

class Solution {
   public:
    /**
     * 带备忘录的深搜
     * 同一个单元格对应的最长递增路径的长度是固定不变的，因此可以使用记忆化的方法进行优化。
     * 时间复杂度：O(mn)
     * 空间复杂度：O(mn)
     */
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    vector<vector<int>> memo;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        m = matrix.size(), n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& matrix, int x, int y) {
        if (memo[x][y]) return memo[x][y];
        int t = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] > matrix[x][y])
                t = max(t, dfs(matrix, a, b));
        }
        t++;
        memo[x][y] = t;
        return t;
    }
};