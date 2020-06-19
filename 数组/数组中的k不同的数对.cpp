#include <bits/stdc++.h>

using namespace std;

/**
 * 题目532：数组中的k不同的数对
 */

class Solution {
   public:
    /**
     * 哈希表
     */
    int findPairs(vector<int>& nums, int k) {
        if (!nums.size() || k < 0) return 0;
        unordered_map<int, int> hash;  // 哈希表去重
        int res = 0;
        for (auto n : nums) hash[n]++;
        if (k == 0) {  // k为0时，统计相同的数字
            for (auto item : hash)
                if (item.second > 1) res++;
        } else {
            // 否则正常统计
            for (auto item : hash) res += hash.count(item.first + k);
        }
        return res;
    }
};