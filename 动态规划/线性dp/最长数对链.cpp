#include <bits/stdc++.h>

using namespace std;

/**
 * 最长数对链
 */

class Solution {
   public:
    /**
     * 套了个壳子的最长增长子序列
     * 状态表示：dp[i]表示以i位置结尾的子序列，值为最大长度
     * 状态计算：dp[i] = max(dp[i], dp[j] + 1) pairs[j] < pairs[i]
     * 时间复杂度：O(n^2 + nlogn)
     */
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, dp[i]);
        return res;
    }
};