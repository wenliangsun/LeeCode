#include <bits/stdc++.h>

using namespace std;

/**
 * 题目238：除自身以外数组的乘积
 */
class Solution {
   public:
    /**
     * 思路：先从前向后累乘，然后从后向前累乘
     * 时间复杂度：O(n)
     * 空间复杂度：O(1) 不算答案数组的空间
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int tmp = 1;
        // 从前向后累乘
        for (int i = 1; i < n; i++) {
            tmp *= nums[i - 1];
            res[i] *= tmp;
        }
        tmp = 1;
        // 从后向前累乘
        for (int i = n - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            res[i] *= tmp;
        }
        return res;
    }
};