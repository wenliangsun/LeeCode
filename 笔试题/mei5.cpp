#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    vector<string> subs;
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = 0; j < s.size(); j++) {
            subs.push_back(s.substr(i, j - i));
        }
    }
    int res = 0;
    for (auto s : subs) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s[i] == t[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if (dp[i][j] == s.size()) {
                    res %= mod;
                    res++;
                }
            }
        }
        if (dp[s.size()][t.size()] == s.size()) {
            res %= mod;
            res++;
        }
    }
    cout << res % mod << endl;
}