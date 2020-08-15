#include <bits/stdc++.h>

using namespace std;

/**
 * 有序数组的不同绝对值个数
 * 给定一个有序数组, 求它的元素的绝对值个数. 如数组[-3, -1, 0, 0, 2, 3, 5], 返回5.
 */

class Solution {
    public:
    /**
     * 思路1：开一个哈希表，遍历一次数组，把绝对值扔进哈希表，最后哈希表的大小就是不同绝对值个数
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    int countDistinctAbs(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto n : nums) hash.insert(abs(n));
        return hash.size();
    }

    /**
     * 双指针
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int countDistinctAbs2(vector<int>& nums) {
        if (!nums.size()) return 0;
        int n = nums.size();
        int l = 0, r = n - 1, res = 0;
        while (l < r) {
            if (l > 0 && nums[l] == nums[l - 1]) { // 去重
                l++;
                continue;
            }
            if (r < n - 1 && nums[r] == nums[r + 1]) { // 去重
                r--;
                continue;
            }
            if (nums[l] + nums[r] == 0) {
                res++;
                l++, r--;
            } else if (nums[l] + nums[r] > 0) {
                res++, r--;
            } else {
                res++, l++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-3, -3, -2, -2, -1, 0, 0, 2, 2, 3, 3, 3, 4, 4, 5 ,5};
    Solution s = Solution();
    int res = s.countDistinctAbs(nums);
    cout << res << endl;

    return 0;
}