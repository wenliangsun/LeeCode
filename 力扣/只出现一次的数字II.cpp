#include <bits/stdc++.h>

using namespace std;

/**
 * 题目137：只出现一次的数字II
 */

class Solution {
   public:
    /**
     * 有限状态自动机 位运算
     */
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (auto n : nums) {
            ones = ones ^ n & ~twos;
            twos = twos ^ n & ~ones;
        }
        return ones;
    }
    /**
     * 利用哈希表
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int singleNumber(vector<int>& nums) {
        map<int, int> hash;
        for (auto n : nums) hash[n]++;
        for (auto item : hash)
            if (item.second == 1) return item.first;
    }
};