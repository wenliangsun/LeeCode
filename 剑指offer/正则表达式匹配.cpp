#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i][j]表示s的前i个字符和p的前j个字符是否匹配
     * 状态计算：分两部分，如果当前字符匹配，则匹配下一个
     *  如果p中当前字符是*，则判断*前面的字符与s中的当前字符是否相等，如果相等，则可以匹配多次1次或0次，如果不相等则匹配0次
     */
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;  // 空字符串匹配
        // 空字符串和a*a*a*a*a*...匹配的情况
        for (int i = 2; i <= m; i += 2)
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 2];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // 当前字符匹配
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                // 下一个字符是*
                if (p[j - 1] == '*') {
                    // *前面的字符和s中的当前字符匹配
                    if (j > 1 && (p[j - 2] == s[i - 1] || p[j - 2] == '.'))
                        // 匹配多次1次0次
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[n][m];
    }

    /**
     * 回溯法
     */
    bool isMatch(string s, string p) { return dfs(s, 0, p, 0); }

    /**
     * 分两种情况：
     * 1.下一个字符是*，如果当前字符匹配（或当前模式串是'.'），则可以匹配0次1次多次，如果当前字符不匹配，则匹配0次
     * 2.下一个字符不是*，如果当前字符匹配，则匹配下一个字符，如果不匹配，返回false
     */
    bool dfs(string& s, int sidx, string& p, int pidx) {
        // 匹配完成
        if (sidx == s.size() && pidx == p.size()) return true;
        // 模式串没有了，匹配失败
        if (sidx < s.size() && pidx == p.size()) return false;
        // 下一个字符是*
        if (pidx + 1 < p.size() && p[pidx + 1] == '*')
            // 当前字符匹配
            if (sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.'))
                // 匹配多次，1次，0次
                return dfs(s, sidx + 1, p, pidx) ||
                       dfs(s, sidx + 1, p, pidx + 2) ||
                       dfs(s, sidx, p, pidx + 2);
            else
                // 当前字符不匹配，则匹配0次
                return dfs(s, sidx, p, pidx + 2);
        // 下一个字符不是*，判断当前字符是否匹配
        if (sidx < s.size() && (s[sidx] == p[pidx] || p[pidx] == '.'))
            return dfs(s, sidx + 1, p, pidx + 1);

        return false;
    }
};