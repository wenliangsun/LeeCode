#include <bits/stdc++.h>

using namespace std;

/**
 * 背包问题求解方案数
 */

const int N = 1010, mod = 1e9 + 7, INF = 100000000;

int n, m;
// dp[j] 表示当体积恰好是j的时候的最大价值，g[j]表示体积恰好是j的时候的方案数。
int dp[N], g[N];

int main() {
    cin >> n >> m;
    g[0] = 1;  // 体积为0时的方案数只有一种
    for (int i = 1; i <= m; i++) dp[i] = -INF;  // 这儿区别于0-1背包问题
    for (int i = 0; i < n; i++) {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--) {
            // 这儿计算最大值价值，分两种情况
            int t = max(dp[j], dp[j - v] + w);
            int s = 0;
            // 如果和第一种情况相同，加第一种对应的方案数
            if (t == dp[j]) s += g[j];
            // 如果和第二种情况相同，加第二种对应的方案数
            if (t == dp[j - v] + w) s += g[j - v];
            if (s >= mod) s -= mod;
            dp[j] = t;
            g[j] = s;
        }
    }
    int maxw = 0;
    // 寻找最大价值(并不一定体积用满才是最优方案)，区别于0-1背包问题中动态数组的含义！！！
    for (int i = 0; i <= m; i++) maxw = max(maxw, dp[i]);
    int res = 0;
    for (int i = 0; i <= m; i++) {
        if (dp[i] == maxw) res += g[i];
        if (res >= mod) res -= mod;
    }
    cout << res << endl;
    return 0;
}