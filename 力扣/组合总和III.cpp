#include <bits/stdc++.h>

using namespace std;

/**
 * 题目216：组合总数III
 */

class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(k, n, 1, path);
        return res;
    }

    /**
     * 回溯 + 深搜
     */
    void dfs(int k, int n, int idx, vector<int> path) {
        if (k == 0) {
            if (n == 0) res.push_back(path);
            return;
        }
        for (int i = idx; i < 10; i++) {
            if (n >= i) {
                path.push_back(i);
                dfs(k - 1, n - i, i + 1, path);
                path.pop_back();
            }
        }
    }
};