#include <iostream>

using namespace std;

// 282 石子合并
// 区间dp问题

const int N = 310;

int n;
int s[N];
int dp[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i], s[i] += s[i - 1];
    }
    // 枚举区间长度
    for (int len = 2; len <= n; len++) {
        // 枚举左端点
        for (int i = 1; i + len - 1 <= n; i++) {
            // 右端点
            int j = i + len - 1;
            dp[i][j] = 1e8;
            // 计算当前区间的最小合并代价
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
}