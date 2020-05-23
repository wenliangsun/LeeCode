#include <bits/stdc++.h>

using namespace std;

/**
 * 题目140：单词拆分II
 */

class Solution {
    vector<vector<string>> tmp;

   public:
    /**
     * 带备忘录的回溯法
     */
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> m;
        return dfs(m, wordDict, s);
    }
    // 带备忘录的回溯
    vector<string> dfs(unordered_map<string, vector<string>>& m,
                       vector<string>& wordDict, string s) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (auto word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> tmp = dfs(m, wordDict, s.substr(word.size()));
            for (auto itm : tmp) {
                res.push_back(word + (itm.empty() ? "" : " " + itm));
            }
        }
        m[s] = res;
        return res;
    }

    /**
     * 动态规划  超时
     *
     * 时间复杂度：O(n^3)
     */
    vector<string> wordBreak2(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto d : wordDict) dict.insert(d);
        vector<vector<string>> dp(s.size() + 1, vector<string>());
        vector<string> init;
        init.push_back("");
        dp[0] = init;
        for (int i = 1; i <= s.size(); i++) {
            vector<string> tmp;
            for (int j = 0; j < i; j++) {
                if (dp[j].size() > 0 &&
                    dict.find(s.substr(j, i - j)) != dict.end()) {
                    for (auto t : dp[j]) {
                        tmp.push_back(t + (t == "" ? "" : " ") +
                                      s.substr(j, i - j));
                    }
                }
            }
            dp[i] = tmp;
        }
        return dp[s.size()];
    }

    /**
     * dfs + 回溯  会超时
     * 可以优化为备忘录模式，减少过多的计算，也可动态规划
     *
     * 时间复杂度：O(n^n)
     * 空间复杂度：O(n^3)
     */
    vector<string> wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto d : wordDict) dict.insert(d);
        vector<string> path;
        dfs(s, dict, 0, path);
        vector<string> res;
        for (int i = 0; i < tmp.size(); i++) {
            string t = tmp[i][0];
            for (int j = 1; j < tmp[i].size(); j++) {
                t += ' ', t += tmp[i][j];
            }
            res.push_back(t);
        }
        return res;
    }

    void dfs(string s, unordered_set<string> dict, int begin,
             vector<string> path) {
        if (s.size() == begin) {
            tmp.push_back(path);
            return;
        }
        for (int i = begin; i < s.size(); i++) {
            if (dict.find(s.substr(begin, i - begin + 1)) != dict.end()) {
                path.push_back(s.substr(begin, i - begin + 1));
                dfs(s, dict, i + 1, path);
                path.pop_back();
            }
        }
    }
};