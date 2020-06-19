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
        for (int i = 1; i < n; i++) {
            t *= nums[i - 1];
            res[i] *= t;
        }
        t = 1;
        // 后面部分的累积
        for (int i = n - 2; i >= 0; i--) {
            t *= nums[i + 1];
            res[i] *= t;
        }
        return res;
    }
};