#include <bits/stdc++.h>

using namespace std;

/**
 * 题目451：根据字符串出现的频率排序
 */

class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        priority_queue<pair<int, char>> q;
        for (auto c : s) hash[c]++;
        for (auto item : hash) q.push({item.second, item.first});
        string res;
        while (q.size()) {
            auto item = q.top();
            q.pop();
            string s(item.first, item.second);
            res += s;
        }
        return res;
    }
};