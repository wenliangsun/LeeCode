#include <bits/stdc++.h>

using namespace std;

/**
 * 岛屿数量
 */

class Solution {
   public:
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    // 二维深搜
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == '1')
                dfs(grid, a, b);
        }
    }
};