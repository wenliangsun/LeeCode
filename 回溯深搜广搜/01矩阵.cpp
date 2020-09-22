#include <bits/stdc++.h>

using namespace std;

/**
 * 题目542:01矩阵
 */

class Solution {
   public:
    // bfs 多源最短路径问题
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        typedef pair<int, int> PII;
        int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
        int m = matrix.size(), n = matrix[0].size();
        queue<PII> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j}); // 源点入队
                } else
                    matrix[i][j] = -1; // 1的位置用-1来表示未访问
            }
        }
        while (q.size()) {
            auto t = q.front(); // 访问结点
            q.pop();
            int x = t.first, y = t.second;
            // 访问当前结点的周围一圈
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && matrix[a][b] == -1) {
                    matrix[a][b] = matrix[x][y] + 1; // 更新距离
                    q.push({a, b}); // 周围结点入队
                }
            }
        }
        return matrix;
    }
};