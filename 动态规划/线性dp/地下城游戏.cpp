#include <bits/stdc++.h>

using namespace std;

/**
 * 地下城游戏
 */

class Solution {
   public:
    /**
     * 从右下到左上状态转移
     * 状态表示：dp[i][j]表示位置i，j到达终点需要的最小初始量
     * 状态计算：dp[i][j] = max(min(dp[i+1][j], dp[i][j+1])- dungeon[i][j], 1)，
     * 当前状态只与dp[i+1][j]和dp[i][j+1]的最小值有关，且需要满足当前位置i，j的初始值达到min-dungeon[i][j], 并保证初始值要大于1
     */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1; // 边界初始化为1
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};