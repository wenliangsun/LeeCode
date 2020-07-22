#include <bits/stdc++.h>

using namespace std;

/**
 * 最短无序连续子数组
 */

class Solution {
   public:
    /**
     * 暴力，枚举区间起点和终点，如果起点和终点不在正确的位置，记录起点和终点的位置。
     * 时间复杂度：O(n^2)
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int l = nums.size(), r = 0;  //记录左边界和右边界
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[i]) {  // 如果不在正确的位置上，更新左右边界
                    l = min(l, i);
                    r = max(r, j);
                }
            }
        }
        return r - l > 0 ? r - l + 1 : 0;
    }

    /**
     * 排序
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(n)
     */
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t(nums);
        sort(t.begin(), t.end());
        int l = nums.size(), r = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != t[i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        return r - l > 0 ? r - l + 1 : 0;
    }

    /**
     * 单调栈
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int l = nums.size(), r = 0;
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            while (stk.size() && nums[stk.top()] > nums[i]) {
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (stk.size() && nums[stk.top()] < nums[i]) {
                r = max(r, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return r - l > 0 ? r - l + 1 : 0;
    }
};