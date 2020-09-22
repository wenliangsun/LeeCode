#include <bits/stdc++.h>

using namespace std;

/**
 * 题目747：最少是其他数字两倍的最大数
 */

class Solution {
   public:
    int dominantIndex(vector<int>& nums) {
        int mx = 0, idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (mx < nums[i]) {
                mx = nums[i];
                idx = i;
            }
        }
        for (auto n : nums) {
            if (n != mx && n * 2 > mx) return -1;
        }
        return idx;
    }
};