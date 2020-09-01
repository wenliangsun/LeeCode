#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 直接对奇数位进行交换 会改变奇和奇数、偶数和偶数的相对位置
     * 时间复杂度：O(n)
     */
    vector<int> exchange(vector<int>& nums) {
        int idx = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            // 这个操作注意下
            while (nums[i] % 2 == 0 && i < idx) swap(nums[i], nums[idx--]);
        }
        return nums;
    }

    /**
     * 快慢指针
     * 奇数和偶数的相对位置不变
     */
    vector<int> exchange(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (nums[j] & 1) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return nums;
    }

    /**
     * 双指针 会改变奇和奇数、偶数和偶数的相对位置
     */
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] & 1) {
                l++;
                continue;
            }
            if (!(nums[r] & 1)) {
                r--;
                continue;
            }
            swap(nums[l++], nums[r--]);
        }
        return nums;
    }
    /**
     * 新开一个数组, 不会改变奇数和奇数 偶数和偶数的相对位置
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<int> exchange(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums)
            if (n & 1) res.push_back(n);
        for (auto n : nums)
            if (!(n & 1)) res.push_back(n);
        return res;
    }
};