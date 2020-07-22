#include <bits/stdc++.h>

using namespace std;

/**
 * 最长上升子序列
 */

class Solution {
   public:
    /**
     * 动态规划
     * 状态表示：dp[i]表示以i为结尾的子序列的最大长度
     * 状态计算：dp[i] = max(dp[i], dp[j] + 1) 当nums[j] < nums[i]时
     * 时间复杂度：O(n^2)
     */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }

    /**
     * 时间复杂度：O(nlogn)
     */
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<int> dp(n);
        int len = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = len;
            while (l < r) {
                int mid = l + r >> 1;
                if (dp[mid] >= nums[i]) r = mid;
                else l = mid + 1;
            }
            if (l ==len) len++;
            dp[l] = nums[i];
        }
        return len;
    }
};