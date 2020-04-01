#include <vector>

using namespace std;

/**
 * 题目213：打家窃舍II
 */
class LeeCode213 {
   public:
    /**
     * 思路：因为房子围成一个圈，所有数组中的收尾不能同时被抢，此时有三种情况：
     * (1) 首位都不抢
     * (2) 抢首不抢尾 区间[0,n-1]
     * (3) 抢尾不抢首 区间[1,n]
     * 我们取三种情况中的最大的，实际上是两种情况的最大的。
     */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        return max(robRange(nums, 0, n - 1), robRange(nums, 1, n));
    }

   private:
    int robRange(vector<int> nums, int begin, int end) {
        int dp_i_1 = 0;
        int dp_i_2 = 0;
        int dp_i = 0;
        for (int i = end - 1; i >= begin; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};