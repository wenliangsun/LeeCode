#include <vector>

using namespace std;

/**
 * 题目128：最长增长子序列
 */
class LeeCode300 {
   public:
    /**
     * 思路：动态规划
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    int lengthOfLIS(vector<int>& nums) {
        // 动态数组，表示当前位置之前的最长增长子序列
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // 当前最大增长子序列是之前比当前数字小的最长增长子序列+1，并取最大的那个
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        // 寻找最大的
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }

    /**
     * 思路：二分查找法
     * 利用扑克牌的一种玩法，给定一把牌，我们只能把点数小的压在点数大的上面，(可用二分法找应该放置的堆)
     * 如果当前牌的点数较大且没有可以放置的堆，则新建一个堆，把这张牌放上去。
     * 如果当前牌有多个堆可供选择，则放置在最左侧的堆。
     * 最终牌的堆数就是最长递增子序列的长度。
     * 时间复杂度O(nlongn)
     */
    int lengthOfLIS2(vector<int>& nums) {
        // 用来放堆顶元素
        vector<int> top(nums.size(), 0);
        // 堆数初始化0
        int piles = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 要处理的扑克牌
            int poker = nums[i];
            int left = 0;
            int right = piles;
            // 二分查找左边界
            while (left < right) {
                int mid = (left + right) / 2;
                if (top[mid] > poker) {
                    right = mid;
                } else if (top[mid] < poker) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            // 没有找到合适的堆，则新建一个堆
            if (left == piles) {
                piles++;
            }
            // 把这张牌放在堆顶
            top[left] = poker;
        }
        return piles;
    }
};
