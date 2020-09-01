#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 快排的思想
     * 
     * 时间复杂度：O(n)
     */
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        int idx = -1;
        while (idx != k - 1) {
            int idx = partition(arr, l, r);
            if (idx > k - 1)
                r = idx - 1;
            else if (idx < k - 1)
                l = idx + 1;
            else
                break;
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }

    int partition(vector<int>& nums, int l, int r) {
        int flag = l;
        int idx = l + 1;
        for (int i = idx; i <= r; i++) {
            if (nums[i] < nums[flag]) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[flag], nums[idx - 1]);
        return idx - 1;
    }

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