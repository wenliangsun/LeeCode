#include <bits/stdc++.h>

using namespace std;

/**
 * 题目695：岛屿的最大面积
 */

class Solution {
   public:
    int m, n, cnt = 0;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt = 0;
                    dfs(grid, i, j);
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        cnt++;
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b])
                dfs(grid, a, b);
        }
    }
};