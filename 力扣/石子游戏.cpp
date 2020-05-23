#include <vector>

using namespace std;

/**
 * 题目877：石子游戏
 */
class LeeCode877 {
   public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        // dp数组 [i][j][k] 表示在区间[i,j]中k选手获得的最高分数
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, 0)));
        // base case 当只有一堆石头时，先手拿了后手没有
        for (int i = 0; i < n; i++) {
            dp[i][i][0] = piles[i];
            dp[i][i][1] = 0;
        }
        // 斜着遍历数组，这块最好的是画出状态转移表，然后照着遍历
        // num表示斜着遍历的次数
        for (int num = 1; num < n; num++) {
            // 横坐标
            for (int i = 0; i < n - num; i++) {
                int j = num + i;  // 纵坐标
                // 作为先手，面对[i,j]区间，如果我选择左侧，那么此时面对[i+1,j]但我变成了后手
                int left = piles[i] + dp[i + 1][j][1];
                // 作为先手，面对[i,j]区间，如果我选择右侧，那么此时面对[i,j-1]但我变成了后手
                int right = piles[j] = dp[i][j - 1][1];
                // 因为选手足够聪明，所以选择最多的一种方式
                // 如果先手选择从左侧拿
                if (left > right) {
                    // 先手拿了左侧
                    dp[i][j][0] = left;
                    // 此时后手就变成了先手
                    dp[i][j][1] = dp[i + 1][j][0];
                } else {
                    // 先手拿了右侧
                    dp[i][j][0] = right;
                    // 此时后手就变成了先手
                    dp[i][j][1] = dp[i][j - 1][0];
                }
            }
        }
        return dp[0][n - 1][0] - dp[0][n - 1][1] > 0;
    }
};
