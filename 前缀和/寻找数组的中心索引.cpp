#include <bits/stdc++.h>

using namespace std;

/**
 * 题目724：寻找数组的中心索引
 */
class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, pre = 0;
        for (auto n : nums) sum += n;
        for (int i = 0; i < nums.size(); i++) {
            if (pre == sum - pre - nums[i]) return i;
            pre += nums[i];
        }
        return -1;
    }

    /**
     * 前缀和
     */
    int pivotIndex(vector<int>& nums) {
        if (!nums.size()) return -1;
        vector<int> pre(nums.size() + 1), post(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        for (int i = nums.size() - 1; i >= 0; i--)
            post[i] = post[i + 1] + nums[i];
        for (int i = 0; i < nums.size(); i++) {
            if (pre[i] == post[i + 1]) return i;
        }
        return -1;
    }
};
