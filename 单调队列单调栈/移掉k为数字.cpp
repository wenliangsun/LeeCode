#include <bits/stdc++.h>

using namespace std;

/**
 * 题目402：移掉k位数字
 */

class Solution {
   public:
    /**
     * 单调栈
     * 利用栈存储当前迭代数字之前的数字，对于每一个数字，和栈顶元素比较，即该数字的左邻居
     * 如果小于栈顶元素，则出栈。
     * 从左向右依次扫描，如果前一个位置的数字比当前数字大，则把前一个数字删除，如果是递增的话，从最后面删除
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    string removeKdigits(string num, int k) {
        stack<char> stk;
        for (auto c : num) {
            while (k && stk.size() && stk.top() > c) { // 单调递增栈
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        while(k > 0) stk.pop(), k--; // 如果原本就是递增的，则在末尾删除
        string res;
        while (stk.size()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        int idx = 0;
        while (res[idx] == '0') idx++;
        res = res.substr(idx);
        return res == "" ? "0" : res;
    }
};