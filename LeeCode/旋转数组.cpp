#include <bits/stdc++.h>

using namespace std;

/**
 * 题目189：旋转数组
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 */

class Solution {
   public:
    /**
     * 循环赋值  这个很牛皮！！！！
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int cnt = 0;
        for (int i = 0; cnt < nums.size(); i++) {
            int cur = i;
            int pre = nums[i];
            do {
                int next = (cur + k) % n;
                int tmp = nums[next];
                nums[next] = pre;
                pre = tmp;
                cur = next;
                cnt++;
            } while (i != cur);
        }
    }

    /**
     * 思路：三次翻转
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
    }

    /**
     * 使用辅助数组
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp(n);
        for (int i = 0; i < nums.size(); i++) {
            tmp[(i + k) % n] = nums[i];
        }
        nums = tmp;
    }

    /**
     * 思路：暴力 超时
     * 时间复杂度：O(kn)
     * 空间复杂度：O(1)
     */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        while (k--) {
            int tmp = nums[n - 1];
            for (int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }
            nums[0] = tmp;
        }
    }
};