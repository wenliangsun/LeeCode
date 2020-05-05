#include <bits/stdc++.h>

using namespace std;

/**
 * 题目125：验证回文串
 */

class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (!isNum(s[l]) && l < r) l++;
            while (!isNum(s[r]) && l < r) r--;
            if (toupper(s[l]) != toupper(s[r])) return false;
        }
        return true;
    }

    bool isNum(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'))
            return true;
        return false;
    }
};