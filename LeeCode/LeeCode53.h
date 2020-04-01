#include <climits>
#include <vector>

using namespace std;

/**
 * 题目53：最大子序列
 */
class LeeCode53 {
   public:
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