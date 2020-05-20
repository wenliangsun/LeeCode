#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, p;
    while (cin >> s >> p) {
        vector<vector<bool>> dp(s.size() + 1,
                                vector<bool>(p.size() + 1, false));
        // base case 空字符串匹配的情况
        dp[0][0] = true; 
        // 模式串匹配空字符串的情况
        for (int i = 0; i < p.size(); i++)
            dp[0][i + 1] = p[i] == '*' && dp[0][i];
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                // 如果当前字符匹配
                if (s[i] == p[j] || p[j] == '?')
                    dp[i + 1][j + 1] = dp[i][j];
                    // 如果当前字符是 * 时
                else if (p[j] == '*')
                    dp[i + 1][j + 1] = dp[i][j] || dp[i][j + 1] || dp[i + 1][j];
            }
        }
        cout << dp[s.size()][p.size()] << endl;
    }
    return 0;
}