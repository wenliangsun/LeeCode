#include <bits/stdc++.h>

using namespace std;

/**
 * 题目164：最大间距
 */

class Solution {
   public:
    /**
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(1)
     */
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            res = max(res, abs(nums[i] - nums[i - 1]));
        }
        return res;
    }

    /**
     * 思考线性时间复杂度的算法
     */
    int maximumGap(vector<int>& nums) {}
};