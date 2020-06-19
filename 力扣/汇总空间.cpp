#include <bits/stdc++.h>

using namespace std;

/**
 * 题目228：汇总区间
 */

class Solution {
   public:
    /**
     * 双指针
     * 注意最后需要再特殊处理一下
     */
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (!nums.size()) return res;
        int l = 0, r = 0, idx = 0; // idx记录递增数
        while (r < nums.size()) {
            if (nums[r] != nums[l] + idx) {
                if (l != r - 1)
                    res.push_back(to_string(nums[l]) + "->" +
                                  to_string(nums[r - 1]));
                else
                    res.push_back(to_string(nums[l]));
                l = r;
                idx = 0;
            }
            r++;
            idx++;
        }
        if (l != r - 1)
            res.push_back(to_string(nums[l]) + "->" + to_string(nums[r - 1]));
        else
            res.push_back(to_string(nums[l]));
        return res;
    }
};