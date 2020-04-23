
/**
 * 题目70：爬楼梯
 */
class LeeCode70 {
   public:
    /**
     * 思路：递归法 自顶向下
     * 有很多重复计算，时间复杂度很高
     */
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    /**
     * 思路：自底向上，保留中间结果
     */
    int climbStairs2(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            int n_clb = 0;
            int clb1 = 1;
            int clb2 = 2;
            for (int i = 3; i <= n; i++) {
                n_clb = clb1 + clb2;
                clb1 = clb2;
                clb2 = n_clb;
            }
            return n_clb;
        }
    }

    /**
     * 思路：动态规划
     * 状态转移方程：dp[i] = dp[i-1] + dp[i-2]
     */
    int climbStairs3(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};