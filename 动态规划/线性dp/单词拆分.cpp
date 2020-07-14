#include <bits/stdc++.h>

using namespace std;

/**
 * 单词拆分
 */

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i]表示字符串前i个字符能否由单词表中的单词表示
     * 状态计算：dp[i] = true 如果前i个字符中从后面拆出来一个单词表中的单词，
     * 并且剩余的字符串dp[i-len(单词)]可以用单词表中单词表示时。
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (auto d : wordDict) hash.insert(d);
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && hash.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};