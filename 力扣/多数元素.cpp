#include <bits/stdc++.h>

using namespace std;

/**
 * 题目169：多数元素
 */

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};