#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1162：地图分析
 */

class Solution {
   public:
    typedef pair<int, int> PII;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<PII> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) q.push({i, j});  // 所有陆地作为源点，入队
            }
        }
        if (q.empty() || q.size() == m * n) return -1; // 如果全是陆地或者海洋，返回-1
        PII t;
        while (q.size()) {
            t = q.front(); // 取出队列元素
            q.pop();
            int x = t.first, y = t.second;
            // 遍历四周的海洋
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 0) {
                    grid[a][b] = grid[x][y] + 1; // 这里直接修改了原数组，因此就不需要额外的数组来标志是否访问
                    q.push({a, b}); // 将四周的海洋入队
                }
            }
        }
        return grid[t.first][t.second] - 1; // 返回最后一次遍历到的海洋的距离。
    }
};