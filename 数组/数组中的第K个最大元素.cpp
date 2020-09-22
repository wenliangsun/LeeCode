#include <bits/stdc++.h>

using namespace std;

/**
 * 题目215：数组中的第K个最大元素
 */

class Solution {
   public:
    /**
     * 思路：直接排序
     */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()), reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }

    /**
     * 使用堆
     */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto n : nums) {
            if (q.size() < k)
                q.push(n);
            else {
                if (q.size() && q.top() < n) q.pop(), q.push(n);
            }
        }
        return q.top();
    }
};