#include <iostream>

using namespace std;

/**
 * 是0-1背包问题的扩展版本
 */

const int N = 110;
int n, m;
int dp[N][N];
int f[N];

int main() {
    cin >> n >> m;
    // for (int i = 1; i <= n; i++) {
    //     int v, w, s;
    //     cin >> v >> w >> s;
    //     for (int j = 0; j <= m; j++) {
    //         dp[i][j] = dp[i - 1][j];
    //         for (int k = 1; k <= s; k++) {
    //             if (j >= k * v)
    //                 dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v] + k * w);
    //         }
    //     }
    // }
    // cout << dp[n][m] << endl;

    // 优化版本
    for (int i = 1; i <= n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= s && k * v <= j; k++)
                f[j] = max(f[j], f[j - k * v] + k * w);
        }
    }
    cout << f[m] << endl;
}