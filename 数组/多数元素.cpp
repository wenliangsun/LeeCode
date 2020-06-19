#include <bits/stdc++.h>

using namespace std;

/**
 * 题目169：多数元素
 */

class Solution {
   public:
    /**
     * 排序
     * 时间复杂度：O(nlongn)
     */
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    /**
     * 摩尔投票
     * 时间复杂度: O(n)
     * 空间复杂度：O(1)
     *
     * 包含两个阶段，抵消阶段和计数阶段
     * 抵消阶段：两个不同投票进行对坑，并且同时抵消掉各一张票，如果两个投票相同，则累加可抵消的次数；
     * 计数阶段：在抵消阶段最后得到的抵消计数只要不为0，那这个候选人是有可能超过一半的票数的，为了验证，则需要遍历一次，统计票数，才可确定。
     */
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0], cnt = 1;
        // 抵消阶段
        for (int i = 1; i < n; i++) {
            if (res == nums[i])
                cnt++;
            else {
                cnt--;
                if (!cnt) res = nums[i], cnt = 1;
            }
        }
        cnt = 0;
        // 计数阶段
        for (auto n : nums)
            if (n == res) cnt++;
        return cnt > n / 2 ? res : -1;
    }
};