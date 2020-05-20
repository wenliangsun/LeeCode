#include <bits/stdc++.h>

using namespace std;

/**
 * 题目454：四数之和II
 */

class Solution {
   public:
    /**
     * 思路很巧妙！！！ 看代码就能懂!!!
     *
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                     vector<int>& D) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto a : A)
            for (auto b : B) m[a + b]++;
        for (auto c : C)
            for (auto d : D) res += m.count(-(c + d)) ? m[-(c + d)] : 0;
        return res;
    }
};