#include <bits/stdc++.h>

using namespace std;

/**
 * 一和零
 */

class Solution {
   public:
    /**
     * 转换为0-1背包问题
     * 状态表示：dp[i][j]表示i个0和j个1能构成的最多字符串
     */
    typedef pair<int, int> PII;
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (auto s : strs) { // 枚举每一个物品
            PII t;
            cnt(s, t); // 计算物品的每一部分（0和1）的体积(数量)
            // 0-1背包问题的模板
            for (int i = m; i >= t.first; i--) {
                for (int j = n; j >= t.second; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - t.first][j - t.second] + 1);
                }
            }
        }
        return dp[m][n];
    }
    // 统计当前物品的容量
    void cnt(string& s, PII& t) {
        int n0 = 0, n1 = 0;
        for (auto c : s) {
            if (c == '0')
                n0++;
            else
                n1++;
        }
        t.first = n0, t.second = n1;
    }
};