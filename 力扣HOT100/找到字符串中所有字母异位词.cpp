#include <bits/stdc++.h>

using namespace std;

/**
 * 找到字符串中所有字母异位词
 */

class Solution {
   public:
    /**
     * 滑动窗口
     */
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        unordered_map<char, int> need, window;
        vector<int> res;
        for (auto c : p) need[c]++;
        int l = 0, r = 0, matched = 0;
        while (r < m) {  // 右边界
            char c = s[r];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) matched++;
            }
            r++;
            while (matched == need.size()) {  // 如果匹配，缩小左边界
                if (r - l == p.size()) res.push_back(l);
                char t = s[l];
                if (need.count(t)) {
                    window[t]--;
                    if (window[t] < need[t]) matched--;
                }
                l++;
            }
        }
        return res;
    }
};