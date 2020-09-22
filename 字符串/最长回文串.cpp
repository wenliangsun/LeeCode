#include <bits/stdc++.h>

using namespace std;

/**
 * 题目409：最长回文串
 */

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c]++;
        int res = 0;
        for (auto it : hash) {
            auto t = it.second;
            res += t / 2 * 2;
            if (t % 2 == 1 && res % 2 == 0) res++;
        }
        return res;
    }
};