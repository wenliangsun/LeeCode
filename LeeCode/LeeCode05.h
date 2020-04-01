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
        if (s.empty() || s.size() == 1) {
            return s;
        }
        bool temp[s.size() + 1][s.size() + 1];  // 记录数组
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= s.size(); j++) {
                temp[i][j] = false;
            }
        }
        int maxlen = 0;  // 最大长度
        string res;      // 最长回文
        for (int i = 0; i < s.size(); i++) {
            temp[i][i] = true;  // 每一个单个字符都是回文
            if (maxlen == 0) {  //设置初始回文和长度。
                res = s[i];
                maxlen = 1;
            }
            for (int j = 0; j < i; j++) {  // 表示当前字符串的长度
                // 判断是否是回文!!!
                temp[j][i] =
                    (s[i] == s[j] && (i - j < 2 || temp[j + 1][i - 1]));
                if (temp[j][i]) {  // 如果是回文，更新回文长度
                    maxlen = max(maxlen, i - j + 1);
                    res = s.substr(j, maxlen);
                }
                cout << res << endl;
            }
        }
    }

    /**
     * 最长公共子串法
     */
    string longestPalindrome02(string s) {}

    /**
     * 中心扩展法
     */
    string longestPalindrome03(string s) {
        
    }

    /**
     * Manacher 法
     */
    string longestPalindrome04(string s){

    }
};