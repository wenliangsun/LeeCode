#include <bits/stdc++.h>

using namespace std;

/**
 * 题目219：存在重复元素II
 */

class Solution {
   public:
    /**
     * 哈希表 维护一个长度为k的哈希表
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.count(nums[i])) return true;
            st.insert(nums[i]);
            if (st.size() > k) {
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};