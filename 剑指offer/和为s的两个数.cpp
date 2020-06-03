#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target)
                return {nums[l], nums[r]};
            else if (sum < target)
                l++;
            else
                r--;
        }
        return {-1, -1};
    }
};