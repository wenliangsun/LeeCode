#include <bits/stdc++.h>

using namespace std;

/**
 * 题目128：最长连续序列
 */

class Solution {
   public:
    /**
     * 时间复杂度：O(n) 哈希表
     */
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int n : nums) st.insert(n);
        int res = 1;
        for (int num : st) {
            // 寻找最小的数作为起点
            if (st.find(num - 1) == st.end()) {
                int curnum = num;
                int curLen = 1;
                // 寻找序列
                while (st.find(curnum + 1) != st.end()) {
                    curLen++;
                    curnum++;
                }
                res = max(res, curLen);
            }
        }
        return res;
    }
    /**
     * 排序，时间复杂度O(nlogn)
     */
    int longestConsecutive1(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int res = 1, curLen = 1;
        // 遍历数组一次
        for (int i = 1; i < nums.size(); i++) {
            // 判断相连两个数是否相等
            if (nums[i - 1] != nums[i]) {
                // 判断是否是递增的，否则重置
                if (nums[i] == nums[i - 1] + 1) {
                    curLen++;
                } else {
                    res = max(res, curLen);
                    curLen = 1;
                }
            }
        }
        return max(res, curLen);
    }
};