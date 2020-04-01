#include <climits>
#include <vector>
using namespace std;

/**
 * 题目123：买卖股票的最佳时机III
 */
class LeeCode123 {
   public:
    /**
     * 思路：k=2时，与之前不同的是，需要考虑k的所有状态
     * 状态转移方程：无法简化
     * dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
     * dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
     */
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int max_k = 2;
        int dp[prices.size()][max_k + 1][2];
        for (int i = 0; i < prices.size(); i++) {
            // base case
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
            for (int k = max_k; k > 0; k--) {
                // 处理base情况
                if (i - 1 == -1) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];  // 注意这儿的意义
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] =
                    max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][max_k][0];
    }

    /**
     * 思路：K=2时是可以枚举出来的
     * dp[i][2][0] = max(dp[i-1][2][0],dp[i-1][2][1]+prices[i])
     * dp[i][2][1] = max(dp[i-1][2][1],dp[i-1][1][0]-prices[i])
     * dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][1][1]+prices[i])
     * dp[i][1][1] = max(dp[i-1][1][1],-prices[i])
     */
    int maxProfit2(vector<int>& prices) {
        // k等于1时候的base case
        int dp_i_10 = 0;
        int dp_i_11 = INT_MIN;
        // k等于2时候的base case
        int dp_i_20 = 0;
        int dp_i_21 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            dp_i_20 = max(dp_i_20, dp_i_21 + prices[i]);
            dp_i_21 = max(dp_i_21, dp_i_10 - prices[i]);
            dp_i_10 = max(dp_i_10, dp_i_11 + prices[i]);
            dp_i_11 = max(dp_i_11, -prices[i]);
        }
        return dp_i_20;
    }
};