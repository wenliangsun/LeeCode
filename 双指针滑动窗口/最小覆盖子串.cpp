#include <bits/stdc++.h>

using namespace std;

/**
 * 题目76：最小覆盖子串
 */

class Solution {
   public:
    /**
     * 滑动窗口
     */
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto c : t) need[c]++;
        int l = 0, r = 0, idx = 0, mxlen = INT_MAX, matched = 0;
        while (r < s.size()) { // 先移动右指针扩大窗口
            auto c = s[r];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) matched++;
            }
            r++;
            while (matched == need.size()) { // 再移动左指针缩小窗口
                if (r - l < mxlen) {
                    mxlen = r - l;
                    idx = l;
                }
                auto t = s[l];
                if (need.count(t)) {
                    window[t]--;
                    if (window[t] < need[t]) matched--;
                }
                l++;
            }
        }
        return mxlen == INT_MAX ? "" : s.substr(idx, mxlen);
    }
};