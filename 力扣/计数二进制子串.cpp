#include <bits/stdc++.h>

using namespace std;

/**
 * 题目696：计数二进制子串
 */

class Solution {
   public:
    /**
     * 统计相邻的相同的0或1的数量，则满足的子串的数量是相邻两个数量的最小值
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int countBinarySubstrings(string s) {
        int pre = 0, res = 0, idx = 0;
        while (idx < s.size()) {
            auto c = s[idx];
            int cnt = 0;
            while (idx < s.size() && s[idx] == c) cnt++, idx++;
            res += min(pre, cnt);
            pre = cnt;
        }
        return res;
    }
};