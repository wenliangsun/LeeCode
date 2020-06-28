#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1219：黄金矿工
 */

class Solution {
   public:
    int res = 0, sum, n, m;
    /**
     * 回溯法  深搜
     */
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] != 0) {
                    sum = 0;
                    dfs(grid, i, j);
                }

        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m || !grid[x][y]) return;
        int t = grid[x][y];
        sum += t;
        res = max(res, sum);  // 需要在这儿更新最大值
        grid[x][y] = 0;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
        grid[x][y] = t;
        sum -= t;
    }
};