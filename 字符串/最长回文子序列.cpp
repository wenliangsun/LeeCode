#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // base case
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        // 注意这儿需要反着遍历
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    // 如果不相等，说明这两个字符不能同时出现的区间，分别将字符加到原来的区间，取其中较大者
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[0][s.size() - 1] << endl;
    }
    return 0;
}