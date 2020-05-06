#include <bits/stdc++.h>

using namespace std;

/**
 * 题目139：单词拆分
 */

class Solution {
   public:
    /**
     * 思路：动态规划
     *
     * dp[i] 表示字符串前i个字符可以是否可以由字典中的单词构成
     * 可以将前i个字组成的字符串分成两部分，一部是s[0,j]一部分是s[j+1,i]
     * 而前面一部分是dp[j]，只需要判断s[j+1,i]是否在字典中
     * dp[i] = dp[j]&&check(s[j+1,i]) 0<= j < i
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto d : wordDict) dict.insert(d);
        // dp[i] 表示字符串前i个字符可以是否可以由字典中的单词构成
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

    /**
     * 备忘录 + 回溯
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    bool wordBreak2(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), 0);
        unordered_set<string> dict;
        for (auto d : wordDict) dict.insert(d);
        return dfs(s, dict, 0, memo);
    }

    /**
     * 递归 + 回溯  会超时
     * 时间复杂度：O(n^n)
     * 空间复杂度：O(n)
     */
    bool wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto d : wordDict) dict.insert(d);
        return dfs(s, dict, 0);
    }

    bool dfs(string s, unordered_set<string> dict, int begin) {
        if (s.size() == begin) {
            return true;
        }
        for (int i = begin; i < s.size(); i++) {
            if (dict.find(s.substr(begin, i - begin + 1)) != dict.end() &&
                dfs(s, dict, i + 1))
                return true;
        }
        return false;
    }

    // 备忘录模式
    bool dfs(string s, unordered_set<string> dict, int begin,
             vector<int>& memo) {
        if (s.size() == begin) {
            return true;
        }
        if (memo[begin]) return memo[begin] > 0;
        for (int i = begin; i < s.size(); i++) {
            if (dict.find(s.substr(begin, i - begin + 1)) != dict.end() &&
                dfs(s, dict, i + 1, memo)) {
                memo[begin] = 1;
                return true;
            }
        }
        memo[begin] = -1;
        return false;
    }
};