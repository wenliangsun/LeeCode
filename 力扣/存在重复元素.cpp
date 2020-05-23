#include <bits/stdc++.h>

using namespace std;

/**
 * 题目217：存在重复元素
 */

class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        if (!nums.size()) return false;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if (m.count(nums[i]) && m[nums[i]] > 1) return true;
        }
        return false;
    }
};