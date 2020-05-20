#include <bits/stdc++.h>

using namespace std;

// 回溯法
bool dfs(string s, string p, int sIdx, int pIdx) {
    if (pIdx == p.size()) return sIdx == s.size();
    bool firstMatch =
        (sIdx != s.size() && (p[pIdx] == s[sIdx] || p[pIdx] == '.'));
    if (pIdx + 1 < p.size() && p[pIdx + 1] == '*') {
        return dfs(s, p, sIdx, pIdx + 2) ||
               (firstMatch && dfs(s, p, sIdx + 1, pIdx));
    } else
        return firstMatch && dfs(s, p, sIdx + 1, pIdx + 1);
}

int main() {
    string s, p;
    while (cin >> s >> p) {
        vector<vector<bool>> dp(s.size() + 1,
                                vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        // 考虑 "" 和a*a*a*匹配的情况
        for (int i = 2; i <= p.size(); i += 2) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 2];
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                // 当前字符匹配
                if (p[j - 1] == '.' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                // 当前模式字符是 '*' 时
                if (p[j - 1] == '*') {
                    // 如果 '*' 的前一个字符和匹配串的当前字符不匹配
                    if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                        dp[i][j] = dp[i][j - 2];
                    else
                        // 否则匹配的话，可能匹配多次，匹配 1 次，匹配 0 次
                        dp[i][j] =
                            dp[i - 1][j] || dp[i][j - 1] || dp[i - 1][j - 2];
                }
            }
        }
        cout << dp[s.size()][p.size()] << endl;
    }
    return 0;
}