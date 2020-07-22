#include <bits/stdc++.h>

using namespace std;

/**
 * 除自身以外数组的乘积
 */

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int t = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= t;
            t *= nums[i];
        }
        t = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= t;
            t *= nums[i];
        }
        return res;
    }
};