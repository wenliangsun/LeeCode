#include <bits/stdc++.h>

using namespace std;

/**
 * 题目394：字符串解码
 */

class Solution {
   public:
    /**
     * 栈
     */
    string decodeString(string s) {
        string res;
        stack<int> ns;
        stack<string> ss;
        int n = 0;
        for (auto c : s) {
            // 遇到左括号，数字入栈，当前字符串入栈，然后分别清空
            if (c == '[') {
                ns.push(n);
                ss.push(res);
                n = 0;
                res.clear();
                // 遇到右括号，括号中间的字符串出现了多少次
            } else if (c == ']') {
                int tn = ns.top();  // 次数
                ns.pop();
                auto ts = ss.top();
                ss.pop();
                // res表示当前括号区间的字符串，然后重复tn次
                for (int i = 0; i < tn; i++) ts += res;
                res = ts;
                // 是数字
            } else if (c >= '0' && c <= '9')
                n = n * 10 + c - '0';
            else  // 是字符
                res += c;
        }
        return res;
    }
};