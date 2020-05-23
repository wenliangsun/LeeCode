#include <climits>
#include <vector>
using namespace std;

/**
 * 题目198：打家窃舍
 */
class LeeCode198 {
   public:
    /**
     * 思路：动态规划 ：递归-->备忘录-->动态规划
     * 状态：房间号
     * 选择：偷或者不偷
     * base case：如果走过了所有房间，则偷到的金额为0.
     * 状态转移方程：
     * dp[i] = max(dp[i+1],nums[i]+dp[i+2])
     */
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 2, 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }

    /**
     * 进一步优化，将空间复杂度降为O(1)
     */
    int rob2(vector<int>& nums) {
        int dp_i_1 = 0;
        int dp_i_2 = 0;
        int dp_i = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};