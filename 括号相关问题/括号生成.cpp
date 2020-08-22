#include <bits/stdc++.h>

using namespace std;

/**
 * 题目22：括号生成
 */

class Solution {
   public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string path;
        dfs(n, n, path); // 做减法
        return res;
    }

    void dfs(int l, int r, string& path) {
        if (l == 0 && r == 0) {
            res.push_back(path);
            return;
        }
        if (l > 0) {
            path.push_back('(');
            dfs(l - 1, r, path);
            path.pop_back();
        }
        if (l < r && r > 0) {
            path.push_back(')');
            dfs(l, r - 1, path);
            path.pop_back();
        }
    }
};