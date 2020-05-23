#include <bits/stdc++.h>

using namespace std;

/**
 * 有台奇怪的打印机有以下两个特殊要求：打印机每次只能打印同一个字符序列。
 * 每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
 * 给定一个只包含小写英文字母的字符串，你的任务是计算这个打印机打印它需要的最少次数。
 */

class Solution {
   public:
    /**
     * 状态表示：dp[l][r] 表示将区间[l, r]染成最终样子的方式
     * 其值表示最少需要染次数 状态计算：
     * 分两部分，第一部分是只然左端点L,dp[l][r] = dp[l+1, r] + 1。
     * 第二部分是如果第k个位置的颜色和最左端点l的颜色一致，则在然l的时候可以顺带染了，
     * 此时dp[l][r] = min(dp[l][k-1]+dp[k+1][r]) 这儿不需要+1
     * 是因为染l的时候就会顺带染了
     */
    int strangePrinter(string s) {
        int n = s.size();
        if (!n) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        // 枚举区间长度
        for (int len = 1; len <= n; len++) {
            // 枚举左端点
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;          // 计算右端点
                dp[l][r] = dp[l + 1][r] + 1;  // 染最左端点
                // 遍历区间，寻找可被左端点顺带染了的位置
                for (int k = l + 1; k <= r; k++) {
                    if (s[k] == s[l])
                        dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
};