#include <bits/stdc++.h>

using namespace std;

/**
 * 题目209：长度最小的子数组
 */

class Solution {
   public:
    /**
     * 思路：双指针  滑动窗口
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX, sum = 0, l = 0;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum >= s) {
                res = min(res, r - l + 1);
                sum -= nums[l++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }

    /**
     * 前缀和 + 暴力枚举区间
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(1)
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        int res = INT_MAX;
        vector<int> sum(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (sum[j] - sum[i] + nums[i] >= s) res = min(res, j - i + 1);
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};