#include <bits/stdc++.h>

using namespace std;

/**
 * 题目81：搜索旋转排序数组II
 */

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        if (!nums.size()) return false;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {// 注意这儿带等号
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[r]) { // 如果中间位置和右边相等，排除右边的重复的，即右指针向左移动
                r--;
                continue;
            }
            if (nums[mid] < nums[r]) { // 右侧区间是有序的
                if (nums[mid] < target && nums[r] >= target) l = mid + 1; // target在当前区间
                else r = mid - 1;
            } else { // 左侧区间是有序的
                if (nums[l] <= target && nums[mid] > target) r = mid - 1; // target在当前区间
                else l = mid + 1;
            }
        }
        return false;
    }
};