#include <bits/stdc++.h>

using namespace std;

/**
 * 滑动窗口的最大值
 * 
 * 单调队列
 */

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 判断队头是否需要出队
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            // 维护一个单调队列
            while (q.size() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            // 判断是否需要添加进结果数组中
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};