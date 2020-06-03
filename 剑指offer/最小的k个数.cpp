#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 优先队列 求解topk问题
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        vector<int> res;
        for (auto n : arr) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        while (q.size()) {
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};