#include <bits/stdc++.h>

using namespace std;

/**
 * 题目557：反转字符串中的单词III
 */

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            i = j;
        }
        return s;
    }
};