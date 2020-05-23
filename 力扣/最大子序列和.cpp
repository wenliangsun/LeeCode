#include <climits>
#include <vector>

using namespace std;

/**
 * 题目53：最大子序列
 */
class LeeCode53 {
   public:
    /**
     * 动态规划
     *
     * dp[i] 表示以i为终点的所有字段，其中的值表示这些子段中的最大值
     * 分析可知，状态计算方程是： dp[i] = max(dp[i-1], 0) + nums[i]
     * 因为只与上一次的状态有关，可以进一步优化空间复杂度为O(1)
     */
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, last = 0;
        for (auto n : nums) {
            int t = max(last, 0) + n;
            res = max(res, t);
            last = t;
        }
        return res;
    }
    /**
     * 思路：累加和和当前值相比，如果累加和比当前和小，则抛弃之前的累加和，从当前值开始累加。
     * 在累加的过程中保存最大的和
     * 时间复杂度：O(n)
     */
    int maxSubArray(vector<int>& nums) {
        int cursum = 0;
        int maxsum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            cursum += nums[i];
            if (cursum < nums[i]) {
                cursum = nums[i];
            }
            if (maxsum < cursum) {
                maxsum = cursum;
            }
        }
        return maxsum;
    }
};