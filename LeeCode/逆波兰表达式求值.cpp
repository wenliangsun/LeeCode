#include <bits/stdc++.h>

using namespace std;

/**
 * 题目150：逆波兰表达式求值
 */

class Solution {
   public:
    /**
     * 利用栈的数据结构
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n1, n2;
        for (auto s : tokens) {
            if (s == "+") {
                n1 = stk.top();
                stk.pop();
                n2 = stk.top();
                stk.pop();
                stk.push(n1 + n2);
            } else if (s == "-") {
                n1 = stk.top();
                stk.pop();
                n2 = stk.top();
                stk.pop();
                stk.push(n2 - n1);
            } else if (s == "*") {
                n1 = stk.top();
                stk.pop();
                n2 = stk.top();
                stk.pop();
                stk.push(n1 * n2);
            } else if (s == "/") {
                n1 = stk.top();
                stk.pop();
                n2 = stk.top();
                stk.pop();
                stk.push(n2 / n1);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};