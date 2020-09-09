#include <bits/stdc++.h>

using namespace std;

/**
 * 动态规划
 * 状态表示：dp[i][j]表示s1的前i个字符和s2的前j个字符能否交错构成s3的前i+j个字符
 * 状态转移：根据s3的最后一个来自s1还是来自s2分两种情况：见代码
 */
bool isInterleave(string& s1, string& s2, string& s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) return false;
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            int idx = i + j - 1;
            if (i > 0) dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[idx]);
            if (j > 0) dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[idx]);
        }
    }
    return dp[m][n];
}

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    bool res = isInterleave(s1, s2, s3);
    cout << res << endl;
    return 0;
}