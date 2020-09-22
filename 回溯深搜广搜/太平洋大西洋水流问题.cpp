#include <bits/stdc++.h>

using namespace std;

/**
 * 题目417：太平洋大西洋水流问题
 */

class Solution {
   public:
    /**
     * 逆向想，类似洪水灌溉，就可以从边向里面搜索可以到达的区域，分别从太平洋和大西洋的区域进行搜索，将搜索过的区域分别标记，
     * 如果一个区域同时被两次遍历标记，则该区域可以流向两个洋。
     */
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if (!matrix.size() || !matrix[0].size()) return res;
        m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> st1(m, vector<bool>(n));// 分别标记大西洋和太平洋逆向访问过的区域
        vector<vector<bool>> st2(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool isEdge1 = i == 0 || j == 0; // 太平洋
                bool isEdge2 = i == m - 1 || j == n - 1; // 大西洋
                if (isEdge1) dfs(matrix, i, j, st1); // 从边界向里面逆向搜索
                if (isEdge2) dfs(matrix, i, j, st2); // 从边界向里面逆向搜索
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 同时被访问过位置记录答案
                if (st1[i][j] && st2[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<bool>>& st) {
        st[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] >= matrix[x][y] && !st[a][b])
                dfs(matrix, a, b, st);
        }
    }
};