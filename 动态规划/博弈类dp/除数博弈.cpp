#include <bits/stdc++.h>

using namespace std;

/**
 * 题目1025：除数博弈
 */

class Solution {
   public:
    bool divisorGame(int N) {
        if (N == 1) return false;
        if (N == 2) return true;
        vector<bool> dp(N + 1); // dp[i] 表示面对数字i当前玩家的输赢情况
        dp[2] = true;
        for (int i = 3; i <= N; i++) { // 枚举玩家面临的数字
            for (int x = 1; x < i; x++) { // 当前玩家需要选一个满足要求的数字，而且选完之后确保下一轮dp[i-x]玩家输的情况。
                if (!(i % x) && !dp[i - x]) {
                    dp[i] = true; // 则我就会赢
                    break;
                }
            }
        }
        return dp[N];
    }
    /**
     * 归纳法，遇奇则输，遇偶则赢
     */
    bool divisorGame(int N) {
        if (N & 1) return false;
        return true;
    }
};