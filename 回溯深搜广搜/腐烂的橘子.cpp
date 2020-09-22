#include <bits/stdc++.h>

using namespace std;

/**
 * 题目994：腐烂的橘子
 */

class Solution {
   public:
    typedef pair<int, int> PII;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<PII> q;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) cnt++;
                if (grid[i][j] == 2) q.push({i, j});
            }
        }
        int res = 0;
        while (cnt > 0 && q.size()) {
            res++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                int x = t.first, y = t.second;
                for (int j = 0; j < 4; j++) {
                    int a = x + dx[j], b = y + dy[j];
                    if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1) {
                        grid[a][b] = 2;
                        cnt--;
                        q.push({a, b});
                    }
                }
            }
        }
        return cnt > 0 ? -1 : res;
    }
};