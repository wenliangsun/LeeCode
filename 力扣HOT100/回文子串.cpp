#include <bits/stdc++.h>

using namespace std;

/**
 * 题目647：回文子串
 */

class Solution {
   public:
    /**
     * 从中心往两侧延伸
     * 在长度为n的字符串中，可能的回文中心位置有2n-1个：字母，或者两个字母的中心
     * 时间复杂度：O(n^2)
     */
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < 2 * n - 1; i++) {  //枚举每一个可能的回文中心
            int l = i / 2, r = l + i % 2;  // 计算可能的回文中心的位置
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++, l--, r++;
            }
        }
        return res;
    }

    /**
     * 动态规划
     * 状态表示：dp[i][j]表示区间i，j是否是回文
     */
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int j = 0; j < n; j++) {
            dp[j][j] = true;
            res++;
            for (int i = 0; i < j; i++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) res++;
            }
        }
        return res;
    }
};