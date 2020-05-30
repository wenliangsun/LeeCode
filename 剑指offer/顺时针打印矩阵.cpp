#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 代码简洁
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (!matrix.size()) return res;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> st(n, vector<bool>(m));
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, d = 0;
        for (int i = 1; i <= n * m; i++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || st[nx][ny]) {
                d = (d + 1) % 4;
                nx = x + dx[d], ny = y + dy[d];
            }
            res.push_back(matrix[x][y]);
            st[x][y] = true;
            x = nx, y = ny;
        }
        return res;
    }

    /**
     * 模拟法 代码复杂!
     */
    vector<int> res;
    int n, m;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return res;
        n = matrix.size(), m = matrix[0].size();
        int l = 0;
        while (l * 2 < n && l * 2 < m) {
            helper(matrix, l);
            l++;
        }
        return res;
    }

    void helper(vector<vector<int>>& matrix, int b) {
        int endx = m - b - 1, endy = n - b - 1;
        for (int i = b; i <= endx; i++) res.push_back(matrix[b][i]);
        if (b < endy)
            for (int i = b + 1; i <= endy; i++) res.push_back(matrix[i][endx]);
        if (b < endx && b < endy)
            for (int i = endx - 1; i >= b; i--) res.push_back(matrix[endy][i]);
        if (b < endx && b < endy - 1)
            for (int i = endy - 1; i > b; i--) res.push_back(matrix[i][b]);
    }
};