#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 时间复杂度:O(KN^2)， 可以用二分进行优化
     * 状态表示：dp[i][j]表示有i个鸡蛋，面对j层楼测出F的最少次数
     * 状态计算：如果我在m层仍(1<m<j)，有两种情况，碎了，i-1即鸡蛋少一个，楼层区间变为1~m-1，如果没碎，i不变，楼层区间变为j-m
     */
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) dp[1][i] = i;  // base case
        for (int i = 2; i <= k; i++) {              // 枚举鸡蛋
            for (int j = 1; j <= n; j++) {          // 枚举楼层
                int minV = INT_MAX;
                for (int m = 1; m <= j; m++) {  // 选择从哪个楼层扔
                    // 状态更新
                    minV = min(minV, max(dp[i - 1][m - 1], dp[i][j - m]) + 1);
                }
                dp[i][j] = minV;
            }
        }
        return dp[k][n];
    }

    /**
     * 时间复杂度：O(KN)
     * 空间复杂度：O(KN)
     * 状态表示：dp[i][j]表示用i个鸡蛋和允许j次移动可以“保证求解”的最大楼层。
     * 状态计算：参考解析https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-xiang-jie-by-shellbye/
     */
    int superEggDrop(int k, int n) {
        // vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        // for (int i = 1; i <= n; i++) {
        //     dp[0][i] = 0;
        //     for (int j = 1; j <= k; j++) {
        //         dp[j][i] = dp[j][i - 1] + dp[j - 1][i - 1] + 1;
        //         if (dp[j][i] >= n) return i;
        //     }
        // }
        // return n;

        // 空间优化
        vector<int> dp(k + 1, 1);
        int m = 2;
        dp[0] = 0;
        while (dp[k] < n) {
            for (int i = k; i >= 1; i--) {
                dp[i] = dp[i] + dp[i - 1] + 1;
            }
            m++;
        }
        return m - 1;
    }
};