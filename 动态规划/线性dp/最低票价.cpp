#include <bits/stdc++.h>

using namespace std;

/**
 * 最低票价
 */

class Solution {
   public:
    /**
     * 从前向后计算
     * 状态表示：dp[i]表示到第i天所用的最小花费
     * 状态计算：dp[i] = min(dp[i-1] + costs[0], dp[i-7] + costs[1], dp[i-30] +
     * costs[2]) 当第i天是需要出行的时候，否则dp[i] = dp[i-1]
     */
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int last = days[n - 1]; // 出行的最后一天
        vector<int> dp(last + 1); // 状态数组
        int idx = 0;
        for (int i = 1; i <= last; i++) {
            if (i == days[idx]) { // 当前天需要出行
                int cst = INT_MAX;
                int t1 = i - 1;
                int t7 = i - 7 > 0 ? i - 7 : 0;
                int t30 = i - 30 > 0 ? i - 30 : 0;
                cst = min(dp[t1] + costs[0], cst);
                cst = min(dp[t7] + costs[1], cst);
                cst = min(dp[t30] + costs[2], cst);
                dp[i] = cst;
                idx++;
            } else // 不需要出行
                dp[i] = dp[i - 1];
        }
        return dp[last];
    }
};