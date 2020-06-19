#include <bits/stdc++.h>

using namespace std;

/**
 * 题目837：新21点
 * 不懂。。。
 */

class Solution {
   public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1;
        if (N == 0 || K > N) return 0;
        vector<double> dp(N + 1, 0);
        dp[0] = 1.0;
        double sum = 1.0, res = 0.0;
        for (int i = 1; i <= N; i++) {
            dp[i] = 1.0 * sum / W;
            if (i < K)
                sum += dp[i];
            else
                res += dp[i];
            if (i >= W) sum -= dp[i - W];
        }
        return res;
    }
};