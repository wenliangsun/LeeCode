#include <bits/stdc++.h>

using namespace std;

/**
 * 最长公共子序列
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i][j]表示text1的前i个字符和text2的前j个字符中所有子序列的集合，值为子序列的最大长度。
     * 状态计算：见代码
     */
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1])  // 当前字符相等时
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else  // 当前字符不相等时
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }

    /**
     * 打印出最长公共子序列，任意打印一个
     */
    string longestCommonSubsequence2(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        vector<vector<int>> fg(m + 1, vector<int>(n + 1)); // 用来记录状态
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    fg[i][j] = 0;
                } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    fg[i][j] = 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                    fg[i][j] = -1;
                }
            }
        }
        string res;
        printLCS(fg, m, n, text1, res); // 递归打印
        reverse(res.begin(), res.end()); // 翻转一下
        return res;
    }

    /**
     * 打印最长公共子序列
     */
    void printLCS(vector<vector<int>>&fg, int i, int j, string&s1, string& res) {
        if (i == 0 || j == 0) return;
        if (fg[i][j] == 0) {
            res += s1[i - 1];
            printLCS(fg, i - 1, j - 1, s1, res);
        } else if (fg[i][j] == 1) {
            printLCS(fg, i - 1, j, s1, res);
        } else {
            printLCS(fg, i, j - 1, s1, res);
        }
    }
};

int main() {
    Solution s = Solution();
    string s1 = "1A2C3D4B56";
    string s2 = "B1D23CA45B6A";
    string res = s.longestCommonSubsequence2(s1,s2);
    cout << res << endl;
    return 0;
}