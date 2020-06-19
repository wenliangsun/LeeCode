#include <bits/stdc++.h>

using namespace std;

/**
 * 题目946：验证栈序列
 */

class Solution {
   public:
    /**
     * 模拟题
     */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int idx = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[idx]) {
                stk.pop();
                idx++;
            }
        }
        return stk.empty();
    }
};