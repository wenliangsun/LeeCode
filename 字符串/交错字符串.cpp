#include <bits/stdc++.h>

using namespace std;

/**
 * 题目97：交错字符串
 */

class Solution {
public:
    /**
     * 动态规划
     * 状态表示：dp[i][j]表示s1的前i个字符和s2的前j个字符能否组成s3的前i+j个字符
     * 状态计算：根据s3的最后一个字符是s1提供还是s2提供，分两种情况：
     *        (1)s3的最后一个字符来自s1的情况：dp[i][j] = dp[i][j] || (dp[i - 1][j]&&s1[i - 1] == s3[i + j - 1]);
     *        (2)s3的最后一个字符来自s2的情况：dp[i][j] = dp[i][j] || (dp[i - 1][j]&&s2[j - 1] == s3[i + j - 1])
     */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false; // 如果长度不匹配，直接返回false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true; // base case
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int idx = i + j - 1;
                if (i > 0) dp[i][j] = dp[i][j] || (dp[i - 1][j] && s1[i - 1] == s3[idx]);
                if (j > 0) dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[idx]);
            }
        }
        return dp[m][n];
    }
};