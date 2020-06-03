#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 最长无重复子串
     *
     * 滑动窗口
     */
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash[s[i]] > 1) hash[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }
};