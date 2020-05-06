#include <bits/stdc++.h>

using namespace std;

/**
 *  题目152：乘积最大的子数组
 * 给你一个整数数组 nums
 * ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
 */

class Solution {
   public:
    /**
     * 思路：因为数组中会有负数出现，所以最大值可能变成最小值，最小值可能变成最大值
     * 因此需要记录最大值和最小值，如果遇到负数，则最大值和最小值交换
     */
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, tmax = 1, tmin = 1;
        for (int i = 0; i < nums.size(); i++) {
            // 遇到负数，最大值和最小值交换
            if (nums[i] < 0) {
                int tmp = tmax;
                tmax = tmin;
                tmin = tmp;
            }
            // 更新最大值
            tmax = max(tmax * nums[i], nums[i]);
            // 更新最小值
            tmin = min(tmin * nums[i], nums[i]);
            // 更新答案
            res = max(res, tmax);
        }
        return res;
    }
};