#include <bits/stdc++.h>

using namespace std;

/**
 * 最大矩形：力扣85题
 */

class Solution {
   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (!matrix.size() || !matrix[0].size()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        vector<int> dp(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0;
            }
            res = max(res, largestRectangleArea(dp));
        }
        return res;
    }

    /**
     * 单调栈
     */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }
        while (stk.size()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
            stk.push(i);
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, heights[i] * (right[i] -left[i] - 1));
        return res;
    }
};
