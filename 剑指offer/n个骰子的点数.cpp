#include <bits/stdc++.h>

using namespace std;

/**
 * n个骰子的点数
 */

class Solution {
   public:
    /**
     * 动态规划：
     * 状态表示：dp[i][j]表示第i次掷后出现的点数j的集合，其值是出现点数j的数量
     * 状态计算：dp[i][j] 可以由dp[i-1][j-1]，dp[i-1][j-2]...dp[i-1][j-6]获得
     *
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n^2)
     */
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1));
        for (int i = 1; i <= 6; i++) dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * i; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j > k) dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        int all = pow(6, n);
        vector<double> res;
        for (int i = n; i <= 6 * n; i++) res.push_back(dp[n][i] * 1.0 / all);
        return res;
    }

    /**
     * 优化空间
     * 使用滚动数组优化空间复杂度
     * 空间复杂度：O(n)
     *
     * 还有点问题！！！
     */
    vector<double> twoSum(int n) {
        vector<vector<int>> dp(2, vector<int>(6 * n + 1));
        for (int i = 1; i <= 6; i++) dp[1][i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * i; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j > k) dp[i & 1][j] += dp[(i - 1) & 1][j - k];
                }
            }
        }
        int all = pow(6, n);
        vector<double> res;
        for (int i = n; i <= 6 * n; i++)
            res.push_back(dp[n & 1][i] * 1.0 / all);
        return res;
    }
};