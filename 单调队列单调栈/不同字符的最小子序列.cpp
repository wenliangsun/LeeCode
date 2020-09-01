#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1081：不同字符的最小子序列
 * 和316题一样
 */

class Solution {
public:
    /**
     * 单调栈
     */
    string smallestSubsequence(string text) {
        if (text.empty()) return text;
        unordered_map<char, int> pos;
        unordered_set<char> hash;
        stack<char> stk;
        int n = text.size();
        for (int i = 0; i < n; i++) pos[text[i]] = i;
        for (int i = 0; i < n; i++) {
            auto c = text[i];
            if (!hash.count(c)) {
                while (stk.size() && stk.top() > c && pos[stk.top()] > i) {
                    hash.erase(stk.top());
                    stk.pop();
                }
                stk.push(c);
                hash.insert(c);
            }
        }
        string res;
        while (stk.size()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};