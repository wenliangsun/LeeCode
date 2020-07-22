#include <vector>

using namespace std;

/**
 * 题目34：在排序数组中查找元素的第一个和最后一个位置
 */
class LeeCode34 {
   public:
    /**
     * 思路：对于排序数组首先想到的是二分法
     * 对时间复杂度有要求O(logn)
     * (1) 利用二分法找目标数字在数组中的最左边索引；
     * (2) 利用二分法找
     */
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size()) return {-1, -1};
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        int t = l;
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        return {t, l};
    }
};