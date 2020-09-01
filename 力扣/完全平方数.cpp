#include <bits/stdc++.h>

using namespace std;

/**
 *  题目279：完全平方数
 */

class Solution {
   public:
    /**
     * 动态规划
     * 时间复杂度：O(nsqrt(n))
     * 空间复杂度：O(n)
     */
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) dp[i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = sqrt(i); j >= 1; j--) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }

    // 广搜
    int numSquares(int n) {
        queue<int> q;
        vector<int> dist(n + 1, INT_MAX);  // 0点到n点的距离
        q.push(0);
        dist[0] = 0;
        while (q.size()) {
            int t = q.front();
            q.pop();
            if (t == n) return dist[t];
            for (int i = 1; t + i * i <= n; i++) {
                int j = t + i * i;
                // 更新距离
                if (dist[j] > dist[t] + 1) {
                    dist[j] = dist[t] + 1;
                    q.push(j);
                }
            }
        }
        return 0;
    }
};