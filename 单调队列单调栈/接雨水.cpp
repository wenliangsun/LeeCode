#include <bits/stdc++.h>

using namespace std;

/**
 * 接雨水
 *
 * 单调栈
 */

class Solution {
   public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < height.size(); i++) {
            int last = 0;  // 记录之前的高度
            // 维护一个单调递减栈
            while (stk.size() && height[stk.top()] <= height[i]) {
                int t = stk.top();
                stk.pop();
                // 当前层的雨水
                res += (height[t] - last) * (i - t - 1);
                last = height[t];  // 之前的高度更新为当前高度
            }
            // 右边墙低于左边墙的情况
            if (stk.size()) res += (height[i] - last) * (i - stk.top() - 1);
            stk.push(i);
        }
        return res;
    }
};