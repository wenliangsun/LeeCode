#include <bits/stdc++.h>

using namespace std;

/**
 * 有重量分别为3，5，7公斤的三种货物，和一个载重量为X公斤的箱子（不考虑体积等其它因素，只计算重量）
 * 需要向箱子内装满X公斤的货物，要求使用的货物个数尽可能少（三种货物数量无限）
 * 
 * 完全背包问题的简化版！！！
 */

const int INF = 1000000;

int main() {
    int x;
    cin >> x;
    vector<int> dp(x + 1, INF);
    dp[3] = 1, dp[5] = 1, dp[6] = 2, dp[7] = 1;
    for (int i = 8; i <= x; i++) {
        if (dp[i - 3] == INF && dp[i - 5] == INF && dp[i - 7] == INF)
            dp[i] = INF;
        else
            dp[i] = min(dp[i - 7], min(dp[i - 5], dp[i - 3])) + 1;
    }
    int res = dp[x] == INF ? -1 : dp[x];
    cout << res << endl;
    return 0;
}