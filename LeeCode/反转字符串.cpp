#include <bits/stdc++.h>

using namespace std;

/**
 * 题目344：反转字符串
 */

class Solution {
   public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++, r--;
        }
    }
};