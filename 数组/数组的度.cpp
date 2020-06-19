#include <bits/stdc++.h>

using namespace std;

/**
 * 题目697：数组的度
 */

class Solution {
   public:
   /**
    * 找最大度的最左侧位置和最右侧位置，然后求区间长度
    */
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left, right, hash; // 左侧位置，右侧位置，统计出现的次数
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            if (!left.count(n)) left[n] = i; // 第一次出现，记录左侧位置
            right[n] = i; // 更新右侧位置
            hash[n]++; // 统计出现的次数
        }

        int res = nums.size();
        int mx = 0;
        for (auto item : hash) mx = max(mx, item.second); // 寻找出现最多的次数
        for (auto item : hash) { 
            if (item.second == mx)
                res = min(res, right[item.first] - left[item.first] + 1);
        }
        return res;
    }
};