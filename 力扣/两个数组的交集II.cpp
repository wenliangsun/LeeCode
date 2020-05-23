#include <bits/stdc++.h>

using namespace std;

/**
 * 题目350： 两个数的交集II
 */

class Solution {
   public:
    /**
     * 哈希表  注意这题的思考！！！
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (auto n : nums1) hash[n]++;
        for (auto n : nums2) {
            if (hash.count(n) && hash[n] > 0) {
                res.push_back(n);
                hash[n]--;
            }
        }
        return res;
    }
};