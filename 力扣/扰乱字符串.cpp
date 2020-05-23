#include <string>

using namespace std;

/**
 * 题目87：扰乱字符串
 */
class LeeCode87 {
   public:
    /**
     * 思路：动态规划
     * 详细介绍见答案 好好理解一下！！！
     * 字符串长度一样，S划分为S1和S2，T也可以划分为T1和T2
     *   (1)情况一：没交换:S1==>T1,S2==>T2
     *   (2)情况二：交换了：S1==>T2 S2==>T1
     */
    bool isScramble(string s1, string s2) {
        // 如果长度不一样，不能变换来
        if (s1.size() != s2.size()) {
            return false;
        }
        bool dp[s1.size()][s2.size()][s1.size() + 1];
        // 初始化动态数组
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                for (int k = 0; k <= s1.size(); k++) {
                    dp[i][j][k] = false;
                }
            }
        }
        // 初始化动态数组的初始值
        // 当长度为1的时候，只需要判断两个字符是否相等即可
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        // 遍历字符串的长度，即枚举区间长度
        for (int s = 2; s <= s1.size(); s++) {
            // 枚举s1中的起点位置
            for (int i = 0; i < s1.size() - s + 1; i++) {
                // 枚举s2中的起点位置
                for (int j = 0; j < s2.size() - s + 1; j++) {
                    // 枚举当前长度的字符串的划分位置
                    for (int k = 1; k < s; k++) {
                        // s1_1和s2_1匹配
                        if (dp[i][j][k] && dp[i + k][j + k][s - k]) {
                            dp[i][j][s] = true;
                            break;
                        }
                        // s1_1 和 s2_2匹配
                        if (dp[i][j + s - k][k] && dp[i + k][j][s - k]) {
                            dp[i][j][s] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0][s1.size()];
    }
};