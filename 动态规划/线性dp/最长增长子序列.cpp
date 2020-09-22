#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个无序的整数数组，找到其中最长递增子序列的长度。
 *
 * 变形题目：
 * 牛客快手：搭积木
 * 顺丰笔试2：获得最多的金币
 */

class Solution {
   public:
    /**
     * 思路：二分查找法
     * 利用扑克牌的一种玩法，给定一把牌，我们只能把点数小的压在点数大的上面，(可用二分法找应该放置的堆)
     * 如果当前牌的点数较大且没有可以放置的堆，则新建一个堆，把这张牌放上去。
     * 如果当前牌有多个堆可供选择，则放置在最左侧的堆。
     * 最终牌的堆数就是最长递增子序列的长度。
     * 时间复杂度：O(nlogn)
     */
    int lengthOfLIS(vector<int>& nums) {
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
     * 输出最长增长子序列，输出任意一个
     * 反向寻找
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)
     */
    vector<int> lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n), pos(n);
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            pos[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pos[i] = j;
                }
            }
        }
        int len = 0, p = 0; // 找最大位置
        for (int i = 0; i < n; i++) {
            if (dp[i] > len) {
                len = dp[i];
                p = i;
            }
        }
        vector<int> res(len);
        int idx = len - 1; // 反向寻找
        while (pos[p] != p || idx >= 0) {
            res[idx--] = nums[p];
            p = pos[p];
        }
        return res;
    }

    /**
     * 输出字典序最小的最长增长子序列
     * 堆纸牌的方法，用一个数组记录每一个数字放在哪一堆上
     * 然后从后向前遍历数组去寻找每一堆上的数字
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(n)
     */
    vector<int> lengthOfLIS3(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n), pos(n);
        int len = 0;
        for (int i = 0; i < n; i ++) {
            int l = 0, r = len;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (dp[mid] >= nums[i]) r = mid;
                else l = mid + 1;
            }
            if (l == len) len++;
            dp[l] = nums[i];
            pos[i] = l; // 记录当前数字放在第几堆上
        }
        vector<int> res(len, INT_MAX); // 答案数组
        int idx = len - 1; // 答案数组的索引
        for (int i = n - 1; i >= 0; i--) {
            if (pos[i] == idx) { // 如果索引相同，则说明该数字是答案数组中当前位置的数字。
                res[idx] = min(res[idx], nums[i]);
                idx--;
            }
        }
        return res;
    }
};

int main() {
    // vector<int> nums = {2, 1, 5, 3, 6, 4, 8, 9, 7};
    vector<int> nums = {1, 2, 8, 6, 4};
    Solution s = Solution();
    vector<int> res = s.lengthOfLIS3(nums);
    for (auto n : res) cout << n << " ";
}