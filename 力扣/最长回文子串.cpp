#include <algorithm>
#include <string>

using namespace std;

/**
 * 题目5：最长回文子串
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 */
class LeeCode05 {
   public:
    /**
     * 动态规划方法，自底至上
     */
    string longestPalindrome(string s) {
        int n = s.size(), len = 0;
        string res;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            dp[j][j] = true;
            if (!len) {
                len = 1;
                res = s[0];
            }
            for (int i = 0; i < j; i++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i + 1][j - 1]);
                if (dp[i][j] && len < j - i + 1) {
                    len = j - i + 1;
                    res = s.substr(i, len);
                }
            }
        }
        return res;
    }

    /**
     * 中心扩展法
     */
    string longestPalindrome02(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            // 这样做可以同时处理奇数和偶数的情况
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i + 1);
            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }

   private:
    /**
     * 中心扩展
     */
    string palindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};