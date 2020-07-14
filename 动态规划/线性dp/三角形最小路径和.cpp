#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 */

class Solution {
   public:
    /**
     * 用滚动数组优化空间复杂度
     * 考虑到之和上一层的数组有关，只用2层的数组，即所有的i坐标模2,或者&1两个等价
     * 空间复杂度：O(n)
     */
    int minimumTotal(vector<vector<int>>& g) {
        int n = g.size();
        vector<vector<long long>> dp(2, vector<long long>(n));
        dp[0][0] = g[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i & 1][j] = INT_MAX;
                if (j > 0) dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j - 1] + g[i][j]);
                if (j < i) dp[i & 1][j] = min(dp[i & 1][j], dp[i - 1 & 1][j] + g[i][j]);
            }
        }
        long long res = INT_MAX;
        for (int i = 0; i < n; i++) res = min(res, dp[n - 1 & 1][i]);
        return res;
    }

    /**
     * 状态表示 ：dp[i][j]
     * 表示到达第i层上第j个结点的所有路径集合，其值表示这些路径集合中的最小值
     * 状态计算 ：分为从左上来的和右上来的  左上来的是 dp[i][j] = min(dp[i][j],
     * dp[i-1][j-1]+g[i][j]) 右上来的是 dp[i][j] = min(dp[i][j], dp[i - 1][j] +
     * g[i][j])
     *
     * 空间复杂度：O(n^2)
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