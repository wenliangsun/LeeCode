#include <bits/stdc++.h>

using namespace std;

/**
 * 题目和剑指offer上的构建乘积数组一样
 */

class Solution {
   public:
    /**
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int t = 1;
        // 前面部分的累积
        for (int i = 0; i < n; i++) {
            res[i] *= t;
            t *= nums[i];
        }
        t = 1;
        // 后面部分的累积
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= t;
            t *= nums[i];
        }
        return res;
    }
};