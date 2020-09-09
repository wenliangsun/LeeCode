#include <bits/stdc++.h>

using namespace std;

/**
 * 其实就是组合总和
 */

class Solution {
   public:
    vector<vector<int>> res;
    /**
     * 回溯法
     */
    vector<vector<int>> combinationSum(int n) {
        vector<int> path;
        dfs(n, n, 1, path);
        return res;
    }

    void dfs(int n, int target, int idx, vector<int>& path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = idx; i <= n; i++) {
            if (target >= i) {
                path.push_back(i);
                dfs(n, target - i, i, path);
                path.pop_back();
            }
        }
    }
};

int main() {
    int n = 4;
    Solution s = Solution();
    vector<vector<int>> res = s.combinationSum(n);
    for (int i = 0; i < res.size(); i++) {
        for (auto n : res[i]) cout << n << ' ';
        cout << endl;
    }
    
    return 0;
}