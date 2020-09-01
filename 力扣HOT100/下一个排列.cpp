#include <bits/stdc++.h>

using namespace std;

/**
 * 下一个排列
 */

class Solution {
   public:
    /**
     * 因为要找下一个排列，所以从后向前遍历找到nums[i]<nums[j]的位置，i的位置需要交换一个[j,end]里面比它大的数里面的最小的一个，
     * 此时i之后的数字是降序，通过reverse把它转换成升序即得到答案。
     * 在[j,end]中寻找第一个大于nums[i]的数字的过程可以用二分法优化
     */
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos] <= nums[pos - 1]) pos--; // 找位置
        reverse(nums.begin() + pos, nums.end()); // 翻转之后的序列，使之变为升序
        if (pos) { // 条件
            for (int i = pos; i < nums.size(); i++) { // 寻找大于nums[pos]的第一个数，因为是升序
                if (nums[i] > nums[pos - 1]) {
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
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos] <= nums[pos - 1]) pos--;
        reverse(nums.begin() + pos, nums.end());
        if (pos) {
            int l = pos, r = nums.size() - 1;
            while (l < r) { // 二分查找
                int mid = (l + r) >> 1;
                if (nums[mid] > nums[pos - 1]) r = mid;
                else l = mid + 1;
            }
            swap(nums[l], nums[pos - 1]);
        }
    }
};