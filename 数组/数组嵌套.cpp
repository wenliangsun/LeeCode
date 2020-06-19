#include <bits/stdc++.h>

using namespace std;

/**
 * 题目565：数组嵌套
 */

class Solution {
   public:
    /**
     * 思路：遍历每一个位置，然后以每一个位置为起始索引，开始构建集合S，将使用过的元素标记为-1。
     * 如果方位到-1，则直接跳出，原因是如果访问到之前一个循环中访问过的数，则说明也进入了之前的循环，没有必要再进行下去了。
     */
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        // 遍历每一个起点
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;  // 记录以当前位置为起始索引的集合中元素的数量
            int k = i;
            // 依照规则依次访问，遇到-1时跳出
            while (nums[k] != -1) {
                int t = k;
                k = nums[k];
                nums[t] = -1;
                cnt++;
            }
            res = max(res, cnt);  // 更新答案
        }
        return res;
    }
};