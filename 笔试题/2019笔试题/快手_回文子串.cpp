#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 *
 * 最长回文子串的动态规划版本的扩展
 */

int main() {
    string s;
    cin >> s;
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1));
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = true;
        res++;
        for (int j = 0; j < i; j++) {
            dp[j][i] = (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1]));
            if (dp[j][i]) res++;
        }
    }
    cout << res << endl;
    return 0;
}