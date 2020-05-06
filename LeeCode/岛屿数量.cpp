#include <bits/stdc++.h>

using namespace std;

/**
 * 题目200：岛屿数量
 */

class Solution {
   public:
    /**
     * 深度优先搜索
     */
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if (!r) return 0;
        int c = grid[0].size();
        int res = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                // 寻找1，然后把与1相接的变为0
                if (grid[i][j] == '1') {
                    res++;
                    // 寻找与当前位置相接的陆地，并置为0
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1);
    }
};