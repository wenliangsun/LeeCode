#include <bits/stdc++.h>

using namespace std;

/**
 * 柱状图中的最大矩形
 *
 * 单调栈
 */

class Solution {
   public:
    /**
     * 枚举所有柱形的上边界，作为整个矩形的上边界，然后去求左右边界。
     * 1.找出左边离它最近的，比它小的柱形 left
     * 2.找出右边离它最近的，比它小的柱形 right
     */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        // 从左向右遍历，维护一个单调递减的栈
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty())
                left[i] = -1;  // 注意这儿相当于负无穷
            else
                left[i] = stk.top();
            stk.push(i);
        }
        while (stk.size()) stk.pop();  // 需要将栈弹空
        // 向右向左遍历，维护一个单调递减的栈
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty())
                right[i] = n;
            else
                right[i] = stk.top();
            stk.push(i);
        }
        int res = 0;
        // 遍历一次 更新答案
        for (int i = 0; i < n; i++)
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        return res;
    }
};
