#include <bits/stdc++.h>

using namespace std;

/**
 * 最长回文子串
 */

class Solution {
   public:
    /**
     * 中心扩展法
     * 时间复杂度：O(n^2)
     */
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        int len = 0;
        // 枚举所有可能的中心点
        for (int i = 0; i < 2 * n - 1; i++) {
            int l = i / 2, r = l + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) l--, r++;
            if (r - l - 1 > len) {
                len = r - l - 1;
                res = s.substr(l + 1, len);
            }
        }
        return res;
    }
};