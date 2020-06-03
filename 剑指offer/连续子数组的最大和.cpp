#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int last = 0, res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int t = max(last, 0) + nums[i];
            res = max(res, t);
            last = t;
        }
        return res;
    }
};