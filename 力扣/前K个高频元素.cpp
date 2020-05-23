#include <bits/stdc++.h>

using namespace std;

/**
 * 题目347：前K个高频元素
 */

class Solution {
   public:
    /**
     * 哈希表 + 堆 (优先队列)
     * 时间复杂度：O(nlogk)
     * 空间复杂度：O(n)
     */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        // 统计次数
        for (auto n : nums) hash[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       less<pair<int, int>>>
            q;
        // 往堆中插入数字
        for (auto item : hash) {
            q.push({item.second, item.first});
        }
        vector<int> res;
        // 取前k个作为答案输出
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};