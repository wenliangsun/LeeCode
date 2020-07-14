#include <bits/stdc++.h>

using namespace std;

/**
 * 题目746：使用最小花费爬楼梯
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i] 表示到达i层时花费的总和
     * 状态计算：dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]) 
     * 当前位置花费为从当年位置爬需要的花费和从前面当当前位置的花费之和
     */
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            // cost[i] 表示从当前位置爬需要的花费，min(dp[i-1], dp[i-2]) 表示到达当前位置需要的最小花费(可以跳一阶到达，也可以是跳两节到达)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        // 最后取倒数第一阶和倒数第二阶中的最小值，因为可以从倒数第二阶可以直接跳到最后
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }

    /**
     * 空间优化版
     */
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 1) return cost[0];
        int a = cost[0], b = cost[1];
        for (int i = 2; i < n; i++) {
            int t = cost[i] + min(a, b);
            a = b, b = t;
        }
        return min(a, b);
    }
};