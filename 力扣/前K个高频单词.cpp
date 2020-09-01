#include <bits/stdc++.h>

using namespace std;

/**
 * 题目692：前K个高频单词
 */

class Solution {
public:
    typedef pair<int, string> PII;
    struct cmp {
        bool operator() (PII a, PII b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    /**
     * 使用优先队列，维护一个小顶堆
     * 时间复杂度：O(nlogk)
     * 空间复杂度：O(n)
     */
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        for (auto w : words) hash[w]++;
        priority_queue<PII, vector<PII>, cmp> q;
        vector<PII> tmp;
        for (auto item : hash) tmp.push_back({item.second, item.first});
        for (auto t : tmp) {
            q.push(t);
            if (q.size() > k) q.pop(); 
        }
        vector<string> res;
        while (q.size()) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};