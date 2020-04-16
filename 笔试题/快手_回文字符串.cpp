#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * 最大回文子串是被研究得比较多的一个经典问题。最近月神想到了一个变种，对于一个字符串，
 * 如果不要求子串连续，那么一个字符串的最大回文子串的最大长度是多少呢。
 *
 * 就是最长回文子序列
 *
 */

int main() {
    string s;
    cin >> s;
    // dp[i][j]表示从i到j区间的最长回文子序列
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++) {
        dp[i][i] = 1;
    }
    // 注意这儿i是倒着遍历的
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][s.size() - 1] << endl;
}
