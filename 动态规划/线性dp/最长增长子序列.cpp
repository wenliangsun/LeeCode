#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个无序的整数数组，找到其中最长递增子序列的长度。
 */

class Solution {
   public:
    /**
     * 状态表示：dp[i] 表示以i为终点的上升子序列的集合  其中的值表示长度的最大值
     * 状态计算：dp[i] = dp[j]+1 当nums[j]<nums[i]的时候
     *
     * 时间复杂度：O(n^2)
     */
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) res = max(res, dp[i]);
        return res;
    }

    /**
     * 思路：二分查找法
     * 利用扑克牌的一种玩法，给定一把牌，我们只能把点数小的压在点数大的上面，(可用二分法找应该放置的堆)
     * 如果当前牌的点数较大且没有可以放置的堆，则新建一个堆，把这张牌放上去。
     * 如果当前牌有多个堆可供选择，则放置在最左侧的堆。
     * 最终牌的堆数就是最长递增子序列的长度。
     * 时间复杂度：O(nlogn)
     */
    int lengthOfLIS1(vector<int>& nums) {
        vector<int> dp(nums.size());
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r >> 1;
                if (dp[mid] >= nums[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            if (l == len) len++;
            dp[l] = nums[i];
        }
        return len;
    }
};