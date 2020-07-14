#include <bits/stdc++.h>

using namespace std;

/**
 * 石子游戏
 */

class Solution {
   public:
    /**
     * Min-Max
     * 博弈类问题
     * 时间复杂度：O(2^n)
     */
    bool stoneGame(vector<int>& piles) {
        return score(piles, 0, piles.size() - 1) > 0;
    }
    // 相对分数 会超时！
    int score(vector<int>& piles, int l, int r) {
        if (l == r) return piles[l];  // 只剩一堆，直接拿走
        // 先手拿左堆和拿右堆中相对分数大的一种情况
        return max(piles[l] - score(piles, l + 1, r),
                   piles[r] - score(piles, l, r - 1));
    }

    // 记忆化搜索 时间复杂度：O(n^2)
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n)); // 记忆数组
        return score(piles, 0, n - 1, memo) > 0;
    }

    int score(vector<int>& piles, int l, int r, vector<vector<int>>& memo) {
        if (l == r) return piles[l];
        if (memo[l][r]) return memo[l][r];
        int res = max(piles[l] - score(piles, l + 1, r, memo),
                   piles[r] - score(piles, l, r - 1, memo));
        memo[l][r] = res;
        return res;
    }

    /**
     * 动态规划
     * 状态表示：dp[i][j]表示i，j区间我可以获得的最大相对分数
     * 状态计算：需要斜着遍历数组
     */
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i ++) dp[i][i] = piles[i];
        for (int l = 2; l <= n; l++) {
            // 斜着遍历数组
            for (int i = 0; i < n - l + 1; i++) { // x坐标
                int j = i + l - 1; // y坐标
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j]- dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }

    // 空间优化
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                dp[i] = max(piles[i] - dp[i + 1], piles[i + l - 1] - dp[i]);
            }
        }
        return dp[0] > 0;
    }

    // 题目给了偶数堆的条件，则先手必赢
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};