#include <bits/stdc++.h>

using namespace std;

/**
 * 题目303：区域和检索
 */

class NumArray {
   public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum = vector<int>(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) { return sum[j + 1] - sum[i]; }
};