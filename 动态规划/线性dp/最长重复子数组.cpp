#include <bits/stdc++.h>

using namespace std;

/**
 * 题目718：最长重复子数组
 */

class Solution {
   public:
    /**
     * 状态表示： dp[i][j] 表示以A的第i个元素和B的第j个元素的结尾的的子数组，其值表示子数组的最长长度
     * 状态计算：如果A[i]==B[j]则dp[i][j] = dp[i-1][j-1] + 1, 否则，dp[i][j] = 0;
     */
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
        int res = 0;
        // 寻找最大长度的子数组
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) res = max(res, dp[i][j]);
        return res;
    }
};