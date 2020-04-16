#include <cstring>
#include <iostream>

using namespace std;

/**
 * 你打开了美了么外卖，选择了一家店，你手里有一张满X元减10元的券，
 * 店里总共有n种菜，第i种菜一份需要A_i元，因为你不想吃太多份同一种菜，
 * 所以每种菜你最多只能点一份，现在问你最少需要选择多少元的商品才能使用这张券。
 *
 * 思路：改进版的0-1背包问题
 */

const int N = 110, X = 10010;

int n, x;
int dp[N][X];
int v[N];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    memset(dp, X, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = min(dp[i - 1][j], v[i]);
            if (j > v[i])
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
        }
    }
    cout << dp[n][x] << endl;
}