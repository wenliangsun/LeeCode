#include <bits/stdc++.h>

using namespace std;

/**
 * 题目387：字符串中的第一个唯一的字符
 */

class Solution {
   public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c]++;
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] == 1) return i;
        }
        return -1;
    }
};