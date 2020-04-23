#include <vector>

using namespace std;

/**
 * 题目81：搜索旋转排序数组II
 */
class LeeCode81 {
   public:
    /**
     * 时间复杂度：O(logN)一般情况
     * 最坏情况，O(N)
     */
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target)) {
            return false;
        }
        if (nums.size() == 1 && nums[0] == target) {
            return true;
        }
        int left = 0;
        int right = nums.size() - 1;
        // 这儿考虑了当前排序没有翻转的情况。不会进入下面的循环
        int mid = left;
        // 利用二分搜索的思路 寻找最小的数
        while (nums[left] >= nums[right]) {
            if ((right - left) == 1) {
                mid = right;
                break;
            }
            int mid = left + (right - left) / 2;
            // 如果三个值相等时，无法判断区间，只能暴力查找
            if (nums[left] == nums[mid] && nums[right] == nums[mid]) {
                return findNumber(nums, target);
            }
            if (nums[left] <= nums[mid]) {
                left = mid;
            }
            if (nums[mid] <= nums[right]) {
                right = mid;
            }
        }
        // 判断目标值可能的区间
        if (mid != 0 && target >= nums[0]) {
            left = 0;
            right = mid - 1;
        } else {
            left = mid;
            right = nums.size() - 1;
        }
        // 标准二分查找算法
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

   private:
    /**
     * 暴力查找
     */
    bool findNumber(vector<int> nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return true;
            }
        }
        return false;
    }
};