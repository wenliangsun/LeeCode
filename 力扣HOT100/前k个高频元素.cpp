#include <bits/stdc++.h>

using namespace std;

/**
 * 前k个高频元素
 */

class Solution {
   public:
    typedef pair<int, int> PII;
    /**
     * 使用堆或优先队列，维护一个大小为k的小顶堆。
     * 时间复杂度：O(nlogk)
     * 空间复杂度：O(n)
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto n : nums) hash[n]++;
        vector<PII> t;
        for (auto item : hash) t.push_back({item.second, item.first});
        priority_queue<PII, vector<PII>, greater<PII>> q;
        for (auto n : t) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        vector<int> res;
        while (q.size()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }

    /**
     * 利用快排的思想
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (auto n : nums) hash[n]++;
        vector<PII> t;
        for (auto item : hash) t.push_back({item.second, item.first});
        int idx = -1, l = 0, r = t.size() - 1;
        while (idx != k - 1) {
            idx = partition(t, l, r);
            if (idx > k - 1)
                r = idx - 1;
            else if (idx < k - 1)
                l = idx + 1;
            else
                break;
        }
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(t[i].second);
        return res;
    }

    int partition(vector<PII>& nums, int l, int r) {
        int flag = l;
        int idx = l + 1;
        for (int i = idx; i <= r; i++) {
            if (nums[i].first > nums[flag].first) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[flag], nums[idx - 1]);
        return idx - 1;
    }
};