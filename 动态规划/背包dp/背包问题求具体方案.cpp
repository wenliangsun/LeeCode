#include <bits/stdc++.h>

using namespace std;

/**
 * 背包问题求具体方案数
 */

const int N = 1010;

int n, m;
int v[N], w[N];
// 通过判断dp[n-1][m]是否等于dp[n][m]来判断第n个物品有没有被选。
int dp[N][N];  // 这儿只能用二维

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    // 二维动态数组的时候怎么遍历都行，为了获得字典序最小的，从n开始遍历
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i + 1][j];
            if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
        }
    }
    int vol = m;
    // 求具体方案
    for (int i = 1; i <= n; i++) {
        if (vol > v[i] && dp[i][vol] == dp[i + 1][vol - v[i]] + w[i]) {
            cout << i << ' ';
            vol -= v[i];
        }
    }
    return 0;
}