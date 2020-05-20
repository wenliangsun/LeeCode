#include <bits/stdc++.h>

using namespace std;

/**
 * 混合背包问题
 */

const int N = 1010;

int n, m;
int dp[N];

struct Good {
    int kind;  //物品类型
    int v, w;  // 体积和价值
};

int main() {
    cin >> n >> m;
    vector<Good> goods;
    for (int i = 0; i < n; i++) {
        int v, w, s;
        cin >> v >> w >> s;
        if (s < 0)
            // 0-1背包
            goods.push_back({-1, v, w});
        else if (s == 0)
            // 完全背包
            goods.push_back({0, v, w});
        else {
            // 多重背包转0-1 背包
            for (int k = 1; k <= s; k *= 2) {
                s -= k;
                goods.push_back({-1, k * v, k * w});
            }
            if (s > 0) goods.push_back({-1, s * v, s * w});
        }
    }
    // 先遍历所有的物品
    for (auto g : goods) {
        if (g.kind < 0) {
            for (int j = m; j >= g.v; j--)
                dp[j] = max(dp[j], dp[j - g.v] + g.w);
        } else {
            for (int j = g.v; j <= m; j++)
                dp[j] = max(dp[j], dp[j - g.v] + g.w);
        }
    }
    cout << dp[m] << endl;
    return 0;
}