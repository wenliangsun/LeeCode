#include <climits>
#include <vector>
using namespace std;

/**
 * 题目188：买卖股票的最佳时机IV
 */
class LeeCode188 {
   public:
    /**
     * 思路：由于k次数不是无限也不是1和2，需要考虑k的状态，因此状态转移方程不能简化
     */
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        // 一次交易由买入和卖出构成，因此至少需要两天，所以有效的限制k应该不超过prices.size()/2,
        // 如果超过，就没有约束作用了，相当于k是无限制，可以用无限制的情况解决。
        if (k > prices.size() / 2) {
            return maxProfit_k_inf(prices);
        }
        int dp[prices.size()][k + 1][2];
        for (int i = 0; i < prices.size(); i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MAX;
            for (int t = k; t > 0; t--) {
                if (i - 1 == -1) {
                    dp[i][t][0] = 0;
                    dp[i][t][1] = -prices[i];
                    continue;
                }
                dp[i][t][0] = max(dp[i - 1][t][0], dp[i - 1][t][1] + prices[i]);
                dp[i][t][1] =
                    max(dp[i - 1][t][1], dp[i - 1][t - 1][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][k][0];
    }

   private:
    int maxProfit_k_inf(vector<int> prices) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};