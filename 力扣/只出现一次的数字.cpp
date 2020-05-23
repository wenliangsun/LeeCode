#include <bits/stdc++.h>

using namespace std;

/**
 * 题目136：只出现一次的数字
 */

class Solution {
   public:
    // 异或操作，因为除了一个数字外，其他的数字都出现了两次，所以异或之后会抵消，最终只留下出现一次的数字
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto n : nums) {
            res ^= n;
        }
        return res;
    }
};