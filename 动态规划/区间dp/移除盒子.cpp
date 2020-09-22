#include <bits/stdc++.h>

using namespace std;

/**
 * 题目546：移除盒子
 */

class Solution {
   public:
    vector<vector<vector<int>>> dp; // dp[l][r][k]表示移除区间 [l,r]加上该区间右边等于boxes[r]的k个元素组成的这个序列的最大积分.
    /**
     * 时间复杂度：
     */
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n)));
        return calculate(boxes, 0, n - 1, 0);
    }

    int calculate(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k]) return dp[l][r][k]; //  如果已经计算过了，则直接返回
        while (r > l && boxes[r] == boxes[r - 1]) r--, k++; // 统计右边相等元素的个数，更新区间并更新k
        dp[l][r][k] = calculate(boxes, l, r - 1, 0) + (k + 1) * (k + 1); // l到r区间的积分再加上当前连续的积分
        for (int i = l; i < r; i++) { // 遍历区间，消去中间区间的积分，然后构成连续的序列进行消除
            if (boxes[i] == boxes[r]) { // 如果i和r位置的值相等，则消除i+1到r-1区间，将i和r拼接起来消除。
                dp[l][r][k] = max(dp[l][r][k], calculate(boxes, l, i, k + 1) + calculate(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};