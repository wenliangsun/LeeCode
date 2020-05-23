#include <bits/stdc++.h>

using namespace std;

/**
 * 题目187：重复的DNA序列
 */

class Solution {
   public:
    /**
     * 哈希表
     */
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 10) return res;
        unordered_map<string, int> hash;
        for (int i = 0; i < s.size() - 10 + 1; i++) {
            string t = s.substr(i, 10);
            if (hash.count(t) && hash[t] == 1) res.push_back(t);
            hash[t]++;
        }
        return res;
    }
};