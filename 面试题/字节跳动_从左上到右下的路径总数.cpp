#include <bits/stdc++.h>

using namespace std;

/**
 * 从左上到右下的路径总数，有障碍物
 */

int sumPath(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) continue;
            if (!i && !j) dp[i][j] = 1;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> grid(5, vector<int>(4));
    grid[2][3] = 1;
    grid[4][1] = 1;
    int res = sumPath(grid);
    cout << res << endl;
    return 0;
}