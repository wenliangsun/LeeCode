#include <bits/stdc++.h>

using namespace std;

/**
 * 题目643：子数组最大平均数I
 */

class Solution {
   public:
    /**
     * 滑动窗口
     * 求给定区间中和的最大值
     */
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, res;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        res = sum;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};