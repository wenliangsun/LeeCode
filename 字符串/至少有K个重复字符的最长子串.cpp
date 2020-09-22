#include <bits/stdc++.h>

using namespace std;

/**
 * 题目395：至少有K个重复字符的最长子串
 */

class Solution {
public:
    /**
     * 分治法
     * 先统计每一个字符在当前串中出现的次数，然后按照次数不满足k的字符进行分割
     * 再在各个区间递归调用，计算满足要求的子串
     */
    int longestSubstring(string s, int k) {
        unordered_map<char, int> hash;
        for (auto c : s) hash[c]++; // 统计每一个字符在当前串中出现的次数
        vector<int> split; // 用于存储不满足字符的位置
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] < k) split.push_back(i);
        }
        if (split.size() == 0) return s.size(); // 当前串是满足的情况
        split.push_back(s.size());
        int res = 0, l = 0;
        for (int i = 0; i < split.size(); i++) {
            int len = split[i] - l;
            if (len > res) res = max(res, longestSubstring(s.substr(l, len), k));
            l = split[i] + 1;
        }
        return res;
    }
};