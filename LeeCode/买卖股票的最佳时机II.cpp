#include <climits>
#include <vector>
using namespace std;
/**
 * 题目122：买卖股票的最佳时机II
 */
class LeeCode122 {
   public:
    /**
     * 思路：可以无限次的交易，此时k这个状态就不太需要了，可以简化动态数组
     * 状态转移方程：
     * dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i])
     * dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i])
     *
     * 简化后的动态数组：
     * dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])
     * dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i])
     */
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
