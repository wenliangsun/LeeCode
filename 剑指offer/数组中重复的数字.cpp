#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 考察哈希表
     */
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto n : nums) {
            hash[n]++;
            if (hash[n] > 1) return n;
        }
        return 0;
    }
};