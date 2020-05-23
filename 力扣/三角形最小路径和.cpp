#include <bits/stdc++.h>

using namespace std;

/**
 * 题目120：三角形最小路径和
 */

class Solution {
   public:
    /**
     * 状态表示 ：dp[i][j]
     * 表示到达第i层上第j个结点的所有路径集合，其值表示这些路径集合中的最小值
     * 状态计算 ：分为从左上来的和右上来的  左上来的是 dp[i][j] = min(dp[i][j],
     * dp[i-1][j-1]+g[i][j]) 右上来的是 dp[i][j] = min(dp[i][j], dp[i - 1][j] +
     * g[i][j])
     */
    int minimumTotal(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<long long>> dp(n, vector<long long>(n));
        dp[0][0] = g[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = INT_MAX;  // 初始化最大
                // 左上来的
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + g[i][j]);
                // 右上来的
                if (j < i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + g[i][j]);
            }
        }
        long long res = INT_MAX;
        // 遍历一遍，求最小
        for (int i = 0; i < n; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};