#include <bits/stdc++.h>

using namespace std;

/**
 * 有序数组中，只有一个数字只出现一次，其余数字出现两次。
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid & 1) mid--; // 保证mid前面的数字是偶数
            // 如果mid和mid+1位置的数相等，则说明mid+1之前的数字是偶数个且两两配对，从mid+2之后的区间查找
            if (nums[mid] == nums[mid + 1]) l = mid + 2;
            else r = mid;
        }
        return nums[l];
    }
};