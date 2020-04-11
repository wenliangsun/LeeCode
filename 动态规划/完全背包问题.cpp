#include <iostream>

using namespace std;

const int N = 10010;

int n, m;
int v[N], w[N];
int dp[N][N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    // 朴素版本
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j >= v[i]) {
    //             dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
    //         }
    //     }
    // }

    // 优化版本
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    // cout << dp[n][m] << endl;

    cout << f[m] << endl;

    return 0;
}