#include <vector>

using namespace std;

/**
 * 题目33：搜寻旋转排序数组
 */
class LeeCode33 {
   public:
    /**
     * 思路：考虑时间复杂度O(logn)
     * (1) 首先利用二分法寻找最小位置
     * (2) 然后在对应的区间利用二分法搜索值
     */
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target)) {
            return -1;
        }
        if (nums.size() == 1 && nums[0] == target) {
            return 0;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = left;
        // 注意寻找最小元素的位置和二分法的差别
        while (nums[left] >= nums[right]) {
            if ((right - left) == 1) {
                mid = right;
                break;
            }
            mid = (left + right) / 2;
            if (nums[left] < nums[mid]) {
                left = mid;
            }
            if (nums[mid] < nums[right]) {
                right = mid;
            }
        }
        // 判断目标值可能的区间 排除未旋转的情况
        if (mid != 0 && target >= nums[0]) {
            left = 0;
            right = mid;
        } else {
            left = mid;
            right = nums.size() - 1;
        }
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;  // 注意这儿，容易陷入死循环
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};