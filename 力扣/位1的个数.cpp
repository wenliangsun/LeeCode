#include <bits/stdc++.h>

using namespace std;

/**
 * 题目191：位1的个数
 */

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};