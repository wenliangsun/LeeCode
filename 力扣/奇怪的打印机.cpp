#include <bits/stdc++.h>

using namespace std;

/**
 * 题目664:奇怪的打印机
 */

class Solution {
   public:
    /**
     * 区间dp问题
     *
     * 状态表示：dp[l][r]表示区间[l,r]染成最终样子的方式，其值表示最少需要染的次数
     * 状态计算：分两部分
     * 第一部分只染左端点l，dp[l][r] = dp[l+1][r]+1
     * 第二部分是如果第k个位置的颜色和最左端点l的颜色一致，则在然l的时候可以顺带染了，
     * dp[l][r] = min(dp[l][k-1]+dp[k+1][r]) 这儿不需要+1
     *
     * 时间复杂度：O(n^3)
     */
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // 枚举区间长度
        for (int len = 1; len <= n; len++) {
            // 枚举左端点
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;  // 右端点
                dp[l][r] = dp[l + 1][r] + 1;
                // 遍历区间，寻找可被左端点顺带染了的点
                for (int k = l + 1; k <= r; k++) {
                    if (s[k] == s[l])
                        dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};