#include <bits/stdc++.h>

using namespace std;

/**
 * 题目784：字母大小写全排列
 */

class Solution {
   public:
    vector<string> res;
    /**
     * 标准回溯法
     */
    vector<string> letterCasePermutation(string S) {
        dfs(S, 0);
        return res;
    }

    void dfs(string& s, int idx) {
        res.push_back(s);
        if (idx == s.size()) return;
        for (int i = idx; i < s.size(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                s[i] = s[i] ^ ' ';
                dfs(s, i + 1);
                s[i] = s[i] ^ ' ';
            }
        }
    }
};