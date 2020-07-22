#include <bits/stdc++.h>

using namespace std;

/**
 * 乘积最大子数组
 */

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dpmax[i]表示到i位置最大的乘积，dpmin[i]表示到i位置最小的乘积
     * 状态计算: 见代码
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpmax(nums), dpmin(nums); // dpmax和dpmin分别记录最大值和最小值
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) { // 如果当前数是正数，则正常计算
                dpmax[i] = max(dpmax[i - 1] * nums[i], nums[i]);
                dpmin[i] = min(dpmin[i - 1] * nums[i], nums[i]);
            } else { // 如果当前数是负数，则最大数变最小数，最小数变最大数 
                dpmax[i] = max(dpmin[i - 1] * nums[i], nums[i]);
                dpmin[i] = min(dpmax[i - 1] * nums[i], nums[i]);
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            res = max(res, max(dpmax[i], dpmin[i]));
        }
        return res;
    }

    /**
     * 空间优化
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minV = 1, maxV = 1, res = INT_MIN;
        for (auto n : nums) {
            if (n < 0) {
                int t = maxV;
                maxV = minV;
                minV = t;
            }
            maxV = max(maxV * n, n);
            minV = min(minV * n, n);
            res = max(res, maxV);
        }
        return res;
    }
};