#include <bits/stdc++.h>

using namespace std;

/**
 * 整数拆分或剪绳子
 */

class Solution {
   public:
    /**
     * 暴力：遍历当前剪的长度，剩余部分可以选择不剪，也可以选择剪(递归)，取最大情况
     */
    int integerBreak(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, max(i * (n - i), i * integerBreak(n - i)));
        }
        return res;
    }

    /**
     * 备忘录
     */
    int integerBreak(int n) {
        vector<int> memo(n + 1);
        return dfs(n, memo);
    }

    int dfs(int n, vector<int>& memo) {
        if (n == 2) return 1;
        if (memo[n]) return memo[n];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, max(i * (n - i), i * dfs(n - i, memo)));
        }
        memo[n] = res;
        return res;
    }

    /**
     * 动态规划
     * 状态表示：dp[i]表示长度为i的绳子的获得的最大乘积
     * 状态计算：dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]))
     */
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
    /**
     * 当绳子长度很大的时候
     */
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3, mod = 1e9;
        int res = qmi(3, a - 1, mod);  // 可以被3整除的绳子（a-1）最大乘积
        if (b == 0) return res * 3 % mod; // 剩余长度为0直接乘以余出来的3
        if (b == 1) return res * 4 % mod; // 剩余长度为1时，和前面余出来的长度为3的剪成2*2的
        return res * 6 % mod; // 剩余长度为2，则乘以余出来的3。2*3
    }
    // 快速幂
    int qmi(int m, int k, int p) {
        int res = 1 % p, t = m;
        while (k) {
            if (k & 1) res = res * t % p;
            k >>= 1;
            t = t * t % p;
        }
        return res;
    }
};
