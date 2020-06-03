#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 维护一个单调队列
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // 如果队列不为空，并且窗口滑动到要出队头时
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            // 如果当前元素比队尾元素大，则队尾元素出队
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            q.push_back(i);
            // 窗口符合要求，则取当前的队头元素即为当前窗口的输出结果
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};