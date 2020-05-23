#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 */

class LeeCode53 {
   public:
    /**
     * 动态规划
     *
     * dp[i] 表示以i为终点的所有字段，其中的值表示这些子段中的最大值
     * 分析可知，状态计算方程是： dp[i] = max(dp[i-1], 0) + nums[i]
     * 因为只与上一次的状态有关，可以进一步优化空间复杂度为O(1)
     */
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, last = 0;
        for (auto n : nums) {
            int t = max(last, 0) + n;
            res = max(res, t);
            last = t;
        }
        return res;
    }
};