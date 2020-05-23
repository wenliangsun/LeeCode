#include <bits/stdc++.h>

using namespace std;

/**
 * 题目395：至少有k个重复字符的最长子串
 */

class Solution {
   public:
    /**
     * 先用hash表统计s中每个字符出现的次数，显然如果字符c出现的次数小于k，
     * c必然不在最长子串里面，根据这个特性可以将原始s分割成多个子串递归地求解问题，
     * 我们用一个split数组依次来存放每个分割点的索引，对每个分割区间同样求解该问题(多路的分治问题)，
     * 并取结果的最大值保存在变量ans中，此处有一个小trick（如果当前求解的子串长度比已存在的ans还要小，
     * 则没有必要求解该区间，这样可以减少不必要的计算），最后递归的结束点就是当前求解的字符串s符合最长子串的要求。
     */
    int longestSubstring(string s, int k) {
        unordered_map<char, int> hash;
        int res = 0;
        for (auto c : s) hash[c]++;
        vector<int> split;
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i]] < k) split.push_back(i);
        }
        if (split.size() == 0) return s.size();
        int res = 0, l = 0;
        split.push_back(s.size());
        for (int i = 0; i < split.size(); i++) {
            int len = split[i] - l;
            if (len > res)
                res = max(res, longestSubstring(s.substr(l, len), k));
            l = split[i] + 1;
        }
        return res;
    }
};