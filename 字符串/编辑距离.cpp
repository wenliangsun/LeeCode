#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 0; i <= s1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= s2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    // 依次是插入 删除 替换
                    dp[i][j] = min(dp[i][j - 1] + 1,
                                   min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1));
            }
        }
        cout << dp[s1.size()][s2.size()] << endl;
    }
    return 0;
}