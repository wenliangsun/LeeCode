#include <vector>

using namespace std;

/**
 * 题目63：不同路径II
 */
class LeeCode63 {
   public:
    /**
     * 思路：动态规划
     * 考虑有障碍的情况
     * 时间复杂度：O(MxN)
     * 空间复杂度：O(MxN) ，空间复杂度可以优化为
     * O(1)，即采用原来的数组作为动态数组
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        int dp[rows][cols];
        dp[0][0] = 1;
        for (int i = 1; i < rows; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = 0;
            }
        }
        for (int i = 1; i < cols; i++) {
            if (obstacleGrid[0][i] == 0) {
                dp[0][i] = dp[0][i - 1];
            } else {
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }

    /**
     * 优化版
     * 空间复杂度：O(1)
     */
    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < rows; i++) {
            if (obstacleGrid[i][0] == 0) {
                obstacleGrid[i][0] = obstacleGrid[i - 1][0];
            } else {
                obstacleGrid[i][0] = 0;
            }
        }
        for (int i = 1; i < cols; i++) {
            if (obstacleGrid[0][i] == 0) {
                obstacleGrid[0][i] = obstacleGrid[0][i - 1];
            } else {
                obstacleGrid[0][i] = 0;
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] =
                        obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }
        return obstacleGrid[rows - 1][cols - 1];
    }
};
