#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

    int robRange(vector<int>& nums, int b, int e) {
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i = 0;
        for (int i = b; i <= e; i++) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};