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
     * 
     * 二分模板
     */
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] <= nums.back())
                r = mid;
            else
                l = mid + 1;
        }
        if (target <= nums.back()) {
            r = nums.size() - 1;
        } else {
            l = 0, r--;
        }
        while (l < r) {
            int mid = l + r >> 1;
            if (target <= nums[mid])
                r = mid;
            else
                l = mid + 1;
        }
        return target == nums[l] ? l : -1;
    }
};