#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 枚举所有可能的回文中心，总共有2*n-1个
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     */
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        string res;
        for (int i = 0; i < 2 * n - 1; i++) {
            int l = i / 2, r = l + i % 2; // 注意计算左右起点
            while (l >= 0 && r < n && s[l] == s[r]) l--,r++;
            if (r - l - 1 > len) {
                len = r - l - 1;
                res = s.substr(l + 1, len);
            }
        }
        return res;
    }
};