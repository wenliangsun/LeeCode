#include <bits/stdc++.h>

using namespace std;

/**
 * 题目242：有效的字母异位词
 */

class Solution {
   public:
    /**
     * 排序
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(1)
     */
    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    /**
     * 采用哈希表
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    bool isAnagram(string s, string t) {
        int cnt[26] = {0};
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        for (auto c : t) {
            cnt[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) return false;
        }
        return true;
    }
};