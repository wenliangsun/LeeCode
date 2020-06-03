#include <bits/stdc++.h>

using namespace std;

/**
 * 字符串全排列
 */

class Solution {
   public:
    vector<string> res;
    vector<bool> st;
    vector<string> permutation(string s) {
        string path;
        sort(s.begin(), s.end());
        st = vector<bool>(s.size());
        dfs(s, 0, path);
        return res;
    }

    void dfs(string& s, int idx, string& path) {
        if (idx == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (st[i] || (i > 0 && s[i] == s[i - 1] && !st[i - 1])) continue;
            st[i] = true;
            path.push_back(s[i]);
            dfs(s, idx + 1, path);
            st[i] = false;
            path.pop_back();
        }
    }
};