#include <bits/stdc++.h>

using namespace std;

/**
 * 题目713：乘积小于k的子数组
 */

class Solution {
   public:
    /**
     * 滑动窗口
     * 每次都保证窗口区间的乘积是小于k的，那么窗口中的子数组都是满足条件的。
     */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        // s记录区间的乘积
        int l = 0, r = 0, s = 1, res = 0;
        while (r < nums.size()) {
            s *= nums[r];
            r++;
            // 如果区间的乘积大于k，则向右移动左指针
            while (l < nums.size() && s >= k) s /= nums[l++];
            // 累加满足的子区间个数，统计的是以右指针为终点的子区间，其余的区间之前已经统计过了
            if (l <= r) res += r - l;
        }
        return res;
    }
};