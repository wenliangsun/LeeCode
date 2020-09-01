#include <bits/stdc++.h>

using namespace std;

/**
 * 题目541：反转字符串II
 */

class Solution {
   public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n;) {
            if (i + k >= n)
                reverse(s.begin() + i, s.end());
            else
                reverse(s.begin() + i, s.begin() + i + k);
            i += 2 * k;
        }
        return s;
    }
};