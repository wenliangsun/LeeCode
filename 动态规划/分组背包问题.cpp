#include <iostream>

using namespace std;

const int N = 110;

int n, m;
// v[i][k] 表示第i组中第k个物品的体积
// w[i][k] 表示第i组中第k个物品的价值
// s[i] 表示第i组的物品数量
int v[N][N], w[N][N], s[N];
int dp[N][N];
int f[N];

int main() {
    cin >> n >> m;  // n组物品，m的容量
    for (int i = 1; i <= n; i++) {
        cin >> s[i];  // 每组物品的数量
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         dp[i][j] = dp[i - 1][j];
    //         for (int k = 0; k < s[i]; k++) {
    //             if (j >= v[i][k])
    //                 dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][k]] +
    //                 w[i][k]);
    //         }
    //     }
    // }
    // cout << dp[n][m] << endl;

    // 优化版本
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 0; k < s[i]; k++) {
                if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}
