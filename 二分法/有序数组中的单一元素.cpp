#include <bits/stdc++.h>

using namespace std;

/**
 * 题目540：有序数组中的单一元素
 */

class Solution {
public:
    /**
     * 二分法
     * 每次从奇数个数的子区间查找
     * 时间复杂度：O(logn)
     * 空间复杂度：O(1)
     */
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid & 1) mid--; // 保证mid之前是偶数个数
            // 如果mid和mid+1位置的数相等，则说明mid+1之前的数字是偶数个且两两配对，从mid+2之后的区间查找
            if (nums[mid] == nums[mid + 1]) 
                l = mid + 2; 
            else 
                r = mid;
        }
        return nums[l];
    }
};