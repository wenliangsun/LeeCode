#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。
 */

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty() || nums.back() < target) return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};