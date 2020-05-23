#include <bits/stdc++.h>

using namespace std;

/**
 * 解码方法
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i]表示到位置i的解码方案的集合，其值为方案数
     * 状态转移：最后一个解码分为由一个数字解码获得，和由两个数字解码获得。具体见代码
     */
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            // 由一个数字解码获得
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2) {
                int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                // 由两个数字解码获得 需要判断一下能否使用两个数字解码
                if (t >= 10 && t <= 26) dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};