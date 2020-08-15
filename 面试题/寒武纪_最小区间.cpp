#include <bits/stdc++.h>

using namespace std;

/**
 * 题目632：最小区间
 */

class Solution {
   public:
    typedef pair<int, pair<int, int>> PII;
    /**
     * 多指针 + 优先队列
     * 时间复杂度：O(nklogk)
     */
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<PII, vector<PII>, greater<PII>> q;
        int mx = 0;
        // 相当于合并k个排序链表，用优先队列获取最小值，并记录最大值
        for (int i = 0; i < n; i++) {
            q.push({nums[i][0], {i, 0}});
            mx = max(mx, nums[i][0]);
        }
        int l = -1e5, r = 1e5;
        while (q.size() == n) {
            auto t = q.top();
            q.pop();
            int v = t.first, i = t.second.first, j = t.second.second;
            if (mx - v < r - l) l = v, r = mx;
            if (j + 1 < nums[i].size()) {
                q.push({nums[i][j + 1], {i, j + 1}});
                mx = max(mx, nums[i][j + 1]);
            }
        }
        return {l, r};
    }
};