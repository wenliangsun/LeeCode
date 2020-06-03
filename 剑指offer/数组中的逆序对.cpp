#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    int res = 0;
    int reversePairs(vector<int>& nums) {
        vector<int> t(nums.size());
        helper(nums, 0, nums.size() - 1, t);
        return res;
    }

    /**
     * 归并排序的思路
     * 卡时间复杂度，参数使用引用！！！
     * 首先将数组划分为单个，然后进行二路归并比较，统计逆序对，并对统计过的区间进行排序。
     */
    void helper(vector<int>& nums, int l, int r, vector<int>& t) {
        if (l >= r) return;
        int mid = l + r >> 1;
        helper(nums, l, mid, t);
        helper(nums, mid + 1, r, t);
        int idx = r, idxl = mid, idxr = r;
        while (idxl >= l && r >= mid + 1) {
            if (nums[idxl] > nums[r]) {
                res += r - mid;  // 这儿统计逆序对
                t[idx--] = nums[idxl--];

            } else
                t[idx--] = nums[r--];
        }
        while (idxl >= l) t[idx--] = nums[idxl--];
        while (r >= mid + 1) t[idx--] = nums[r--];
        while (idxr >= l) {
            nums[idxr] = t[idxr];
            idxr--;
        }
    }
};