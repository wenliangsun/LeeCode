#include <bits/stdc++.h>

using namespace std;

/**
 * 最长回文子序列
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i][j]表示区间i，j中最长回文子序列,最终答案是dp[0][n-1],所以起点需要倒着遍历
     * 状态计算：见代码
     */
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {  // 枚举区间起点，需要倒着遍历
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {  // 枚举区间终点
                if (s[i] == s[j])              // 如果两端字符相等
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else  // 如果两端字符不相等，则说不他两不能同时出现在序列中
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};