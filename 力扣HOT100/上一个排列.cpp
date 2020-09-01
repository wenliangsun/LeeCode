#include <bits/stdc++.h>

using namespace std;

/**
 * 上一个排列
 */

class Solution {
   public:
    /**
     * 类似于下一个排序
     * 
     * 因为要找上一个排列，所以从后向前遍历找到nums[i]>nums[j]的位置，先将[j,end]区间的数翻转，在区间中找第一个比nums[i]小的数交换
     * 在[j,end]中寻找第一个大于nums[i]的数字的过程可以用二分法优化
     */
    void prevPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos] >= nums[pos - 1]) pos--; // 找位置
        reverse(nums.begin() + pos, nums.end()); // 翻转之后的序列，使之变为降序
        if (pos) { // 条件
            for (int i = pos; i < nums.size(); i++) { // 寻找小于nums[pos-1]的第一个数，因为是降序
                if (nums[i] < nums[pos - 1]) {
                    swap(nums[i], nums[pos - 1]);
                    break;
                }
            }
        }
    }

    /**
     * 使用二分法优化
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void prevPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos] >= nums[pos - 1]) pos--;
        reverse(nums.begin() + pos, nums.end());
        if (pos) {
            int l = pos, r = nums.size() - 1;
            while (l < r) { // 二分查找
                int mid = (l + r) >> 1;
                if (nums[mid] < nums[pos - 1]) r = mid;
                else l = mid + 1;
            }
            swap(nums[l], nums[pos - 1]);
        }
    }
};