#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1254：统计封闭岛屿的数目
 */

class Solution {
   public:
    int m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    int closedIsland(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && dfs(grid, i, j)) res++;
            }
        }
        return res;
    }

    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (grid[x][y] == 1) return true;
        grid[x][y] = 1;
        bool l = dfs(grid, x - 1, y);
        bool r = dfs(grid, x + 1, y);
        bool u = dfs(grid, x, y - 1);
        bool d = dfs(grid, x, y + 1);
        return l && r && u && d;
    }
};