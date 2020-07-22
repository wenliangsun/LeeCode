#include <bits/stdc++.h>

using namespace std;

/**
 * 滑动窗口最大值
 */

class Solution {
   public:
    /**
     * 维护一个单调递减队列
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (q.size() && i - k + 1 > q.front()) q.pop_front(); // 如果窗口大于k，则队头出队
            while (q.size() && nums[q.back()] < nums[i]) q.pop_back(); // 维护单调递减队列
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]); // 窗口满足要求，则入队
        }
        return res;
    }
};