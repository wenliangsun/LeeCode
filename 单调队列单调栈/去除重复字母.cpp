#include <bits/stdc++.h>

using namespace std;

/**
 * 题目316：去除重复字母
 * 和 1081 不同字符的最小子序列一样
 */

class Solution {
   public:
    /**
     * 单调栈
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    string removeDuplicateLetters(string s) {
        if (s.empty()) return s;
        unordered_map<char, int> pos; // 用来存储每个字符最后出现的位置
        unordered_set<char> hash; // 用来记录栈中字符
        stack<int> stk; // 单调递增栈
        int n = s.size();
        for (int i = 0; i < n; i++) pos[s[i]] = i;
        for (int i = 0; i < n; i++) {
            auto c = s[i];
            if (!hash.count(c)) { // 如果栈中不存在当前字符
                // 维护单调递增栈，并保证在之后还有栈顶字母
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