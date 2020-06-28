#include <bits/stdc++.h>

using namespace std;

/**
 * 题目980：不同路径III
 */

class Solution {
   public:
    int res = 0, n, m;
    /**
     * 回溯法：首先统计0的数量（把1的位置也需要加进去），然后利用零的数量来做dfs
     * 因为每一个零的位置都要走一遍！！！
     */
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (!grid.size()) return 0;
        int cnt = 0, x, y;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    x = i, y = j;
                    cnt++;
                } else if (grid[i][j] == 0) {
                    cnt++;
                }
        dfs(grid, x, y, cnt);
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int cnt) {
        // 判断越界
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == -1) return;
        // 如果0的数量为0 并且到达终点2 则答案+1
        if (cnt == 0) {
            if (grid[x][y] == 2) res++;
            return;
        }
        // 二维回溯的标准套路，利用数组自身来标记访问过的位置
        int t = grid[x][y];
        grid[x][y] = -1;
        dfs(grid, x + 1, y, cnt - 1);
        dfs(grid, x - 1, y, cnt - 1);
        dfs(grid, x, y + 1, cnt - 1);
        dfs(grid, x, y - 1, cnt - 1);
        grid[x][y] = t;
    }

    int res = 0, m, n;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        m = grid.size(), n = grid[0].size();
        int cnt = 0, x, y;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    cnt++, x = i, y = j;
                else if (grid[i][j] == 0)
                    cnt++;
        dfs(grid, x, y, cnt);
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int cnt) {
        if (cnt == 0) {
            if (grid[x][y] == 2) res++;
            return;
        }
        int t = grid[x][y];
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] != -1)
                dfs(grid, a, b, cnt - 1);
        }
        grid[x][y] = t;
    }
};