#include <bits/stdc++.h>

using namespace std;

/**
 * 判断子序列
 */

class Solution {
   public:
    // 简单的双指针
    bool isSubsequence(string s, string t) {
        if (s.empty() && t.empty()) return true;
        for (int i = 0, j = 0; j < t.size(); j++) {
            if (t[j] == s[i]) i++;
            if (i == s.size()) return true;
        }
        return false;
    }
};