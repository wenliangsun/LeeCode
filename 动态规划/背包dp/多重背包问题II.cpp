#include <bits/stdc++.h>

using namespace std;

/**
 * 优化版的多重背包问题
 *
 * 时间复杂度：O(n^2)
 */

const int N = 2010;

int n, m;
int dp[N];

struct Good {
    int v, w;  // 物品的体积和价值
};

int main() {
    cin >> n >> m;
    vector<Good> goods;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        // 转换成0-1背包问题
        for (int k = 1; k <= s; k *= 2) {
            s -= k;
            goods.push_back({k * v, k * w});
        }
        if (s > 0) goods.push_back({s * v, s * w});
    }
    // 套用0-1 背包问题模板
    for (auto g : goods) {
        for (int j = m; j >= g.v; j--) {
            dp[j] = max(dp[j], dp[j - g.v] + g.w);
        }
    }
    cout << dp[m] << endl;
    return 0;
}