#include <bits/stdc++.h>

using namespace std;

/**
 * 题目179：最大数
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 和剑指上“把数组排成最小的数”类似
 */

class Solution {
   public:
    /**
     * 思路：关键在于如何比较两个数即定义一个比较规则
     */
    string largestNumber(vector<int>& nums) {
        string res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0) return "0";
        for (auto n : nums) {
            res += to_string(n);
        }
        return res;
    }

    static bool cmp(int a, int b) {
        string x1 = to_string(a) + to_string(b);
        string x2 = to_string(b) + to_string(a);
        return x1 > x2;
    }
};