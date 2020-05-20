#include <bits/stdc++.h>

using namespace std;

/**
 * 二维费用的背包问题
 */

const int N = 1010;

int n, m, g;   // 数量，体积，重量
int dp[N][N];  // dp[i][j]表示总体积是i，总重量是j时的最大价值

int main() {
    cin >> n >> m >> g;
    for (int i = 0; i < n; i++) {
        int v, w, p;  // 体积，重量, 价值
        cin >> v >> w >> p;
        for (int j = m; j >= v; j--) { // 体积
            for (int k = g; k >= w; k--) { // 重量
                dp[j][k] = max(dp[j][k], dp[j - v][k - w] + p);
            }
        }
    }
    cout << dp[m][g] << endl;
    return 0;
}
