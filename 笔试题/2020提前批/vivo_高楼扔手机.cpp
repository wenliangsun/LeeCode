#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n;
    while (cin >> k >> n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) dp[1][i] = i;  // base case
        for (int i = 2; i <= k; i++) {              // 枚举鸡蛋
            for (int j = 1; j <= n; j++) {          // 枚举楼层
                int minV = INT_MAX;
                for (int m = 1; m <= j; m++) {  // 选择从哪个楼层扔
                    // 状态更新
                    minV = min(minV, max(dp[i - 1][m - 1], dp[i][j - m]) + 1);
                }
                dp[i][j] = minV;
            }
        }
        cout << dp[k][n] << endl;
    }
}