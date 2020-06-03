#include <iostream>
#include <vector>

using namespace std;

/**
 * 小Q有X首长度为A的不同的歌和Y首长度为B的不同的歌，
 * 现在小Q想用这些歌组成一个总长度正好为K的歌单，
 * 每首歌最多只能在歌单中出现一次，在不考虑歌单内歌曲的先后顺序的情况下，
 * 请问有多少种组成歌单的方法。
 *
 * 0-1背包求解方案数
 */

const int mod = 1e9 + 7;

int res, n;

void dfs(vector<int> song, int sum, int begin) {
    if (sum == 0) {
        res %= mod, res++;
        return;
    }
    if (sum < 0) return;
    for (int i = begin; i < song.size(); i++) {
        dfs(song, sum - song[i], i + 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        res = 0;
        int la, na, lb, nb;
        cin >> la >> na >> lb >> nb;
        vector<int> song;
        for (int i = 0; i < na; i++) song.push_back(la);
        for (int i = 0; i < nb; i++) song.push_back(lb);

        vector<vector<int>> dp(song.size() + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= song.size(); i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] % mod;
                if (j >= song[i - 1])
                    dp[i][j] =
                        (dp[i][j] + dp[i - 1][j - song[i - 1]] % mod) % mod;
            }
        }
        cout << dp[song.size()][n] << endl;

        // dfs(song, n, 0);
        // cout << res << endl;
    }
    return 0;
}