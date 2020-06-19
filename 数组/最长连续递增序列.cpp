#include <bits/stdc++.h>

using namespace std;

/**
 * 题目674：最长连续递增序列
 */

class Solution {
   public:
    /**
     * 滑动窗口
     */
    int findLengthOfLCIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        int res = 1;
        // 遍历起点
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;  // 终点
            int cnt = 1;
            // 如果满足条件，终点右移
            while (j < nums.size() && nums[j] > nums[j - 1]) {
                j++, cnt++;
            }
            res = max(res, cnt);  // 更新答案
        }
        return res;
    }
};