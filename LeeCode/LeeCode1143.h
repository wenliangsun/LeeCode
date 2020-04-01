#include <string>
#include <vector>
using namespace std;

class LeeCode1143 {
   public:
    /**
     * 思路：动态规划 一般都是采用二维数组
     * (1)dp的含义：dp[i][j]表示s1[1..i]和s2[1...j]他们最长公共子序列
     * (2)base case 两个字符串中只要有一个是""则最长公共子序列为0
     * (3)状态转移方程：就是做选择，即当前字符是否在最长公共子序列中，
     *      如果s1[i]==s2[j]表明这个字符一定是在最长公共子序列中，
     *              dp[i][j] = d[i-1][j-1]+1;
     *      如果s1[i]!=s2[j]表明这两个字符不能同时出现在最长公共子序列中，
     *              dp[i][j] = max(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]) 可简化为
     *              dp[i][j] = max(dp[i-1][j],dp[i][j-1])
     * 总结：对于两个字符串的动态规划问题，一般来说都是构建二维的动态数组，
     * 这样可以比较容易的写出状态转移方程，即当前状态可以由之前的状态推导出来
     */
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};