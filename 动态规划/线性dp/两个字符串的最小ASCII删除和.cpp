#include <bits/stdc++.h>

using namespace std;

/**
 * 两个字符串的最小ASCII删除和
 */

class Solution {
   public:
    /**
     * 思路：和最短编辑距离思路一样
     * 状态表示：dp[i][j]表示s1的前i个字母和s2的前j个字母中需要删除的最小和
     * 状态计算：dp[i][j] = min(dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1], min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]));
     */
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] + s1[i - 1]; // 边界情况
        for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) // 字符相等的情况
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1],
                                   min(dp[i - 1][j] + s1[i - 1],
                                       dp[i][j - 1] + s2[j - 1]));
            }
        }
        return dp[m][n];
    }
};