#include <climits>
#include <vector>
using namespace std;

/**
 * 题目121：买卖股票的最佳时机
 */
class LeeCode121 {
   public:
    /**
     * 思路：动态规划
     * 利用状态机的技巧实际上就是动态数组，采用穷举的框架。
     * 我们具体到某一天穷举所有的状态，然后找出每个状态下的对应的选择，再根据对应的选择更新状态。
     * 状态：第一个是天数，第二个是可以交易的次数，第三个是当前的持有状态。
     * 选择：买入、卖出、无操作,(这些选择是有限制的)
     *  例子:dp[i][k][1]：表示现在是第i天，手上持有股票，最多可以交易k次
     * 我们要求的最终的答案是dp[n-1][k][0],即最后一天，手上没有股票，最多可以交易k次。
     * 状态转移：
     * (1)今天持有股票：有两种可能，前一天持有股票；前一天手上没有股票，今天买入了
     *      dp[i][k][1] = max(dp[i-1][k][1], dp[i][k-1][0]-prices[i])
     * (2)今天未持有股票：有两种可能，前一天未持有股票；前一天持有股票，但今天卖出了
     *      dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
     *
     * 考虑base case：
     * dp[-1][k][0] = 0 表示还没开始，利润为0
     * dp[-1][k][1] = INT_MIN 表示还没开始是不可能持有股票的
     * dp[i][0][0] = 0 表示不允许交易，这时利润为0
     * dp[i][0][1] = INT_MIN 表示不允许交易，是不可能持有股票的。
     *
     * 考虑到这儿k=1，k对状态转移已经没有影响了，可以简化动态数组
     * 考虑到只和前一个状态有关，可以进一步优化
     */
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2];
        for (int i = 0; i < prices.size(); i++) {
            if (i - 1 == -1) {
                // base case
                dp[i][0] = 0;  //还没开始的时候利润是0
                // 还没开始的时候持有股票不可能，用-prices[i]标记
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
    /*
     * 考虑到只和前一个状态有关，可以进一步优化
     * 空间复杂度：O(1)
     */
    int maxProfit2(vector<int>& prices) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};