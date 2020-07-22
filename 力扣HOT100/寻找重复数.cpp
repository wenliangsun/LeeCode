#include <bits/stdc++.h>

using namespace std;

/**
 * 寻找重复数
 */

class Solution {
   public:
    /**
     * 抽屉原理 + 二分法
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            int cnt = 0;
            for (auto x : nums) cnt += l <= x && x <= mid;
            if (cnt > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    /**
     * 双指针，寻找环的入口 和 环形链表很像
     */
    int findDuplicate(vector<int>& nums) {
        int s = 0, f = 0;
        while (true) {
            s = nums[s];
            f = nums[nums[f]];
            if (s == f) break;
        }
        s = 0;
        while (true) {
            s = nums[s];
            f = nums[f];
            if (s == f) break;
        }
        return s;
    }
};