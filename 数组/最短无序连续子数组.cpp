#include <bits/stdc++.h>

using namespace std;

/**
 * 题目581：最短无序连续子数组
 */

class Solution {
   public:
    /**
     * 排序
     * 时间复杂度：O(nlogn)
     */
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t(nums);
        sort(nums.begin(), nums.end());
        int b = nums.size(), e = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (t[i] != nums[i]) {
                b = min(b, i);
                e = max(e, i);
            }
        }
        return e - b >= 0 ? e - b + 1 : 0;
    }

    /**
     * 单调栈
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int b = nums.size(), e = 0;
        // 寻找左边界
        for (int i = 0; i < nums.size(); i++) {
            while (stk.size() && nums[stk.top()] > nums[i]) {
                b = min(b, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        // 清空栈
        while (stk.size()) stk.pop();
        // 寻找右边界
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (stk.size() && nums[stk.top()] < nums[i]) {
                e = max(e, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return e - b >= 0 ? e - b + 1 : 0;
    }
};