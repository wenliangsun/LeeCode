#include <bits/stdc++.h>

using namespace std;

/**
 * 题目268：缺失数字
 */

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++) {
            res ^= nums[i] ^ i;
        }
        return res;
    }
};