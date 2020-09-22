#include <bits/stdc++.h>

using namespace std;

/**
 * 题目491：递增子序列
 */

class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }

    void dfs(vector<int>& nums, int idx, vector<int>& path) {
        if (path.size() > 1) res.push_back(path);
        unordered_set<int> hash; //用于去重
        for (int i = idx; i < nums.size(); i++) {
            if (hash.count(nums[i])) continue; // 去重
            if (!path.size() || path.back() <= nums[i]) {
                path.push_back(nums[i]);
                hash.insert(nums[i]); // 当前值插入到哈希表
                dfs(nums, i + 1, path);
                path.pop_back();
            }
        }
    }
};