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
     * 时间复杂度：O(n^2)
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto d : wordDict) dict.insert(d);
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) { // 满足条件说明，可以表示，设置为true后直接跳出循环。
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};