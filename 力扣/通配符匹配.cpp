#include <string>

using namespace std;

/**
 * 题目44：通配符匹配
 */
class LeeCode44 {
   public:
    /**
     * 思路：动态规划
     * dp[i][j]： 动态数组表示字符串的前i和字符和模式的前j个字符是否匹配。
     * (1) 如果当前模式字符是'?'或者模式字符和字符串中当前字符相同时：
     *      dp[i][j]=dp[i-1][j-1] 即当前匹配的结果由之前匹配的结果决定。
     * (2) 如果当前模式字符是'*'，则有两种情况：
     *      1)'*' 匹配单个字符，则: dp[i][j] = dp[i-1][j-1];
     *      2)'*' 匹配多个字符，则：dp[i][j] = dp[i-1][j];
     *      3)'*' 匹配空字符，则：dp[i][j] = dp[i][j-1];
     * 时间复杂度：O(SP)
     * 空间复杂度：O(SP)
     */
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= p.size(); j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;  // 初始化 ""和""匹配
        // 初始化动态数组中的第一行即匹配空串的情况!!!
        for (int i = 0; i < p.size(); i++) {
            dp[0][i + 1] = p[i] == '*' && dp[0][i];
        }
        //遍历 注意索引！！！
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                // 如果字符串字符与模式字符匹配
                if (s[i] == p[j] || p[j] == '?') {
                    dp[i + 1][j + 1] = dp[i][j];
                    // 如果模式字符是'*'，匹配一个字符，匹配多个字符，匹配空字符
                } else if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i][j] || dp[i][j + 1] || dp[i + 1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }

    /**
     * 思路：双指针贪心方法
     */
    bool isMatch2(string s, string p) {}

    /**
     * 思路：回溯法
     */
    bool isMatch3(string s, string p) {}

    /**
     * 思路：递归
     */
    bool isMatch4(string s, string p) {}
};