#include <climits>
#include <vector>

using namespace std;

/**
 * 题目714：买卖股票的最佳时机含手续费
 */
class LeeCode714 {
   public:
    /**
     * 思路：把手续费算进买入的股票价格中去，即从利润中减去
     * 状态转移方程：
     * dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])
     * dp[i][1] = max(dp[i-1][1],dp[i-1][0]-fee-prices[i])
     */
    int maxProfit(vector<int>& prices, int fee) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - fee - prices[i]);
        }
        return dp_i_0;
    }
};