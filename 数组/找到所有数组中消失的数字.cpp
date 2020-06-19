#include <bits/stdc++.h>

using namespace std;

/**
 * 题目448：找到所有数组中缺失的数字
 */

class Solution {
   public:
    /**
     * 和442题差不多的思路
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums) {
            n = abs(n);
            if (nums[n - 1] > 0) nums[n - 1] = -nums[n - 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};