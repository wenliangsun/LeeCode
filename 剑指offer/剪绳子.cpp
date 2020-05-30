#include <bits/stdc++.h>

using namespace std;

/**
 * 爆搜--> 备忘录 --> 动态规划 这种思路来考虑问题
 */

class Solution {
   public:
    /**
     * 暴搜
     * 剪一次可以分为两段，对于第二段，可以选择接着剪，也可以选择不剪，取最大值
     */
    int cuttingRope(int n) {
        if (n == 2) return 1;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, max(i * (n - i), i * cuttingRope(n - i)));
        }
        return res;
    }

    /**
     * 备忘录
     */
    int cuttingRope(int n) {
        vector<int> memo(n + 1, -1);
        return dfs(n, memo);
    }

    int dfs(int n, vector<int>& memo) {
        if (n == 2) return 1;
        if (memo[n] != -1) return memo[n];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, max(i * (n - i), i * dfs(n - i, memo)));
        }
        memo[n] = res;
        return res;
    }

    /**
     * 动态规划
     * 状态表示：dp[i]表示长度为i的绳子的能构成的最大乘积
     * 状态计算：dp[i] = max(i*(i-j),i*dp[i-j])
     * 1<=j<i每次都有两种选择，剩下一段绳子剪或者不剪
     */
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};