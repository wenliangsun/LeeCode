#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    char firstUniqChar(string s) {
        int a[26] = {0};
        for (auto c : s) a[c - 'a']++;
        for (auto c : s)
            if (a[c - 'a'] == 1) return c;
        return ' ';
    }
};