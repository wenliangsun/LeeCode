#include <bits/stdc++.h>

using namespace std;

/**
 * 题目239：滑动窗口的最大值
 */
class LeeCode239 {
   public:
    /**
     * 思路：维护一个单调队列
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++) {
            // 队列不为空，并且窗口滑动到需要出队头，则队头出队
            if (q.size() && i - k + 1 > q.front()) q.pop_front();
            // 如果队尾元素小于等于当前元素，则队尾元素出队
            while (q.size() && nums[q.back()] <= nums[i]) q.pop_back();
            // 否则将当前元素入队
            q.push_back(i);
            // 如果窗口大小达到k了，则开始输出结果
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};