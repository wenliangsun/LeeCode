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
};