#include <bits/stdc++.h>

using namespace std;

/**
 * 题目324：摆动排序II
 */

class Solution {
public:
    /**
     * 利用快排的思想找中位数
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int mid;
        if (n & 1) mid = n / 2 + 1;
        else mid = n / 2;
        int idx = -1, l = 0, r = n - 1;
        while (idx != mid) {
            idx = partition(nums, l, r);
            if (idx < mid) l = idx + 1;
            else if (idx > mid) r = idx - 1;
            else break;
        }
        vector<int> tmp(n);
        l = mid - 1, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (i & 1) tmp[i] = nums[r--];
            else tmp[i] = nums[l--];
        }
        nums = tmp;
    }

    int partition(vector<int>& nums, int l, int r) {
        int flag = l;
        int idx = l + 1;
        for (int i = idx; i <= r; i++) {
            if (nums[i] < nums[flag]) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[flag], nums[idx - 1]);
        return idx - 1;
    }

    /**
     * 先排序，然后从中间拆分，对两个数组进行穿插
     * 注意拆开之后需要对每个部分进行翻转，以避免两个数组中出现相同元素导致穿插之后无变化的情况
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(n)
     */
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // 排序
        vector<int> tmp(n);
        int mid;
        if (n & 1) mid = n / 2 + 1;
        else mid = n / 2;
        reverse(nums.begin(), nums.begin() + mid); // 翻转前部分
        reverse(nums.begin() + mid, nums.end()); // 翻转后部分
        int l = 0, r = mid;
        for (int i = 0; i < n; i++) { // 穿插合并
            if (i & 1) tmp[i] = nums[r++];
            else tmp[i] = nums[l++];
        }
        nums = tmp;
    }
};