#include <bits/stdc++.h>

using namespace std;

/**
 * 找到所有数组中消失的数字
 */

class Solution {
   public:
    /**
     * 利用哈希表
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> hash;
        for (auto n : nums) hash.insert(n);
        for (int i = 1; i <= nums.size(); i++)
            if (!hash.count(i)) res.push_back(i);
        return res;
    }

    /**
     * 思路：把nums[nums[i]-1]位置的数字标记为相反数，说明nums[i]这个数字存在，
     * 最后遍历数组一次，如果某个位置的数字非负，则说明缺失当前位置对应的数字
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (auto n : nums) {
            n = abs(n);
            if (nums[n - 1] > 0) nums[n - 1] = -nums[n - 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};