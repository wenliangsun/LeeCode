#include <bits/stdc++.h>

using namespace std;

/**
 * 题目416：分割等和子集
 */

class Solution {
   public:
    /**
     * 动态规划，转换成0-1背包问题
     * 样品是所有的数字，背包容量是所有数字和的一半。
     * 状态表示：dp[j] 表示背包容量为j时是否可以装满
     * 状态计算：要么装当前数字，要么不装
     */
    bool canPartition(vector<int>& nums) {
        int w = 0, n = nums.size();
        for (auto t : nums) w += t;  // 计算数字之和
        if (w % 2) return false;     // 不能被2整除，直接返回false
        vector<bool> dp(w / 2 + 1, false);
        dp[0] = true;
        // 0-1背包模板
        for (auto n : nums) {
            for (int j = w / 2; j >= n; j--) {
                dp[j] = dp[j] || dp[j - n];
            }
        }
        return dp[w / 2];
    }
};