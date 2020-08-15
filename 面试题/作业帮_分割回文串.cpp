#include <bits/stdc++.h>

using namespace std;

/**
 * 分割回文串
 */

class Solution {
   public:
    vector<vector<string>> res;
    // 回溯法
    vector<vector<string>> partition(string s) {
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

    void dfs(string s, int idx, vector<string>& path) {
        if (idx == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            auto t = s.substr(idx, i - idx + 1);
            auto tt = t;
            reverse(tt.begin(), tt.end());
            if (tt != t) continue;
            path.push_back(t);
            dfs(s, i + 1, path);
            path.pop_back();
        }
    }
};