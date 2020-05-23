#include <bits/stdc++.h>

using namespace std;

/**
 * 题目473：火柴拼正方形
 */

class Solution {
   public:
    /**
     * 状态压缩 dp
     */
    bool makesquare(vector<int>& nums) {}

    /**
     * 思路：深度优先搜索 + 剪枝  超时
     * 时间复杂度：O(4^N)
     * 空间复杂度：O(N)
     */
    bool makesquare(vector<int>& nums) {
        if (!nums.size()) return false;
        // 从大到小排序，是为了更快的剪枝
        sort(nums.begin(), nums.end()), reverse(nums.begin(), nums.end());
        int sum = 0;
        for (auto n : nums) sum += n;
        if (sum % 4) return false;

        vector<bool> vis(nums.size(), false);
        for (int i = 0; i < 4; i++) {
            if (!dfs2(nums, vis, 0, sum / 4)) return false;
        }
        return true;

        // return dfs(nums, 0, 0, 0, 0, 0, sum / 4);
    }

    // 剪枝更彻底
    bool dfs2(vector<int>& nums, vector<bool>& vis, int idx, int sum) {
        if (sum == 0) return true;
        if (idx == nums.size()) return false;
        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > sum || vis[i]) continue;
            vis[i] = true;
            if (dfs2(nums, vis, i + 1, sum - nums[i])) return true;
            vis[i] = false;
        }
        return false;
    }

    bool dfs(vector<int> nums, int idx, int a, int b, int c, int d, int sum) {
        if (idx == nums.size()) {
            if (a == sum && b == sum && c == sum && d == sum)
                return true;
            else
                return false;
        }
        if (nums[idx] > sum) return false;
        if (a > sum || b > sum || c > sum || d > sum) return false;
        return dfs(nums, idx + 1, a + nums[idx], b, c, d, sum) ||
               dfs(nums, idx + 1, a, b + nums[idx], c, d, sum) ||
               dfs(nums, idx + 1, a, b, c + nums[idx], d, sum) ||
               dfs(nums, idx + 1, a, b, c, d + nums[idx], sum);
    }
};

int main() {
    vector<int> nums = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
    Solution s = Solution();
    bool res = s.makesquare(nums);
    cout << res << endl;
}