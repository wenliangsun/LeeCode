#include <bits/stdc++.h>

using namespace std;

/**
 * 题目628：三个数的最大乘积
 */

class Solution {
   public:
    /**
     * 排序
     * 找出最小的两个数和最大的三个数即可
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(logn)
     */
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[n - 1],
                   nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};