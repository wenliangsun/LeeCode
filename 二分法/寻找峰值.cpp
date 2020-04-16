#include <vector>

using namespace std;

/**
 * 峰值元素是指其值大于左右相邻值的元素。
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 你可以假设 nums[-1] = nums[n] = -∞。
 *
 * 思路： check(选择)：
 * ：num[mid]>nums[mid+1]则左区间一定存在峰值，否则有区间一定存在峰值
 *
 */

class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] >= nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};