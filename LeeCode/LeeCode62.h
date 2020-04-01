
/**
 * 题目62：不同路径
 */
class LeeCode62 {
   public:
    /**
     * 递归法，因为有许多的重复计算，会超时
     */
    int uniquePaths(int m, int n) {
        int res = 0;
        findPath(m, n, res);
        return res;
    }

    /**
     * 动态规划
     * dp[i][j] = dp[i-1][j]+dp[i][j-1] 表示当前位置有多少种路径
     */
    int uniquePaths2(int m, int n) {
        int dp[m][n];
        // 初始化边界
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        // 初始化
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 数组更新
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // 返回的值注意一下！！！
        return dp[m - 1][n - 1];
    }

   private:
    /**
     * 递归求解
     */
    void findPath(int m, int n, int& res) {
        if (m == 1 && n == 1) {
            res++;
            return;
        } else if (m < 1 || n < 1) {
            return;
        }
        cout << m << "  " << n << endl;
        findPath(m - 1, n, res);
        findPath(m, n - 1, res);
    }
};