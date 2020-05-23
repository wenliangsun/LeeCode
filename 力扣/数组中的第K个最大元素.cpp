#include <bits/stdc++.h>

using namespace std;

/**
 * 题目215：数组中的第K个最大元素
 */

class Solution {
   public:
    /**
     * 思路：直接排序
     */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()), reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }

    /**
     * 其他方法  使用堆
     */
    int findKthLargest(vector<int>& nums, int k){

    }
};