#include <bits/stdc++.h>

using namespace std;

/**
 * 题目227：基本计算器II
 */

class Solution {
   public:
    /**
     * 利用栈数据结构  先计算乘除然后全都转换成加法
     */
    int calculate(string s) {
        stack<long long> stk;
        long long res = 0, num = 0;
        char preOps = '+';
        s += "#";  // 给最后添加一个占位符
        for (auto c : s) {
            if (c == ' ') continue;
            if (c >= '0' && c <= '9')
                num = num * 10 + c - '0';
            else {
                if (preOps == '+')
                    stk.push(num);
                else if (preOps == '-')
                    stk.push(-num);
                else if (preOps == '*')
                    stk.top() *= num;
                else
                    stk.top() /= num;
                num = 0, preOps = c;
            }
        }
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};