#include <vector>

using namespace std;

/**
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1
 * 。 你可以假设数组中不存在重复的元素。 你的算法时间复杂度必须是 O(log n) 级别.
 */

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }
        if (target <= nums.back())
            r = nums.size() - 1;
        else
            l = 0, r--;

        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target) return -1;
        return l;
    }
};