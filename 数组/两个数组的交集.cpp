#include <bits/stdc++.h>

using namespace std;

/**
 * 两个数组的交集
 */

class Solution {
   public:
    /**
     * 两个set
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2;
        for (auto n : nums2) {
            if (st1.count(n)) st2.insert(n);
        }
        return vector<int>(st2.begin(), st2.end());
    }
};