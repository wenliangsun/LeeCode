#include <bits/stdc++.h>

using namespace std;

/**
 * 将一个数组按照中间某一位置分成两部分，使得两部分子数组的和的差值最小。
 */

class Solution {
   public:
    /**
     * 前缀和
     * 要使abs(前缀和 -（总和-前缀和)) = abs(2 * 前缀和 -总和)最小
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int absArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + nums[i - 1];
        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            res = min(res, abs(pre[i] * 2 - pre[n]));
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1, 0, 1, 7, 2, 4};
    int res = s.absArray(nums);
    cout << res << endl;
    return 0;
}