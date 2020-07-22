#include <bits/stdc++.h>

using namespace std;

/**
 * 数组中的第K大元素
 */

class Solution {
   public:
    /**
     * 直接快排
     * 时间复杂度：O(nlogn)
     */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()), reverse(nums.begin(), nums.end());
        return nums[k - 1];
    }
    /**
     * 使用堆
     * 时间复杂度：O(nlogk)
     * 空间复杂度：O(k)
     */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto n : nums) {
            q.push(n);
            if (q.size() > k) q.pop();
        }
        return q.top();
    }

    /**
     * 快排的思想
     * 时间复杂度：O(n)
     */
    int findKthLargest(vector<int>& nums, int k) {
        int idx = -1;
        int l = 0, r = nums.size() - 1;
        while (idx != k - 1) {
            int idx = partition(nums, l, r);
            if (idx < k - 1)
                l = idx + 1;
            else if (idx > k - 1)
                r = idx - 1;
            else
                break;
        }
        return nums[k - 1];
    }

    int partition(vector<int>& nums, int l, int r) {
        int flag = l;
        int idx = l + 1;
        for (int i = idx; i <= r; i++) {
            if (nums[i] > nums[flag]) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[flag], nums[idx - 1]);
        return idx - 1;
    }
};