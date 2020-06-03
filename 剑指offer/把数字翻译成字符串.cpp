#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int res = 0;
    int translateNum(int num) {
        string s = to_string(num);
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int idx) {
        if (idx == s.size()) {
            res++;
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string cur = s.substr(idx, i - idx + 1);
            if (idx < i && cur[0] == '0') continue;
            int t = stoi(cur);
            if (t > 25) break;
            dfs(s, i + 1);
        }
    }
};