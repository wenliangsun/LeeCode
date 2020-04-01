#include <string>

using namespace std;

/**
 * 题目10：正则表达式匹配
 */
class LeeCode10 {
   public:
    /**
     * 思路：回溯法
     */
    bool isMatch(string s, string p) { return match(s, 0, p, 0); }

    /**
     * 思路：动态规划
     */
    bool isMatch02(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        // 初始化动态数组
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= p.size(); j++) {
                dp[i][j] = false;
            }
        }
        // 0,0 位表示s和p都是空字符串时
        dp[0][0] = true;  // "" 和 "" 是 true
        // 初始化 "" 和a*a*a*a*a*这种匹配，其他的都是false
        // 奇数位不管是什么字符都是false，偶数位为*时则为下式值。
        for (int i = 2; i <= p.size(); i += 2) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < p.size(); j++) {
                // 如果当前字符匹配，则最终匹配结果由之前的匹配结果决定，当前是i+1,j+1的原因是动态数组的0,0位记录的是空字符
                if (p[j] == '.' || p[j] == s[i]) {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                // 如果当前匹配字符串的字符是'*',分两种情况，字符串当前字符和'*'之前的字符匹配/不匹配
                if (p[j] == '*') {
                    // 字符串当前字符和'*'之前的字符不匹配，只能让*之前的字符消失。
                    if (p[j - 1] != s[i] && p[j - 1] != '.') {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                        // 若匹配，分三种情况：多个字符匹配情况；单个字符匹配的情况；没有匹配的情况
                    } else {
                        dp[i + 1][j + 1] =
                            dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
                    }
                }
            }
        }

        return dp[s.size()][p.size()];
    }

   private:
    /**
     * 回溯法（递归法）：时间复杂度高，空间内存占用率高
     */
    bool match(string s, int sIndex, string p, int pIndex) {
        // 当两个字符串都匹配完了，则表明匹配成功
        if (sIndex == s.size() && pIndex == p.size()) {
            return true;
        }
        // 当模式的字符串没有了，则匹配失败
        if (sIndex < s.size() && pIndex == p.size()) {
            return false;
        }
        // 分两种情况:
        // 模式串的下一个字符是 "*"
        if ((pIndex + 1) < p.size() && p[pIndex + 1] == '*') {
            // 匹配当前索引的两个字符，若匹配成功，则有三种情况
            if ((sIndex < s.size() && s[sIndex] == p[pIndex]) ||
                (p[pIndex] == '.' && sIndex < s.size())) {
                return match(s, sIndex + 1, p, pIndex) ||
                       match(s, sIndex + 1, p, pIndex + 2) ||
                       match(s, sIndex, p, pIndex + 2);
                // 若匹配失败，则模式串中的当前字符出现0次，匹配字符串和匹配串中的下一个字符
            } else {
                return match(s, sIndex, p, pIndex + 2);
            }
        }
        // 模式串中的下一个字符不是 "*"
        if ((sIndex < s.size() && s[sIndex] == p[pIndex]) ||
            (p[pIndex] == '.' && sIndex < s.size())) {
            return match(s, sIndex + 1, p, pIndex + 1);
        }
        return false;
    }
};