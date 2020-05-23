#include <string>
#include <vector>

using namespace std;

/**
 * 题目516：最长回文子序列
 */
class LeeCode516 {
   public:
    /**
     * 思路：动态规划
     */
    int longestPalindromeSubseq(string s) {
        // 表示字符串中i-j区间的最长回文子序列
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // base case
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        // 由于i大于等于j，所以需要反着遍历或斜着遍历
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                //如果当前字符相等，则当前最长回文子序列是前面的长度上+2
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    // 如果不相等，说明这两个字符不能同时出现的区间，分别将字符加到原来的区间，取其中较大者
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};