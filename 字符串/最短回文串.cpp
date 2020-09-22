#include <bits/stdc++.h>

using namespace std;

/**
 * 题目214：最短回文串
 */

class Solution {
   public:
    /**
     * 思路：找最长回文前缀，然后把剩余的后缀翻转之后加到前缀上即可
     * 可以暴力找，但是会超时
     * 采用KMP算法找。源串作为模式串，翻转的串作为字符串，
     * 匹配完翻转的字符串后模式串中匹配的位置前面的即为最长回文前缀
     */
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; i++) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) j = fail[j];
            if (s[j + 1] == s[i]) fail[i] = j + 1;
        }

        int match = -1;
        for (int i = n - 1; i >= 0; --i) { // 这儿倒着遍历相当于翻转
            while (match != -1 && s[match + 1] != s[i]) match = fail[match];
            if (s[match + 1] == s[i]) match++;
        }
        string t = match == n - 1 ? "" : s.substr(match + 1);
        reverse(t.begin(), t.end());
        return t + s;
    }
};