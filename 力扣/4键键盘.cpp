
/**
 * 题目651：4键键盘
 */
class LeeCode651 {
   public:
    /**
     * 思路：动态规划
     * 最优按键序列一定只有两种情况
     * (1)要么一直按A：AAAA(N较小时)
     * (2)要么先按一些A，然后C-A C-C C-V C-V C-V ...：当N较大时 开头连按⼏个A ，
     *    然后C-A C-C组合再接若⼲C-V ，然后再C-A C-C 接着若⼲C-V ，循环下去
     * 选择：A C-A C-C C-V
     * 状态：剩余的按键数
     * 状态转移方程：
     * dp[i] = dp[i-1]+1
     * dp[i] = dp[j-2]*(i-j+1) j作为若干C-V的起点
     */
    int maxA(int N) {
        int dp[N + 1];
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            // 按键A
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j < i; j++) {
                // 全选 复制dp[j-2] 粘贴(i-j+1)次
                dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
            }
        }
        return dp[N];
    }
};