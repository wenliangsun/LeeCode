#include <bits/stdc++.h>

using namespace std;

/**
 * 题目154：寻找旋转排序数组中的最小值II
 */

class Solution {
   public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[r])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r--;
        }
        return nums[l];
    }
};