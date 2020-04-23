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
        vector<int> res;
        int left = getFirstTarget(nums, target);
        int right = getLastTarget(nums, target);
        res.push_back(left);
        res.push_back(right);
        return res;
    }

   private:
    int getFirstTarget(vector<int> nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            // 不直接相加是为了防止相加时候溢出
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // 注意这儿的技巧！！！
        if (left >= nums.size() || nums[left] != target) {
            return -1;
        }
        return left;
    }

    int getLastTarget(vector<int> nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = left + 1;
            } else {
                right = mid - 1;
            }
        }
        // 注意这儿的技巧！！！
        if (right < 0 || nums[right] != target) {
            return -1;
        }
        return right;
    }
};