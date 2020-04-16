#include <iostream>
#include <vector>

using namespace std;

/**
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
 * 找出给定目标值在数组中的开始位置和结束位置。
 * 时间复杂度要求：O(logn)
 * 如果数组中不存在目标值，返回 [-1, -1].
 */

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        int left = l;

        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        return {left, r};
    }
};
