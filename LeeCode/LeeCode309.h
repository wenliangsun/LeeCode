#include <climits>
#include <vector>
using namespace std;

/**
 * 题目309：最佳买卖股票的时机含冷冻期
 */
class LeeCode309 {
   public:
    /**
     * 思路：因为卖出后需要等一天才能交易，所以状态转移方程转换为：
     * dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i])
     * dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i]) //
     * 如果买入的话需要i-2天的状态
     */
    int maxProfit(vector<int>& prices) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        int dp_pre_0 = 0;  // 保存i-2状态
        for (int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);  // 注意这儿的变化
            dp_pre_0 = temp;
        }
        return dp_i_0;
    }
};