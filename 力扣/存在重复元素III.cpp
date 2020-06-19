#include <bits/stdc++.h>

using namespace std;

/**
 * 题目220：存在重复元素III
 */

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(nums[i]) && abs(nums[hash[nums[i]]] - nums[i]) <= t)
                return true;
            hash[nums[i]] = i;
            if (hash.size() > k) hash.erase(nums[i - k]);
        }
        return false;
    }
};