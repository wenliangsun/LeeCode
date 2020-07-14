#include <bits/stdc++.h>

using namespace std;

/**
 * 回文子串
 */

class Solution {
   public:
    /**
     * 中心扩展法
     * 枚举每一个可能的中心位置，长度为n的字符串，有2*n-1个中心，然后向两边扩展
     */
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            int l = i / 2, r = l + i % 2;  // 注意这儿求中心位置的方法
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++, r--, l++;
            }
        }
        return res;
    }
    /**
     * 动态规划
     * 状态表示：dp[i][j]表示字符串i到j的子串是否是回文串
     * 状态计算：见代码
     */
    int countSubstrings(string s) {
        int res = 0, n = s.size();
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