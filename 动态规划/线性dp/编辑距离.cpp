#include <bits/stdc++.h>

using namespace std;

/**
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2
 * 所使用的最少操作数 。
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i][j]
     * 表示将第一个字符串的前i个字母，变成第二个字符串的前j个字母的方案
     * 其值是方案的最小值 状态计算：分三种情况
     */
    int minDistance(string w1, string w2) {
        vector<vector<int>> dp(w1.size() + 1, vector<int>(w2.size() + 1));
        for (int i = 0; i <= w1.size(); i++) dp[i][0] = i;
        for (int i = 0; i <= w2.size(); i++) dp[0][i] = i;
        for (int i = 1; i <= w1.size(); i++) {
            for (int j = 1; j <= w2.size(); j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] =
                    min(dp[i][j], dp[i - 1][j - 1] + (w1[i - 1] == w2[j - 1]));
            }
        }
        return dp[w1.size()][w2.size()];
    }
};