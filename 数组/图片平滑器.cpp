#include <bits/stdc++.h>

using namespace std;

/**
 * 题目661：图片平滑器
 */

class Solution {
   public:
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1},
        dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 1, sum = M[i][j];
                for (int k = 0; k < 8; k++) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
                        sum += M[tx][ty];
                        cnt++;
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};