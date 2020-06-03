#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 用一个栈来模拟
     */
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int idx = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);  // 先入栈
            // 判断栈顶元素是否和出栈序列一样，一样则出栈
            while (!stk.empty() && stk.top() == popped[idx]) {
                stk.pop();
                idx++;
            }
        }
        return stk.empty();
    }
};