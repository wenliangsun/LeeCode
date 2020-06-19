#include <bits/stdc++.h>

using namespace std;

/**
 * 题目229：求众数II
 */

class Solution {
   public:
    /**
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto n : nums) hash[n]++;
        vector<int> res;
        for (auto item : hash)
            if (item.second > (nums.size() / 3)) res.push_back(item.first);
        return res;
    }

    /**
     * 摩尔投票法
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     * 抵消阶段：两个不同投票进行对坑，并且同时抵消掉各一张票，如果两个投票相同，则累加可抵消的次数
     * 计数阶段：在抵消阶段最后得到的抵消计数只要不为0，那这个候选人是有可能超过一半的票数的，为了验证，则需要遍历一次，统计票数，才可确定。
     */
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (!nums.size()) return res;
        int r1 = nums[0], cnt1 = 0;
        int r2 = nums[0], cnt2 = 0;
        // 抵消阶段
        for (auto n : nums) {
            if (n == r1) {
                cnt1++;
                continue;
            }
            if (n == r2) {
                cnt2++;
                continue;
            }
            if (!cnt1) {
                r1 = n;
                cnt1 = 1;
                continue;
            }
            if (!cnt2) {
                r2 = n;
                cnt2 = 1;
                continue;
            }
            cnt1--;
            cnt2--;
        }

        cnt1 = 0, cnt2 = 0;
        // 计数阶段
        for (auto n : nums) {
            if (n == r1)
                cnt1++;
            else if (n == r2)
                cnt2++;
        }
        if (cnt1 > nums.size() / 3) res.push_back(r1);
        if (cnt2 > nums.size() / 3) res.push_back(r2);
        return res;
    }
};