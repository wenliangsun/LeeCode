#include <bits/stdc++.h>

using namespace std;

/**
 * 每日温度
 */

class Solution {
   public:
    /**
     * 单调栈
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size());
        stack<int> stk;
        for (int i = T.size() - 1; i >= 0; i--) {
            while (!stk.empty() && T[stk.top()] <= T[i]) stk.pop();
            res[i] = stk.empty() ? 0 : stk.top() - i;
            stk.push(i);
        }
        return res;
    }
};